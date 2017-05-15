# Les binaires


Ce dossier contient des binaires qui vous serviront lors de votre projet.


## Serveur de publication

Le serveur de publication vous permet de preparer votre client sans attendre que le serveur soit pret.
Il utilise le port `12345` et est accessible en local ou depuis l'exterieur, il utilise une socket zeromq de type PUB.

Il envois toute les 2 secondes des informations sur la partie avec la configuration suivantes :

* une carte de taille 10x10
* 4 joueurs connectes et actifs
* Tous les joueurs tente de se rendre au centre de la map

