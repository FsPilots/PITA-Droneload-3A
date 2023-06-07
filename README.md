# pita3A-Droneload

L'ensemble des objectifs du projet ont été défini par l'equipe sur la base du règlement du concours Droneload 2023 : https://www.planete-sciences.org/espace/IMG/pdf/2023_droneload_reglement_v1.pdf

L'objectif premier du projet est de réaliser un vol automatique de drone.
Afin d'atteindre ce résultat, le travail a été divisé en différentes parties :

- Les programmes de pilotage qui permettent au drone d'être piloté par l'ordinateur avec différentes fonctions telles que "Haut / Bas / Gauche / Droite / Avant / Arrière"
- La reconnaissance d'image basée sur deux caméras FPV situées devant le drone (Front camera) et dans la backplate face vers le bas (Down Camera)
   - La caméra frontale est capable de détecter les carrés noirs (fenêtres) et les codes QR
   - La caméra Down est capable de détecter deux lasers rouges afin d'estimer l'altitude du drone, des panneaux simples comme celui "TAXI"

L'ensemble du code tourne en C++ par l'intermediaire de CodeBlocks (Fichier projet .CBP)
La méthode utilisé nous a permis de crée une interface graphique totalement modulable et modifiable qui regroupe l'ensemble des informations du drone telles que:
- La position des joysticks de la radio
- Les deux flux vidéos
- La visualisation des programmes de pilotages en cours d'execution
- La posibilité d'enregistrer les flux vidéos, les logs de joysticks et autres informations
- La possibilité de modifié les reglages de traitement d'image en temps réel
