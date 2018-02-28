import matplotlib.pyplot as plt
import numpy as np
from numpy import genfromtxt

print("Plotting in Python using matplotlib...")

my_data = genfromtxt('output.txt', delimiter=',')
print(my_data.shape);

x_orig = [10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000]
x = np.arange(1000)
y = x**2

m, b = np.polyfit(x, y, 1)

plt.scatter(x_orig,my_data, color='r')
plt.plot(x, x**2, '-')
plt.title('Insertion Sort')

plt.show()