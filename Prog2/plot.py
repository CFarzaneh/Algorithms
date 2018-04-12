import matplotlib.pyplot as plt
from scipy.interpolate import spline
import numpy as np
from numpy import genfromtxt
import pandas as pd

probes = ["linear","quadratic","double","cam"]

# for i in probes:
# 	nameOfFile = i + "_probe_output.txt"
# 	print(nameOfFile)

# 	df = pd.read_csv(nameOfFile)
# 	df.plot(x='x',y='y')

# 	plt.title(i + ' Probe')
# 	plt.ylabel('Number of Probes')
# 	plt.xlabel('Load Factor')

# 	plt.show()

i = "double"
nameOfFile = i + "_probe_output.txt"
print(nameOfFile)

df = pd.read_csv(nameOfFile)
dfPy = df.values
dfPy = dfPy[-1]
cuttoff = dfPy[1]
df = df[:-1]
print(df)
print(cuttoff)

df.plot(kind='scatter',x='x',y='y')

axes = plt.gca()
axes.set_ylim([0,100])

plt.title(i + ' Probe')
plt.ylabel('Number of Probes')
plt.xlabel('Load Factor (Cuttoff at ' + str(cuttoff) + ')')

def graph(formula):  
    x = np.arange(0.5, 0.999, 0.01)
    y = eval(formula)
    plt.plot(x, y, color='green')  

graph('1/(1-x)')

plt.show()