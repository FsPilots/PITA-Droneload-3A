import cv2
import numpy as np

RESOLUTION_X , RESOLUTION_Y = 1920, 1080  # Resolution de la caméra / vidéo
SIZE_ERROR = 200
SIZE_ACCROCHE_ERROR = 10
ACCROCHE_ERROR = 10

def window_detection(frame, accroche, indice_non_accrochage, save_center_x, save_center_y):

    # Application du traitement d'image

    # Define the lower and upper bounds of the WINDOW COLOR in the HSV color space  --> actual window color: Black
    lower_black = np.array([0, 0, 0])
    upper_black = np.array([180, 255, 30])

    # Convert the image to the HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Create a mask that only selects pixels that fall within the lower and upper bounds of the black color
    mask = cv2.inRange(hsv, lower_black, upper_black)
    cv2.imshow("Live mask", mask)

    # Appliquer le seuillage adaptatif
    thresh = cv2.adaptiveThreshold(mask, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY_INV, 5, 2)
    cv2.imshow("Live thresh",thresh)

    # Creation d'un leger flou pour lisser les contours 
    blurred = cv2.GaussianBlur(thresh,(25,25),5)
    cv2.imshow("Live blur",blurred)

    # Use the Canny edge detection algorithm to detect edges in the image
    edges = cv2.Canny(thresh, 100, 200)
    cv2.imshow("Live edges",edges)

    # Find contours in the mask
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    if accroche == 1:
        k = 0
        # Iterate over the contours and draw a rectangle around any contour that is a window-like shape
        for contour in contours:
            # Get the bounding rectangle of the contour
            x, y, w, h = cv2.boundingRect(contour)
            aspectRatio = float(w)/h
            center_x, center_y = int(x + w/2), int(y + h/2)
            check_x1, check_x2 = int(save_center_x - SIZE_ACCROCHE_ERROR), int(save_center_x + SIZE_ACCROCHE_ERROR)
            check_y1, check_y2 = int(save_center_y - SIZE_ACCROCHE_ERROR), int(save_center_y + SIZE_ACCROCHE_ERROR)
            # Check if the window is centered
            if (check_x1 < center_x < check_x2) & (check_y1 < center_y < check_y2):
                # Check if the aspect ratio of the contour is close to 1, indicating it is window-like shape
                if 0.85 <= aspectRatio <= 1.2:
                    if h>100:
                        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
                        cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)
                        cv2.putText(frame, "x: {} y: {}".format(center_x, center_y), (center_x+10, center_y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (300, 0, 255), 2, cv2.LINE_AA)
                        k = 1
                        indice_non_accrochage = 0
                        save_center_x, save_center_y = center_x, center_y
                        break
            else:
                k = 0

        # Vérification de l'accroche pour une itération
        if k == 0:
            indice_non_accrochage = indice_non_accrochage + 1
            # Si l'accroche est perdue pour un nombre d'itération supérieur à la limite, l'accroche est perdue.
            if indice_non_accrochage >= ACCROCHE_ERROR:
                accroche = 0
                print("END ACCROCHAGE")
    else:

        # Iterate over the contours and draw a rectangle around any contour that is a window-like shape
        for contour in contours:
            # Get the bounding rectangle of the contour
            x, y, w, h = cv2.boundingRect(contour)
            aspectRatio = float(w)/h
            center_x, center_y = int(x + w/2), int(y + h/2)
            check_x1, check_x2 = int(RESOLUTION_X/2 - SIZE_ERROR), int(RESOLUTION_X/2 + SIZE_ERROR)
            check_y1, check_y2 = int(RESOLUTION_Y/2 - SIZE_ERROR), int(RESOLUTION_Y/2 + SIZE_ERROR)
            # Check if the window is centered
            if (check_x1 < center_x < check_x2) & (check_y1 < center_y < check_y2):
                # Check if the aspect ratio of the contour is close to 1, indicating it is window-like shape
                if 0.85 <= aspectRatio <= 1.2:
                    if h>100:
                        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
                        cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)
                        cv2.putText(frame, "x: {} y: {}".format(center_x, center_y), (center_x+10, center_y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (300, 0, 255), 2, cv2.LINE_AA)
                        accroche = 1
                        indice_non_accrochage = 0
                        print("ACCROCHAGE")
                        save_center_x, save_center_y = center_x, center_y
                        break
        
    cv2.imshow("Live", frame)
    return [accroche, indice_non_accrochage, save_center_x, save_center_y]

# Ouverture de la vidéo en entrée
video = cv2.VideoCapture('Python_test_version/Test_video/capture.mp4')

# Calculer le numéro de frame correspondant à la seconde 11
start_frame = int(12 * 60)

# Avancer à la frame souhaitée
video.set(cv2.CAP_PROP_POS_FRAMES, start_frame)

# Set accroche = 0, indice_non_accrochage = ACCROCHE_ERROR x = 0 et y = 0
indice_non_accrochage = ACCROCHE_ERROR
accroche =  0
x, y = 0, 0

# Boucle principale pour lire les images de la vidéo
while(video.isOpened()):
    # Lecture de l'image:
    ret,frame = video.read()
    if not ret:
        print("Aucune Vidéo")
        break
    else:
        print("Analyse en cours")
        result = window_detection(frame, accroche, indice_non_accrochage, x, y)
        accroche = result[0]
        indice_non_accrochage = result[1]
        x = result[2]
        y = result[3]
        if accroche == 1:
            print("center x = ",x," center y = ",y, "ACCROCHE", "INA = ", indice_non_accrochage)
        else:
            print("center x = ",x," center y = ",y," AUCUNE ACCROCHE")
        # Press q to quit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
