import cv2
image = cv2.imread("PHOTO.png")
grey = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
_,threshold = cv2.threshold(grey,0,255,cv2.THRESH_BINARY_INV,cv2.THRESH_OTSU)
contours,_=cv2.findContours(threshold,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(image,contours,-1,(0,255,0),2)
cv2.imshow("Contours",image)
cv2.waitKey(0)
cv2.destroyAllWindows()
