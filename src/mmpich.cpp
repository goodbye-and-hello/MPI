#include <stdlib.h>
#include "mpi.h"
using namespace std;

// matrix WIDTH & AREA
#define L 64
#define A L*L

int main(int argc, char **argv) {
	int rank;
	int size;
	int div, rem;
	// matrix index
	int begin, end;
	/*
	각 rank가 계산할 영역의 row와 column의 시작과 끝 index
	*/
	int row_b, row_e, col_b, col_e;
	MPI_Status status;
	// m x n = t 연산을 수행할 matrix
	int m[L][L];
	int n[L][L];
	int t[L][L];
	// matrix initialize
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			m[i][j] = 1;
			n[i][j] = 1;
			t[i][j] = 0;
		}
	}
	double b, e;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	/*----------------master----------------*/
	if (rank == 0) {
		/*
		div = matrix 전체 index를 rank의 수로 나누어 저장
		rem = matrix 전체 index를 rank의 수로 나누었을 때 각
		rank에서 추가로 연산을 수행해야 할 나머지 부분
		*/
		div = A / size;
		rem = A % size;
		// matrix multiplication을 수행할 index의 begin과 end
		begin = 0;
		end = div - 1;

		// matrix multiplication을 수행할 index row, column 각각의 begin과 end
		row_b = begin / L;
		row_e = end / L;
		col_b = begin % L;
		col_e = end % L;
		b = MPI_Wtime();
		for (int i = 1; i < size; i++) {
			begin = end + 1;
			// 각 index를 rank의 개수로 나누어 주었을때 나머지가 발생한 경우 연산할 부분을 추가해줌
			end = (i == (size - 1)) ? end + rem + div : end + div;
			// 연산을 수행할 index의 범위를 하위 rank에 전송
			MPI_Send(&end, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			MPI_Send(&begin, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
		// rank 0 에서 연산 수행
		for (int i = row_b; i <= row_e; i++) {
			for (int j = ((i == row_b) ? col_b : 0); j <= ((i == row_e) ? col_e : L - 1); j++) {
				for (int k = 0; k < L; k++)
					t[i][j] += m[i][k] * n[k][j];
			}
		}

		// 각 rank에서 연산 결과를 받아옴
		for (int i = 1; i < size; i++) {
			MPI_Recv(&end, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
			MPI_Recv(&begin, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
			row_b = begin / L;
			col_b = begin % L;
			MPI_Recv(&t[row_b][col_b], end - begin + 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
		}
		e = MPI_Wtime();
		printf("number of ranks : %d \n", size);
		printf("%d x %d matrix > %lf [ms]\n", L, L, (e - b) * 1000);
		// test를 위한 code
		// printf("(0,0) %d, (%d, %d) %d\n", t[0][0], L - 1, L - 1, t[L-1][L-1]);
	}
	/*----------------slave----------------*/
	else {
		// master rank (rank 0)에서 matrix multiplication을 수행할 index의 범위를 받아옴
		MPI_Recv(&end, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&begin, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		// matrix multiplication을 수행할 index row, column 각각의 begin과 end
		row_b = begin / L;
		row_e = end / L;
		col_b = begin % L;
		col_e = end % L;

		// matrix multiplication
		for (int i = row_b; i <= row_e; i++) {
			for (int j = ((i == row_b) ? col_b : 0); j <= ((i == row_e) ? col_e : L - 1); j++) {
				for (int k = 0; k < L; k++)
					t[i][j] += m[i][k] * n[k][j];
			}
		}

		// matrix multiplication의 결과를 rank 0로 전달
		MPI_Send(&end, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&begin, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&t[row_b][col_e], end - begin, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
