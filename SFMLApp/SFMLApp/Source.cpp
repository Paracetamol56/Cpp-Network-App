#include <iostream>
#include <string>
#include <SFML/NetWork/Socket.hpp>
#include <SFML/NetWork/TcpSocket.hpp>
#include <SFML/NetWork/IpAddress.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/NetWork/TcpListener.hpp>
#include <SFML/NetWork/Packet.hpp>
#include <SFML/Window/Keyboard.hpp>



int main() {
	//Déclaration de variables et autre
	sf::TcpSocket Socket1;
	Socket1.setBlocking(false);
	sf::TcpListener Listener;
	Listener.setBlocking(false);
	sf::Packet packet;

	sf::IpAddress ipReceiver;
	unsigned short port;
	sf::Time TimeOut= sf::seconds(10);;
	std::string name;
	
	//nom de l'app
	std::cout << "============================== Better MSN ==============================\n\n";


	//Initialisation de la connexion 
	
	std::cout << "Entrez l'adresse ip du correspondant : ";
	std::cin >>ipReceiver;
	std::cout << "\nEntrez le port de connexion :";
	std::cin >> port;
	std::cout << "\nEntrez votre nom : ";
	std::cin >> name;

	//Connexion

	while (Socket1.connect(ipReceiver, port, TimeOut) == sf::TcpSocket::Status::Done) {
		Listener.listen(port);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
			std::string content;
			std::cin >> content;
			//packet.append(content);
		}
	}

	


	system("PAUSE");

}
