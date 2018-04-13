import matplotlib.pyplot as plt
from scipy.interpolate import spline
import numpy as np
from numpy import genfromtxt
import pandas as pd

probes = ["linear","quadratic","double","cam"]

for i in probes:
	nameOfFile = i + "_probe_output.txt"
	print(nameOfFile)

	df = pd.read_csv(nameOfFile)
	dfPy = df.values

	x = np.arange(0.5, 1.01, 0.01)

	arr = []
	for f in range(0,x.shape[0]-1):
		sum = 0
		j = 0
		low = x[f]
		high = x[f+1]
		for k in range(0,dfPy.shape[0]):
			num = dfPy[k, 0]
			if num < high and num >= low:
				sum += dfPy[k, 1]
				j+=1
		avg = sum/j
		arr.append(avg)

	x=np.delete(x,-1)
	arr = np.asarray(arr)
	final = np.column_stack((x, arr))

	df = pd.DataFrame(data=final,columns=['a','Mine'])
	df.plot(x='a',y='Mine')

	axes = plt.gca()
	axes.set_ylim([0,100])
	axes.set_xlim([0.5,1])

	plt.title(i + ' Probe')
	plt.ylabel('Number of Probes')
	plt.xlabel('Load Factor')

	def graph(formula):  
	    x = np.arange(0.5, 0.999, 0.01)
	    y = eval(formula)
	    plt.plot(x, y, color='green', label='1/(1-x) Function')  

	graph('1/(1-x)')

	plt.legend(loc='best')
	plt.show()