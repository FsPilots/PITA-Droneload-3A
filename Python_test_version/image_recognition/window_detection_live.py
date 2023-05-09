import cv2
import numpy as np
import pyautogui
import av
SCREEN_SIZE = (1920, 1080)  # Dimensions de l'écran
FPS = 30  # Nombre d'images par seconde de la vidéo

# Initialisez l'objet de capture vidéo
fourcc = cv2.VideoWriter_fourcc(*"XVID")
out = cv2.VideoWriter("output.avi", fourcc, FPS, SCREEN_SIZE)

while True:
    # Capturez l'écran de l'ordinateur
    screenshot = pyautogui.screenshot()

    # Convertissez l'image en tableau numpy pour pouvoir la manipuler avec OpenCV
    frame = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

    # Convert the image to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian blur to the image
    # ksize == 25 intensifie le flou et permet de reduire le bruit de l'image thresholded
    blurred =  cv2.GaussianBlur(gray,(25, 25), 0)
    #cv2.imshow("Webcam blurred", blurred)

    # Create an adaptive binary thresholded image
    # blocksize == 15 permet de reduire la sensibilité du threshold pour garder uniquement les contours les plus importants
    adaptthresh = cv2.adaptiveThreshold(blurred, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 15, 2)
    #cv2.imshow("Webcam thresh", adaptthresh)

    # Find contours in the thresholded image
    contours, _ = cv2.findContours(adaptthresh, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    # Iterate over the contours and draw a rectangle around any contour that is a rectangle
    for contour in contours:
        # Get the bounding rectangle of the contour
        x, y, w, h = cv2.boundingRect(contour) 
        aspectRatio = float(w)/h
        center_x, center_y = int(x + w/2), int(y + h/2)
        
        # Check if the aspect ratio of the contour is close to 1, indicating it is a rectangle
        if 0.95 <= aspectRatio <= 1.05:
            if h>50:
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0,0,0), 2)
                cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)
                cv2.putText(frame, "x: {} y: {}".format(center_x, center_y), (center_x+10, center_y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (300, 0, 255), 2, cv2.LINE_AA)


    # Écrivez le cadre sur la sortie vidéo
    out.write(frame)

    #WaitKey Exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Initialisez l'objet de capture vidéo pour la lecture
cap = cv2.VideoCapture("output.avi")

# Affichez la vidéo en continu
while True:
    ret, frame = cap.read()

    if not ret:
        break

    cv2.imshow("Screen Capture", frame)

    # Attendez 1 milliseconde et vérifiez si l'utilisateur appuie sur la touche 'q' pour quitter
    if cv2.waitKey(1) == ord('q'):
        break

# Fermez la fenêtre d'affichage et l'objet de capture vidéo
cap.release()
cv2.destroyAllWindows()
