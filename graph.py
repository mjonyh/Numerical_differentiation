#A program to plot(cross-section) the derivative of a guassian equation                                                                  #
#   FILE: diff.c																				                                         #
#   DESCRIPTION:																														 #
#   This is a code for surface graph .The code that is built for showing graph of differentiating gaussian surface equation of e^-       #
#  (x^2+y^2) .Calculation of this code is in c .For running this code please read "How_to".  											 #
#   Numerical_differentiation - Python version 2.7.6 code.                                                                               #
#   AUTHOR: Shafayet Islam , Sakibul Islam & Md.Enamul Haque                                                                             #
#   Uploaded in : 01/26/16                                                                                                               #
##########################################################################################################################################



#   importing Libraries... ... ... ... ... ... 
from mpl_toolkits.mplot3d import axes3d
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt
import numpy as np
import ctypes


size=200
p=4.0/size

#Data Generate for X and Y coordinate ... ... ... ...

fig = plt.figure()
ax = fig.gca(projection='3d')
X = np.arange(-2, 2.00, p)

Y = np.arange(-2, 2.00, p)
X, Y = np.meshgrid(X, Y)

# importing data for Z coordinate using ctypes... .... .... .... ... ...

libdiff = ctypes.cdll.LoadLibrary('./diff.so')
diff = libdiff.diff
diff.argtypes = ()
diff.restype = ctypes.POINTER(ctypes.c_double)
result = diff()

#Converting one dimentinal array to 2D array .... ... ... ... ... 

Z=[]
k=0
for i in range(size):
	Z.append([]);
	for j in range(size):
		Z[i].append(result[k]);
		k=k+1;


#ploting... .... .... ...
#X, Y, Z = axes3d.get_test_data(0.05)
ax.plot_surface(X, Y, Z, rstride=8, cstride=8, alpha=0.5, linewidth=0.2)
#ax = fig.gca(projection='3d')
z_color_bar = cset = ax.contourf(X, Y, Z, zdir='z', offset=-0.04, cmap=cm.coolwarm)
cset = ax.contourf(X, Y, Z, zdir='x', offset=-2, cmap=cm.coolwarm)
cset = ax.contourf(X, Y, Z, zdir='y', offset=2, cmap=cm.coolwarm)

ax.set_xlabel('X')
#ax.set_xlim(-2, 2)
ax.set_ylabel('Y')
#ax.set_ylim(-2, 2)
ax.set_zlabel('Z')
#ax.set_zlim(-0.0000000000001, 0.000000000000001)

#ax.zaxis.set_major_locator(LinearLocator(10))
#ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(z_color_bar, shrink=0.5, aspect=5)

plt.show()
