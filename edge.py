import cv2
import numpy as np
image = cv2.imread('PHOTO.png')
height, width = image.shape[:2];cv2.imshow("Original", image)
canny = cv2.Canny(image,200,100)
cv2.imshow("Canny",canny)
cv2.imshow("Gaussian",cv2.GaussianBlur(image,(3,3),3))
lapblur = cv2.Laplacian(image,cv2.CV_64F)
lapblur = np.uint8(np.absolute(lapblur))
cv2.imshow("Laplacian",lapblur)
cv2.waitKey(0)
cv2.destroyAllWindows()