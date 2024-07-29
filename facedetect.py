import cv2
facecascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
img = cv2.imread('PHOTO.png')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
faces = facecascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=6, minSize=(30,30))
for (x,y,w,h) in faces:
	cv2.rectangle(img, (x,y), (w+x,h+y), (0,225,0),2)

cv2.imshow("a", img)
cv2.waitKey(0)
cv2.destroyAllWindows()