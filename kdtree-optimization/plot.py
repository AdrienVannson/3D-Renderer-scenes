import numpy as np
from matplotlib import pyplot as plt

xs, ys = [], []

f = open('output', 'r')
for l in f:
    xCenter, yCenter, zCenter, xSize, ySize, zSize, prob = [float(s) for s in l.split()]

    s = 2 * (xSize*ySize + ySize*zSize + zSize*xSize)

    xs.append(s)
    ys.append(prob)

plt.figure()
plt.scatter(xs, ys)
plt.show()
