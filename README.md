[![Typing SVG](https://readme-typing-svg.herokuapp.com?color=%2336BCF7&lines=Lab+2)](https://git.io/typing-svg)
About lab
------------
Info for files:
-  Data.txt              - all values from two matrices
-  Time without.txt           - time for multiply matrices without parallel
-  Time with omp.txt    - time for multiply with parallel
-  main.cpp             - obviously
-  main.py              - correctness check
- comparing_threads.txt - create file below 
- NumberOfThreadsDependence   - operating time with different number of threads

##### About main.cpp: I represented matrices as arrays and used a formula to get the elements from the desired rows or columns (see code).
### Time without
Matrix's size is: 100
Def meth's time: 14.3727
_______________________________
Matrix's size is: 200
Def meth's time: 113.989
_______________________________
Matrix's size is: 300
Def meth's time: 387.619
_______________________________
Matrix's size is: 400
Def meth's time: 889.16
_______________________________
Matrix's size is: 800
Def meth's time: 7246.96
_______________________________
![](without_omp.png)

### Time with omp
Matrix's size is: 100
Def meth's time: 26.6091
_______________________________
Matrix's size is: 200
Def meth's time: 28.5437
_______________________________
Matrix's size is: 300
Def meth's time: 96.3207
_______________________________
Matrix's size is: 400
Def meth's time: 224.973
_______________________________
Matrix's size is: 800
Def meth's time: 1823.44
_______________________________
![](without_omp.png)

#### As we can see - the execution time with parallel calculations is much lower than standard execution.
#### Comparing number of threads:
|Number of threads        | Time(size 100) | Time(size 200) | Time(size 300) | Time(size 400) | Time(size 800) |
|------------------:| -----:| -----:| -----:| -----:| -----:|
| 2   | 8.98 | 57.11 | 193.33 | 456.33 | 3680.65 |
| 3   |   6.51 | 40.08 | 132.48 | 315.23 | 2565.58|
| 4   |   5.93 | 32.61 | 99.27 | 234.56 | 1916.37 |
|8   |   8.04 | 33.28 | 105.63 | 252.59 | 2189.79|

Testing on Intel Core i5-3470 with 4 threads. If you increase the number of threads more than 4, there will be no improvement, the time will only grow.
###### Lab2: Compare parallel execution and standard execution
