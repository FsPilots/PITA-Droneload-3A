import cv2
import numpy as np

def pointlaser_detect(image):

    # Apply Gaussian blur to the image
    # ksize == 25 intensifie le flou et permet de reduire le bruit de l'image thresholded
    image =  cv2.GaussianBlur(image,(25, 25), 0)
    #cv2.imshow("Webcam blurred", blurred)

    # Convert the image to the HSV color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Définition des bornes de couleur pour le rouge -> Laser rouge
    lower_red = np.array([0, 50, 50])
    upper_red = np.array([10, 255, 255])
    lower_red2 = np.array([170, 50, 50])
    upper_red2 = np.array([180, 255, 255])

    # Masquage de l'image pour ne garder que les pixels rouges
    mask = cv2.inRange(hsv, lower_red, upper_red)
    mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
    mask = cv2.bitwise_or(mask, mask2)
    cv2.imshow("Mask", mask)

    # Application d'une morphologie pour éliminer les petits artefacts
    kernel = np.ones((5,5),np.uint8)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)

    # Recherche des contours dans l'image
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Initialisation d'une liste pour stocker les centres des cercles rouges
    centers = []

    # Parcours des contours et recherche des cercles rouges
    for contour in contours:
        #Calcul du rayon du cerle
        (center, radius) = cv2.minEnclosingCircle(contour)
        print('Center coutour:', center)
        print('Rayon: ',radius)
        # Calcul du centre du contour
        M = cv2.moments(contour)
        if M['m00'] != 0:
            cx = int(M['m10'] / M['m00'])
            cy = int(M['m01'] / M['m00'])
            #Stockage des coordonnées du centre
            centers.append((cx, cy))
    print('Recap des cercles trouvs:',centers)
    # Vérification que deux cercles rouges ont été détectés
    if len(centers) >= 2:
        #Traitement des coordonnées des cercles (Deduction de la distance)
        distance=np.sqrt(((centers[1][0]-centers[0][0]))**2+((centers[1][1]-centers[0][1]))**2)
        print(distance)
        # Dessin des cercles sur l'image d'origine et affichage des coordonnées
        for i, center in enumerate(centers):
            cv2.circle(image, center, 5, (0, 0, 255), -1)
            cv2.putText(image, f'{i+1} : ({center[0]}, {center[1]})', (center[0]-50, center[1]+30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1)    
        # Affichage de l'image avec les cercles et les coordonnées détectés
        cv2.putText(image, 'distance : {}'.format(distance),(150,250), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1)
        cv2.imshow('image', image)
    else:
        print('Deux cercles rouges n\'ont pas été détectés.')

    return image

# Ouverture de la vidéo en entrée
video = cv2.VideoCapture('test_picture\PointRouge.MP4')

# Boucle principale pour lire les images de la vidéo
while(video.isOpened()):
    # Lecture de l'image:
    ret,frame = video.read()
    if not ret:
        print("Aucune Vidéo")
        break
    else:
        pointlaser_detect(frame)    
        # Press q to quit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

