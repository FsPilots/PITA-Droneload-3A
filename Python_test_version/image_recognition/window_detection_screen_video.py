import cv2
import numpy as np
import pyautogui
import keyboard

SCREEN_SIZE = (1920, 1080)  # Dimensions de l'écran
FPS = 30 # Nombre d'images par seconde de la vidéoq

# Initialisez l'objet de capture vidéo
fourcc = cv2.VideoWriter_fourcc(*"XVID")
out = cv2.VideoWriter("Python_test_version/Test_video/output.avi", fourcc, FPS, SCREEN_SIZE)
edgesout = cv2.VideoWriter("Python_test_version/Test_video/edgesoutput.avi", fourcc, FPS, SCREEN_SIZE)
maskout = cv2.VideoWriter("Python_test_version/Test_video/maskoutput.avi", fourcc, FPS, SCREEN_SIZE)
cv2.namedWindow("Live", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Live", 1280, 720)
cv2.namedWindow("Live Mask", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Live Mask", 1280, 720)
cv2.namedWindow("Live Edges", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Live Edges", 1280, 720)

while True:
    # Capturez l'écran de l'ordinateur
    screenshot = pyautogui.screenshot()

    # Convertissez l'image en tableau numpy pour pouvoir la manipuler avec OpenCV
    frame = np.array(screenshot)

    # Application du traitement d'image
   
    # Define the lower and upper bounds of the WINDOW COLOR in the HSV color space  --> actual window color: Black
    lower_black = np.array([0, 0, 0])
    upper_black = np.array([180, 255, 30])

    # Convert the image to the HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Create a mask that only selects pixels that fall within the lower and upper bounds of the black color
    mask = cv2.inRange(hsv, lower_black, upper_black)
    # Appliquez le masque à la frame
    frame_masked = cv2.bitwise_and(frame, frame, mask=mask)
    #cv2.imshow("Mask", mask)

    # Apply Gaussian blur to the image
    blurred = cv2.GaussianBlur(mask, (25, 25), 0)
    #cv2.imshow("Blurred", blurred)

    # Use the Canny edge detection algorithm to detect edges in the image
    edges = cv2.Canny(blurred, 50, 150)
    # Appliquez le edgesà la frame
    frame_edges = cv2.bitwise_and(frame, frame, mask=edges)
    #cv2.imshow("Edges", edges)

    # Find contours in the mask
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Iterate over the contours and draw a rectangle around any contour that is a window-like shape
    for contour in contours:
        # Get the bounding rectangle of the contour
        x, y, w, h = cv2.boundingRect(contour)
        aspectRatio = float(w)/h
        center_x, center_y = int(x + w/2), int(y + h/2)

        # Check if the aspect ratio of the contour is close to 1.5, indicating it is window-like shape
        if 0.85 <= aspectRatio <= 1.2:
            cv2.rectangle(frame, (x, y), (x + w, y + h), (330, 0, 0), 2)
            if h>100:
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
                cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)
                cv2.putText(frame, "x: {} y: {}".format(center_x, center_y), (center_x+10, center_y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (300, 0, 255), 2, cv2.LINE_AA)

    # Affichez la frame dans une fenêtre
    cv2.imshow("Live", frame)
    # Affichez le mask dans une fenêtre
    cv2.imshow("Live Mask", frame_masked)
    # Affichez le mask dans une fenêtre
    cv2.imshow("Live Edges", frame_edges)
    print("Rec en cours")


    # Écrivez le cadre sur la sortie vidéo
    out.write(frame)
    edgesout.write(frame_edges)
    maskout.write(frame_masked)

    # Attendez 1 milliseconde et vérifiez si l'utilisateur appuie sur la touche 'q' pour quitter
    if cv2.waitKey(1) == ord('q'):
        print("Fin de programme")
        break

    if keyboard.is_pressed('q'):
        print("Le programme est arrêté.")
        break

# Fermez la fenêtre d'affichage et l'objet de capture vidéoqq
cv2.destroyAllWindows()
out.release()


