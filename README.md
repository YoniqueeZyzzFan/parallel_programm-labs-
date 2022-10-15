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
| Size       | Number of threads        | Time |
| ------------- |:------------------:| -----:|
| 100    | 2   | 8.98 |
| 200     | 2 |   57.11 |
| 300 | 2    |   193.331 |
| 400 | 2    |   456.33 |
| 800 | 2    |   3680.65 |
| 100 | 3   |   6.51 |
| 200 | 3    |   40.0835 |
| 300 | 3    |   132.482|
| 400 | 3    |   315.23 |
| 800 | 3    |   2565.58 |
| 100 | 4    |   5.93 |
| 200 | 4    |   32.6166 |
| 300 | 4    |   99.2775 |
| 400 | 4    |   234.568 |
| 800 | 4    |   1916.37 |
| 100 | 8   |   8.04 |
| 200 | 8   |   33.28 |
| 300 | 8   |   105.63 |
| 400 | 8   |   252.591 |
| 800 | 8   |   2189.79 |

Testing on Intel Core i5-3470 with 4 threads. If you increase the number of threads more than 4, there will be no improvement, the time will only grow.
###### Lab2: Compare parallel execution and standard execution
