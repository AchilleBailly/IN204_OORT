# IN204_OORT
Object oriented ray tracing project


# Anlyse initiale
Principales fonctionnalités :
  - pouvoir implémenter/modifier/créer des scénes 3D basiques (sphères, plans, cubes, sources de lumières)
    * interface graphique ?
    * quel format ?
  - proposer (au moins) un moteur de rendu par RT
    * diminuer un maximum les temps de calcul : accélération GPU et/ou multithreading
    * différents algorithmes de calcul
  - proposer une interface utilisateur : sélection de la scène, du moteur, rendu final
  - avoir la possibilité de facilement rajouter des moteurs de rendu différents, des objets plus complexes (en forme, en textures, dans leurs interactions avec la lumière)

Choix de la librairie de rendu 2D : SDL2 car plutôt simple, et accès au GPU ou **SFML**
Accélération de calcul : OpenCL1.x en combinaison avec des API comme Boost.Compute, Intel CLU, **SYCL** pour faciliter le codage.
  -> SYCL : https://www.khronos.org/assets/uploads/developers/presentations/CppCon-Efficient-GPU-Programming_Sep19.pdf
  -> SDL2 : https://devopssec.fr/article/bases-fondamentales-de-laffichage-graphique-sdl2
  -> SFML : https://www.sfml-dev.org/learn.php

# Installation des bibliothèques
J'ai d'abord essayé d'installer OpenCL pour pouvoir l'utiliser à travers ComputeCpp sur Windows, je n'ai pas réussi. 
Je m'attellerai donc à l'accélération GPU plus tard. 
J'ai ensuite tenté d'utiliser la SFML sur MacOS, avec difficultés, pour enfin y arriver grâce à CMake.

# Documentation
Approches du Ray-Tracing :
https://nguyen.univ-tln.fr/share/Infographie3D/trans_raytracing.pdf
https://fr.wikipedia.org/wiki/Ray_tracing
