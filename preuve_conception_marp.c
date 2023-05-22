/*
 ---
marp: true
theme: projet
paginate: true
_paginate: false
---

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

**ING1** Projet d'informatique


# ECE World

Equipe 56

---

# Equipe 56

![bg right:50%](./images/equipe.avif)

- Antoine Lallement
- Eudes Boyer
- Malik Hassane

---

# ECE World

![bg right:50% 198%](./images/ciel_jaune.jpg)

## Thème

On a choisit de faire notre jeux sur l'univers du retro avec une carte assez futuriste

---

# Carte `1/2`

*Réalisée par : **Malik(100%)**.*

 conçu sur RPG Maker a base de tileset importés

theme futuriste:
-parc d'attration dans les airs
-avec a chaque jeu son endroit a titré

---NOM: "SKYLAND"
![bg right:40%](images/map.jpg)

---

# Carte `2/2`

![bg right:40%](images/map.jpg)


*Réalisée par : **Antoine**,**Eudes**.

:bulb: choix des noms grace a une interface, choix des skins et option de sauvegarde de la partie, affichage d'une minicarte, option de mause/dezoomage de la carte.

---

# Organisation des jeux

Pour chaque jeu il y a un fichier dédiée, ils sont tous regroupé dans une bibliotheque,

Les jeux prennent en parametre les joueurs ainsi que le numéro du joueur qui est rentré dans le mini-jeu pour certain,

On peut lancer un jeu sur la carte en allant vers un batiment et en appuyant sur E pour le lancer

le classement est affiché sur le coté de l'ecran et mis a jour a l'interieur des mini-jeux.


---

![bg right:40%](images/guitar_hero.jpg)

# "Guitare hero"

*Réalisé par : **Antoine** (100%)*


- la vitesse de base ainsi que l'accélération est modifiable par le joueur.
- les notes défilent de haut en bas de manières aléatoire
- Le joueur a le droit a 5 erreurs avant que le mini jeux se ferme
- Les tuiles ont une couleur associés ce qui permet de savoir si il y a une touche ou non a appuyer


---

![bg right:40%](images/guitar_hero.jpg)

# "guitare hero"

### structure tuiles

- `BITMAP *tuiles[4][8]`
- `int couleur[4][8]`
- `int pressed[4][8]`

### Fonctions
- parametres
- scroll_background
- calcul_speed
- verif_score




---

![bg right:40%](images/guitar_hero_jeu.png)

# "guitare hero"

### Graphe d'appel

<br>

game_guitare --> menu
menu --> parametres
game_guitare --> scroll_background
game_guitare --> calcul_speed
game_guitare --> verif_score



---

![bg right:40%](images/logigramme_guitare.png)

# "guitare hero"

### Logigramme



---

![bg right:40%](images/forain.webp)

# Tirs aux ballons

*Réalisé par : **Antoine** (100%)*


- la vitesse des ballons est parametrable (vitesse min/max)
- les ballons sont diposés de manieres aléatoires
- les meilleurs temps sont récompensées


---

![bg right:40%](images/forain.webp)

# Tirs aux ballons


### Structures

-structure de ballon
position, couleur, vitesse, en vie ?
, animation de mort

### Tableaux

- `t_ballon ballons[10]`




---

![bg right:40%](images/forain.webp)

# Tirs aux ballons

### Graphe d'appel

<br>

ballon --> Parametres


---

![bg right:40%](images/logigramme_ballon.png)

# Tirs aux ballons

### Logigramme




---
![bg right:40%](images/pong_arcade.jpg)

# Pong

*Réalisé par : **Antoine** (100%)*


- La vitesse de la balle de base est modifiable dans les parametres
- La balle gagne de la vitesse a chaque rebonds
- le gagnant est récompensé tandis-que le perdant lui perd un ticket
- l'adversaire est selectionable par le joueur


---

![bg right:40%](images/pong_arcade.jpg)

# Pong

### Structures

-structure de pong
position balle, block, vitesse des blocks et de la balle

### Tableaux

- `t_pong pongeurs[2]`




---

![bg right:40%](images/pong_arcade.jpg)

# Pong

### Graphe d'appel

<br>

game_PONG --> Parametres
game_PONG --> initpong
game_PONG --> condition_victoire
game_PONG --> deplacement_b/p
game_PONG --> draw_terrain
draw_terrain --> dessin_balle


---

![bg right:70%](images/logigramme_pong.png)

# Pong

### Logigramme




---



![bg right:40%](images/Horse-racing-4.jpg)

# Course hippique

*Réalisé par : **Eudes** (100%)*


- Chaque joueur parie sur le cheval gagnant
- Les chevaux avancent de maniere aléatoire
- Le ou les gagnants sont récompensés par un point et ne depensent pas de tickets
- Les autres joueurs perdent un ticket


---
![bg right:40%](images/Horse-racing-4.jpg)

# Course Hippique

### Graphe d'appel

<br>

courseHippique --> choixChevaux
courseHippique --> debutCourse
courseHippique --> ecranFin

---

![bg right:70%](images/logigrammeHippique.png)

# Course Hippique

### Logigramme




---


![bg right:40%](images/kikipenalty.jpg)

# Penalty

*Réalisé par : **Eudes** (100%)*


- Un joueur controle le gardien et l'autre le tireur
- Chaque coin du but est associé à un chiffre du Numpad
- La puissance du tir est reglé en fonction de la jauge à droite
- Le gardien peut faire un plongeon vers la lucarne,sur le coté ou se deplacer latérallement


---
![bg right:40%](images/kikipenalty.jpg)

#  Penalty

### Graphe d'appel

<br>

penalty --> menuPenalty
penalty --> actionPenalty
penalty --> animationGardien
penalty --> bougerGardien
penalty --> finPenalty



---

![bg right:70%](images/logigrammeFoot.png)

# Penalty

### Logigramme



---
![bg right:65%](images/jack.jpg)

### Jackpot

- by MALIK(100%)

---

![bg right:65%](images/jack.jpg)

- Le joueur active le jeu en esperant obtenir trois symboles identiques

- le joueur gagne ou perd un ticket en fonction des symboles qui l'obtient

---

![bg right:70%](images/logi_jackpot.png)

### Jackpot

- logigramme
---

#  Bilan collectif

---


# Antoine

## Tâches réalisées

- `✅ 100%` Nouvelle partie (choix des noms, personnages ...)
- `✅ 100%` Tâche 2 deplacement collisions + effet de 3D
- `✅ 100%` Charge d'un personnage
- `✅ 100%` Charge d'un personnage
- `✅ 100%` Tableau des scores
- `✅ 100%` Mini carte + carte dézoomer en pause
- `❌ 20%` essaie de son inaboutie
- `❌ 10%` Nouvelle police (font)

---

# Eudes

## Tâches réalisées

- `✅ 100%` Les joueurs peuvent sauvegarder leur partie sur 3 emplancement différents
- `✅ 100%` Les joueurs peuvent charger la partie qu'ils désirent au lancement

---

# Malik

## Tâches réalisées
- `✅ 100%` Map entierement personalisé sur un theme precis

-`✅ 100%` gestion du stress des coequipiers

---


# Investissement

Si vous deviez vous répartir des points, comment feriez-vous ?

- Antoine : 50
- Eudes : 40
- Malik : 10

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Pong| 95% | Pas de sons |
| Tir aux ballons | 100% | - |
| Guitar Hero | 100% | - |
| course hippique | 100% |-  |
| penalty | 100% | - |
| jackpot | 100% |  |
| mario | 60% |Manque de temps |


---

### lien vers le git_hub
- https://github.com/eudesBr1/ECE-WORLD









 */