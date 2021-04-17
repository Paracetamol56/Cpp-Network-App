#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
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
	

	char ConnectionType;
	char buffer[2000];
	std::size_t received;

	sf::IpAddress ipReceiver;
	unsigned short port;
	sf::Time TimeOut= sf::seconds(10);;
	std::string name;

	std::string content;


	//thread receive
		std::thread receive ([&buffer,&Socket1,&received]() {
			
			Socket1.receive(buffer, sizeof(buffer), received);
			
		});

	////////////////////////////////////////


	//nom de l'app
	std::cout << "============================== Better MSN ==============================\n\n";


	//Initialisation de la connexion 
	std::cout << "Entrez 's' si vous etes le serveur et 'c' si vous etes le client: ";
	std::cin >> ConnectionType;
	///////////////////////////////

	//demande les informations necessaire a la connexion en fonction du role de l'utilisateur
	if (ConnectionType == 's') //Serveur
	{
		
		std::cout << "Vous etes le serveur! \n";
		std::cout << "\nEntrez le port de connexion :";
		std::cin >> port;
		std::cout << "\nEntrez votre nom : ";
		std::cin >> name;



		Listener.listen(port);
		Listener.accept(Socket1);
		memset(buffer, 0, 2000);

		

		//boucle envoie
		while (1 == 1)
		{
			
			std::getline(std::cin, content);
			Socket1.send(content.c_str(), content.length() + 1);
			receive.join();

			std::cout << buffer << "\n\n";
			memset(buffer, 0, 2000);

		}

	}

	else if (ConnectionType == 'c') //Client
	{

		
		std::cout << "Vous etes le client! \n";
		std::cout << "\nEntrez l'adresse ip du correspondant : ";
		std::cin >> ipReceiver;
		std::cout << "\nEntrez le port de connexion :";
		std::cin >> port;
		std::cout << "\nEntrez votre nom : ";
		std::cin >> name;

		Socket1.connect(ipReceiver, port,TimeOut);
		memset(buffer, 0, 2000);

		


		//boucle envoie
		while (1 == 1)
		{
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
				std::getline(std::cin, content);
			}*/

			std::getline(std::cin, content);
			Socket1.send(content.c_str(), content.length() + 1);
			receive.join();

			std::cout << buffer << "\n\n";
			memset(buffer, 0, 2000);

		}
		

		std::cout << buffer<<"\n\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////////






	//Pour le moment ce qu'il y a en dessous on s'en fout

	//Connexion

	//if (Socket1.connect(ipReceiver, port, TimeOut)) {
	//	Listener.accept(Socket1);
	//}


	//while (Socket1.connect(ipReceiver, port, TimeOut) == sf::TcpSocket::Status::Done) {
	//	
	//	Listener.listen(port);

	//	while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))) {
	//		std::string content;
	//		std::cin >> content;
	//		packet.append(content);
	//		Socket1.send(packet);
	//	}
	//}
	///////////////////////////////////////////////////////
	


	system("PAUSE");

}
