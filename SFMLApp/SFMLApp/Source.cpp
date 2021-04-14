#include <iostream>
#include <string>
#include <SFML/NetWork/Socket.hpp>
#include <SFML/NetWork/TcpSocket.hpp>



int main() {
	//Déclaration de variables et autre
	sf::TcpSocket Socket1;
	std::string ipReceiver;
	int port;
	std::string name;
	
	//Initialisation de la connexion 
	
	std::cout << "Entrez l'adresse ip du correspondant : ";
	std::cin >> ipReceiver;
	std::cout << "\n Entrez le port de connexion :";
	std::cin >> port;
	std::cout << "\n Entrez votre nom : ";
	std::cin >> name;


}
