# Cpp-Network-App

---

![Work in progress](https://img.shields.io/badge/-Work%20In%20Progress-red?style=flat-square) ![Language](https://img.shields.io/badge/Language-C++-blue?style=flat-square) ![GitHub contributors](https://img.shields.io/github/contributors/Paracetamol56/Cpp-Network-App?style=flat-square) ![GitHub last commit](https://img.shields.io/github/last-commit/Paracetamol56/Cpp-Network-App?style=flat-square) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/Paracetamol56/Cpp-Network-App?style=flat-square)

_[EN]_

## Presentation

This is a two person network chat application.

The application is made in ultra low level C++, the graphics library used is WXwidgets C++ and the communication part is handled by sfml.

The network communication system uses a non-blocking socket and each user is able to send/retrieve data.

## Compiling and debugging

You must download the WXwidgets libraries and put the `lib` and` included` directories in the solution directory. Choose the LIBDebug or LIBRelease configuration to compile because the program only uses static libraries.
**Download Libraries:** https://www.wxwidgets.org/downloads/
You can download the source code and compile the libraries yourself or download the precompiled `.lib` files.

## Installation

At the moment, the application is still in the development, no release is available.

---

_[FR]_

## Presentation

Ceci est une application réseaux de chat à deux personnes.

L'application est programmée en C++ ultra bas niveau, la bibliothèque graphique utilisé est WXwidgets C++ et la partie communication est assurée par sfml.

Le système de communication réseaux utilise un socket non bloquant et chaque utilisateur est capable d’envoyer/récupérer des données.

## Compilation et debugging

Vous devez impérativement télécharger les bibliothèques WXwidgets et mettre les répertoires `lib` et `inclue` dans le répertoire de la solution. Choisissez les configuration LIBDebug ou LIBRelease pour compiler car le programme utilise des bibliothèques statiques.
**Télécharger les bibliothèques :** https://www.wxwidgets.org/downloads/
Vous pouvez télécharger le code source et compiler les bibliothèques vous-même où télécharger les fichiers `.lib` précompilés.

## Installation

Pour l’instant, l’application est encore en phase de développement, aucune release n’est disponible.

---

## _[EN]_ UML class diagram / _[FR]_ Diagramme UML de classe

_(non definitive / non deffinitif)_

![UML](/Doc/mermaid-diagram-20210514103155.svg)

### _[EN]_ Classes description :

- `CApp`: main entry point of the application
- `CMain`: Management of the main window with events, message list and content display
- `CSettings`: Stores the application settings and manages a window for the user to enter them
- `CContent`: Stock the data of a message (text, username, date and time, files attached) and organize them in a panel.
- `CImagePanel`: Class allowing the display of an image in a panel

### _[FR]_ Description des classes :

- `CApp` : point d’entrée principale de l’application
- `CMain` : Gestion de la fenêtre principale avec évènements, liste de message et affichage du contenu
- `CSettings` : Stock les paramètres de l’application et gère aussi une fenêtre pour que l’utilisateur puisse les saisir
- `CContent` : Stock les données d’un message (texte, nom d’utilisateur, date et heure, fichiers joints avec le message) et les organise dans un panneau.
- `CImagePanel` : Class permettant l’affichage d’une image sous forme de panneau
