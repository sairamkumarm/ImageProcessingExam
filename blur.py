import cv2
image = cv2.imread('PHOTO.png')
cv2.imshow("ORG",image)
cv2.imshow("Gaussian",cv2.GaussianBlur(image,(15,15),2))
cv2.imshow("Median",cv2.medianBlur(image,15))
cv2.imshow("Bilateral",cv2.bilateralFilter(image,15,75,75))
cv2.waitKey(0)
cv2.destroyAllWindows()