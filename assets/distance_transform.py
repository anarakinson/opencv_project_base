import cv2 
import numpy as np 
  
# Load the input image and make it grayscale. 
image = cv2.imread('j4.jpg') 
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) 
  
# Create a binary image by throttling the image. 
ret, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY) 
  
#Determine the distance transform. 
dist = cv2.distanceTransform(thresh, cv2.DIST_L2, 3) 
  
# Make the distance transform normal. 
dist_output = cv2.normalize(dist, None, 0., 2.5, cv2.NORM_MINMAX) 
  
# Display the distance transform 
cv2.imshow('Distance Transform', dist_output) 
cv2.waitKey(0) 

# Python program to compute and visualize the 
# histogram of Blue channel of image 
# %matplotlib inline 
  
# importing libraries 
import cv2 
import numpy as np 
from matplotlib import pyplot as plt 

# reading the input image 
img = cv2.imread('red-ball.jpg') 

# computing the histogram of the blue channel of the image 
histb = cv2.calcHist([img],[0],None,[256],[0,256]) 
histg = cv2.calcHist([img],[1],None,[256],[0,256]) 
histr = cv2.calcHist([img],[2],None,[256],[0,256]) 

# plot the above computed histogram 
plt.plot(histb, color='b')  
plt.plot(histg, color='g')  
plt.plot(histr, color='r') 
plt.title('Image Histogram For Blue Channel GFG') 
plt.show()
