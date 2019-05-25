# MPICH2  Clustering Project
Since : 2018.06.05 ~ 2018.06.12

Author : @ssibongee



We construct a clustering environment using four PCs (MPI) and compare the performance

difference according to degree of parallelism by matrix multiplication.



### 1. System Environment

![sysenv](C:\Users\시원\Desktop\git\MPI\img\sysenv.png)

Using 4 PCs in Computer Labs Yonsei Univ WJ





### 2. Testing

![test_c](C:\Users\시원\Desktop\git\MPI\img\test_c.png)

test code to verify that our system environment is correctly built

![](C:\Users\시원\Desktop\git\MPI\img\test_r.png)

it can be confirmed that it works correctly.



### 3. Experiments



#### Experiment 1

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  1   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex1_1](C:\Users\시원\Desktop\git\MPI\img\ex1_1.png)

![ex1_2](C:\Users\시원\Desktop\git\MPI\img\ex1_2.png)





#### **Experiment 2**

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  2   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex2_1](C:\Users\시원\Desktop\git\MPI\img\ex2_1.png)

![ex2_2](C:\Users\시원\Desktop\git\MPI\img\ex2_2.png)





#### **Experiment 3**

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  4   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex3_1](C:\Users\시원\Desktop\git\MPI\img\ex3_1.png)

![ex3_2](C:\Users\시원\Desktop\git\MPI\img\ex3_2.png)





#### **Experiment 4**

**experiment  environment**

|  PC  | RANK |   MATRIX WIDTH    |
| :--: | :--: | :---------------: |
|  4   |  4   | 64x64 ~ 1024x1024 |





**experiment results**

![ex4_1](C:\Users\시원\Desktop\git\MPI\img\ex4_1.png)





### 4. Efficiency Analysis



**Experiment 1**

![eff_1](C:\Users\시원\Desktop\git\MPI\img\eff_1.PNG)





**Experiment 2**

![eff_2](C:\Users\시원\Desktop\git\MPI\img\eff_2.PNG)





**Experiment 3**

![eff_3](C:\Users\시원\Desktop\git\MPI\img\eff_3.PNG)





**Experiment 4**

![eff_4](C:\Users\시원\Desktop\git\MPI\img\eff_4.PNG)





**Experiments  Compare 1 to 3**

![eff_cmp](C:\Users\시원\Desktop\git\MPI\img\eff_cmp.PNG)

