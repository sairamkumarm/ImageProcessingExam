import cv2
image = cv2.imread('PHOTO.png')
height, width = image.shape[:2]
q1=image[:height//2,:width//2]
q2=image[height//2:height,:width//2]
q3=image[:height//2,width//2:width]
q4=image[height//2:height,width//2:width]
cv2.imshow("q1",q1)
cv2.imshow("q2",q2)
cv2.imshow("q3",q3)
cv2.imshow("q4",q4)
cv2.waitKey(0)
cv2.destroyAllWindows()