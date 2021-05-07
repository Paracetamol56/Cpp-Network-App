#include <iostream>
#include <ws2tcpip.h>
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

sf::TcpListener Listener;

int main() {
	void intercepte(char buffer[], sf::TcpSocket& Socket1, size_t& received);
	//Déclaration de variables et autre
	sf::TcpSocket Socket1;
	
	Socket1.setBlocking(true);

	Listener.setBlocking(true);
	

	char ConnectionType;
	char buffer[2000];
	std::size_t received;

	sf::IpAddress ipReceiver;
	unsigned short port;
	sf::Time TimeOut= sf::seconds(10);;
	std::string name;

	std::string content;


	bool parole;
	

	
	

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
		
		parole = true;

		while (1 == 1) {
			if (parole == true) {
				std::cout << name << " : \n";
				memset(buffer, 0, sizeof(buffer));
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				std::cin >> content;
				Socket1.sf::TcpSocket::send(content.c_str(), content.length() + 1);
				parole = false;
				
			}
			else if (parole == false) 
			{
				Socket1.sf::TcpSocket::receive(buffer, sizeof(buffer), received);
				std::cout << name << " : \n";
				std::cout << buffer << "\n\n";
				parole = true;
			}

		}
		

		//lancement du thread de lecture
		
		//std::thread listen(intercepte,std::ref(buffer),std::ref(Socket1),std::ref(received));
		//
		////boucle envoie
		//while (1 == 1)
		//{
		//	std::cin>> contentserveur;
		//	Socket1.sf::TcpSocket::send(contentserveur.c_str(), contentserveur.length() + 1);
		//	
		//	
		//}

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
		
		parole = false;
		
		//lancement du thread de lecture
		
		//
		//std::thread listen(intercepte, std::ref(buffer), std::ref(Socket1), std::ref(received));

		////boucle envoie
		//while (1 == 1)
		//{
		//	std::cin>>contentclient;
		//	Socket1.sf::TcpSocket::send(contentclient.c_str(), contentclient.length() + 1);
		//}

		while (1 == 1) {
			if (parole == true) {
				std::cout << name << " : \n";
				memset(buffer, 0, sizeof(buffer));
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				std::getline(std::cin, content);
				Socket1.sf::TcpSocket::send(content.c_str(), content.length() + 1);
				parole = false;
			}
			else if (parole == false)
			{
				Socket1.sf::TcpSocket::receive(buffer, sizeof(buffer), received);
				std::cout << name << " : \n";
				std::cout << buffer << "\n\n";
				parole = true;
			}
		}

		//std::cout << buffer<<"\n\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////////



	system("PAUSE");

}





//fonction de lecture
void intercepte(char buffer[],sf::TcpSocket& Socket1,size_t& received ) 
{
	while (1 == 1) {
		
		Socket1.sf::TcpSocket::receive(buffer, sizeof(buffer), received);
		

		if (buffer != memset(buffer, 0, 2000)) {
			std::cout << *buffer << "\n\n";
		}

		memset(buffer, 0, 2000);
	}
}