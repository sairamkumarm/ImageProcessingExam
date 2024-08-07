import cv2
image = cv2.imread('PHOTO.png')
grey = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
facefinder = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
faces = facefinder.detectMultiScale(grey,1.1,6,minSize=(50,50))
for (x,y,w,h) in faces:
	cv2.rectangle(image,(x,y),(x+w,y+h),(0,255,0),2)
cv2.imshow("faces",image)
cv2.waitKey(0)
cv2.destroyAllWindows()