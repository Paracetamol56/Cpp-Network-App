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

_(non deffinitif)_

![UML](https://mermaid.ink/svg/eyJjb2RlIjoiJSV7aW5pdDogeyd0aGVtZSc6J2Jhc2UnLCAndGhlbWVWYXJpYWJsZXMnOiB7ICdwcmltYXJ5Q29sb3InOiAnI2NjZWVmZicsICdjbGFzc1RleHQnOiAnIzAwMCcgfVxuICAgIH19JSVcbiAgICBjbGFzc0RpYWdyYW1cbiAgICAgICAgY2xhc3MgQ0FwcCB7XG4gICAgICAgIC1tX2ZyYW1lMDEgOiBDTWFpbipcbiAgICAgICAgK0NBcHAoKVxuICAgICAgICArdmlydHVhbCBib29sIE9uSW5pdCgpXG4gICAgICAgIH1cblxuICAgICAgICBjbGFzcyBDTWFpbiB7XG4gICAgICAgIC1tX21haW5NZW51QmFyIDogd3hNZW51QmFyKlxuICAgICAgICAtbV9maWxlTWVudSA6IHd4TWVudSpcbiAgICAgICAgLW1faGVscE1lbnUgOiB3eE1lbnUqXG4gICAgICAgIC1zZWNvbmRhcnlPdXRwdXRTaXplciA6IHd4Qm94U2l6ZXIqXG4gICAgICAgIC1tX2lucHV0VGV4dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX2lucHV0RmlsZVBhdGggOiB3eFN0cmluZ1xuICAgICAgICAtbV9jb250ZW50TGlzdCA6IGxpc3Q8Q0NvbnRlbnQqPlxuICAgICAgICArQ01haW4oKVxuICAgICAgICArZ2V0SW5wdXREYXRhKCkgOiB3eFN0cmluZ1xuICAgICAgICArdXBkYXRlQ29udGVudCgpIDogdm9pZFxuICAgICAgICArT25RdWl0KCkgOiB2b2lkXG4gICAgICAgICtPblNldHRpbmdzKCkgOiB2b2lkXG4gICAgICAgICtPbkFib3V0KCkgOiB2b2lkXG4gICAgICAgICtPbkJ1dHRvblNlbmQoKSA6IHZvaWRcbiAgICAgICAgK09uQnV0dG9uQWRkZmlsZSgpIDogdm9pZFxuICAgICAgICB9XG5cbiAgICAgICAgY2xhc3MgQ0NvbnRlbnQge1xuICAgICAgICAtbV9jb250ZW50VGltZTpzdGQ6OmNocm9ubzogOiB0aW1lX3BvaW50PHN0ZDo6Y2hyb25vOjpzeXN0ZW1fY2xvY2s-XG4gICAgICAgIC1tX3VzZXJuYW1lIDogd3hTdHJpbmdcbiAgICAgICAgLW1fdGV4dE1lc3NhZ2UgOiB3eFN0cmluZ1xuICAgICAgICAtbV9maWxlUGF0aCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX2ltYWdlUGFuZWwgOiBDSW1hZ2VQYW5lbCpcbiAgICAgICAgK0NDb250ZW50KClcbiAgICAgICAgfVxuXG4gICAgICAgIGNsYXNzIENJbWFnZVBhbmVsIHtcbiAgICAgICAgLW1faW1hZ2UgOiB3eEltYWdlXG4gICAgICAgIC1tX3Jlc2l6ZWQgOiB3eEJpdE1hcFxuICAgICAgICArQ0ltYWdlUGFuZWwocGFyZW50IDogd3hQYW5lbCosIGZpbGVQYXRoIDogd3hTdHJpbmcsIGZvcm1hdCA6IHd4Qml0bWFwVHlwZSlcbiAgICAgICAgK0NJbWFnZVBhbmVsKHBhcmVudCA6IHd4RnJhbWUqLCBmaWxlUGF0aCA6IHd4U3RyaW5nLCBmb3JtYXQgOiB3eEJpdG1hcFR5cGUpXG4gICAgICAgICtwYWludEV2ZW50KGV2dCA6IHd4UGFpbnRFdmVudCYpIDogdm9pZFxuICAgICAgICArcGFpbnROb3coKSA6IHZvaWRcbiAgICAgICAgK09uU2l6ZShldnQgOiB3eFBhaW50RXZlbnQmKSA6IHZvaWRcbiAgICAgICAgK3JlbmRlcihkYyA6IHd4REMmKSA6IHZvaWRcbiAgICAgICAgfVxuXG4gICAgICAgIGNsYXNzIENTZXR0aW5ncyB7XG4gICAgICAgIC1tX0lQQWRyZXNzMDFJbnB1dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX0lQQWRyZXNzMDJJbnB1dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX0lQQWRyZXNzMDNJbnB1dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX0lQQWRyZXNzMDRJbnB1dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX3BvcnRJbnB1dCA6IHd4U3RyaW5nXG4gICAgICAgIC1tX3VzZXJuYW1lSW5wdXQgOiB3eFN0cmluZ1xuICAgICAgICArb25CdXR0b25PaygpIDogdm9pZFxuICAgICAgICArb25CdXR0b25DYW5jZWwoKSA6IHZvaWRcbiAgICAgICAgfVxuXG4gICAgICAgIENBcHAgXCIxXCIgLS0-IFwiMVwiIENNYWluIDogbV9mcmFtZTAxXG4gICAgICAgIENNYWluIFwiMVwiIC0tPiBcIjFcIiBDU2V0dGluZ3NcbiAgICAgICAgQ01haW4gXCIxXCIgLS0-IFwiMC4uKlwiIENDb250ZW50IDogbV9jb250ZW50TGlzdFxuICAgICAgICBDQ29udGVudCBcIjFcIiAtLT4gXCIxXCIgQ0ltYWdlUGFuZWwgOiBtX2ltYWdlUGFuZWwiLCJtZXJtYWlkIjp7InRoZW1lIjoiZGVmYXVsdCJ9LCJ1cGRhdGVFZGl0b3IiOmZhbHNlfQ)

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
