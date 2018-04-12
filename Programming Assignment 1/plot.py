import matplotlib.pyplot as plt
from scipy.interpolate import spline
import numpy as np
from numpy import genfromtxt

print("Plotting in Python using matplotlib...")

my_data = genfromtxt('output.txt', delimiter=',')
print(my_data);

x_orig = np.array([10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000])

plt.scatter(x_orig, my_data, color='r')

xnew = np.linspace(x_orig.min(),x_orig.max(),100)
power_smooth = spline(x_orig,my_data,xnew)

plt.plot(xnew, power_smooth)

plt.title('Insertion Sort')
plt.ylabel('Time in seconds')
plt.xlabel('Input size')

plt.show()