import numpy as np
import operator
import re

matrix1 = []
matrix2 = []
data = []
changer = True
data = np.genfromtxt('C:\\Users\\student\\source\\repos\\g\\g\\Data.txt', delimiter=" ", dtype=int)
size = 400
t1 = []
t2 = []
for k in data:
    if changer:
        t1.append(k)
    else:
        t2.append(k)
    changer = operator.not_(changer)
    if (len(t1) == size):
        matrix1.append(t1.copy())
        t1.clear()
    if (len(t2) == size):
        matrix2.append(t2.copy())
        t2.clear()
test = np.matrix(matrix1, dtype=int)
test2 = np.matrix(matrix2, dtype=int)
pl = np.dot(test, test2)

data2 = np.genfromtxt('C:\\Users\\student\\source\\repos\\g\\g\\Matrix.txt', delimiter=" ", dtype=int)
t3 = []
m = []
for k in data2:
    t3.append(k)
    if (len(t3) == size):
        m.append(t3.copy())
        t3.clear()

pl2 = np.matrix(m, dtype=int)

pl = np.array(pl)
pl2 = np.array(pl2)
if (np.array_equal(pl, pl2)):
    print("It's alright")
else:
    print("Fatal error, u r d")
