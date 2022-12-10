[![Typing SVG](https://readme-typing-svg.herokuapp.com?color=%2336BCF7&lines=Lab+4)](https://git.io/typing-svg)
About lab
------------
Info for files:
-  mainGpu.h              - main
-  matMulGPU.cu  -  multiplication

### Time with CUDA (block size = 10)
Matrix's size is: 100
Def meth's time: 0.06 ms
_______________________________
Matrix's size is: 200
Def meth's time: 0.17 ms
_______________________________
Matrix's size is: 300
Def meth's time: 0.40 ms
_______________________________
Matrix's size is: 400
Def meth's time: 0.95 ms
_______________________________
Matrix's size is: 800
Def meth's time: 9.33 ms
_______________________________
![](cuda.png)

#### Size - number of columns (n.columns = n.rows)
#### Comparing number of threads:
|Block size        | Time(size 100) | Time(size 200) | Time(size 300) | Time(size 400) | Time(size 800) |
|------------------:| -----:| -----:| -----:| -----:| -----:|
| 5   |   0.06 ms | 0.19 ms | 0.65 ms | 1.52 ms | 15.79 ms |
| 10   |   0.06 ms | 0.17 ms | 0.40 ms | 0.95 ms |9.33 ms|
| 25   | 0.08 ms | 0.14 ms | 0.33 ms | 0.74 ms | 6.67 ms |

Testing on gtx 1060.
