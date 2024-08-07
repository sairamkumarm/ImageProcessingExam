import cv2
import numpy as np
image = cv2.imread('PHOTO.png')
height, width = image.shape[:2]
angle = 45
scalex_y = 1.5
txy = 50
cv2.imshow("Original", image)
rotmat = cv2.getRotationMatrix2D((width//2,height//2),angle,1)
cv2.imshow("Rotated",cv2.warpAffine(image, rotmat,(width,height)))
cv2.imshow("Scaled",cv2.resize(image,fx=scalex_y, fy=scalex_y,dsize=None))
tmat = np.float32([[1,0,txy],[0,1,txy]])
cv2.imshow("Translated",cv2.warpAffine(image, tmat,(width,height)))
cv2.waitKey(0)
cv2.destroyAllWindows()