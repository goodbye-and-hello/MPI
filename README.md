# MPICH2  Clustering Project
Since : 2018.06.05 ~ 2018.06.12

Author : [@ssibongee](https://github.com/ssibongee)


We construct a clustering environment using four PCs (MPI) and compare the performance

difference according to degree of parallelism by matrix multiplication.



### 1. System Environment

![sysenv](https://github.com/ssibongee/MPI/blob/master/img/sysenv.png?raw=true)

Using 4 PCs in Computer Labs Yonsei Univ WJ





### 2. Testing

![test_c](https://github.com/ssibongee/MPI/blob/master/img/test_c.png?raw=true)

test code to verify that our system environment is correctly built

![](https://github.com/ssibongee/MPI/blob/master/img/test_r.png?raw=true)

it can be confirmed that it works correctly.



### 3. Experiments



#### Experiment 1

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  1   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex1_1](https://github.com/ssibongee/MPI/blob/master/img/ex1_1.png?raw=true)

![ex1_2](https://github.com/ssibongee/MPI/blob/master/img/ex1_2.png?raw=true)





#### **Experiment 2**

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  2   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex2_1](https://github.com/ssibongee/MPI/blob/master/img/ex2_1.png?raw=true)

![ex2_2](https://github.com/ssibongee/MPI/blob/master/img/ex2_2.png?raw=true)





#### **Experiment 3**

**experiment  environment**

|  PC  |  RANK  | MATRIX WIDTH |
| :--: | :----: | :----------: |
|  4   | 1 ~ 10 |  1024x1024   |





**experiment results**

![ex3_1](https://github.com/ssibongee/MPI/blob/master/img/ex3_1.png?raw=true)

![ex3_2](https://github.com/ssibongee/MPI/blob/master/img/ex3_2.png?raw=true)





#### **Experiment 4**

**experiment  environment**

|  PC  | RANK |   MATRIX WIDTH    |
| :--: | :--: | :---------------: |
|  4   |  4   | 64x64 ~ 1024x1024 |





**experiment results**

![ex4_1](https://github.com/ssibongee/MPI/blob/master/img/ex4_1.png?raw=true)





### 4. Efficiency Analysis



**Experiment 1**

![eff_1](https://github.com/ssibongee/MPI/blob/master/img/eff_1.PNG?raw=true)





**Experiment 2**

![eff_2](https://github.com/ssibongee/MPI/blob/master/img/eff_2.PNG?raw=true)





**Experiment 3**

![eff_3](https://github.com/ssibongee/MPI/blob/master/img/eff_3.PNG?raw=true)





**Experiment 4**

![eff_4](https://github.com/ssibongee/MPI/blob/master/img/eff_4.PNG?raw=true)





**Experiments  Compare 1 to 3**

![eff_cmp](https://github.com/ssibongee/MPI/blob/master/img/eff_cmp.PNG?raw=true)
