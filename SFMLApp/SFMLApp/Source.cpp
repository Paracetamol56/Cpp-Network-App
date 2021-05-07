#include <iostream>
<<<<<<< Updated upstream
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
=======
#include <SFML/Network.hpp>
>>>>>>> Stashed changes

const unsigned short PORT = 9999;
const std::string IPADDRESS = "127.0.0.1"; //change to suit your needs

<<<<<<< Updated upstream
int main() {
	void intercepte(char buffer[], sf::TcpSocket& Socket1, size_t& received);
	//Déclaration de variables et autre
	sf::TcpSocket Socket1;
	
	Socket1.setBlocking(true);

	Listener.setBlocking(true);
	
=======
std::string msgSend;
>>>>>>> Stashed changes

sf::TcpSocket socket;
sf::Mutex globalMutex;
bool quit = false;

<<<<<<< Updated upstream
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
=======
void DoStuff(void)
{
	static std::string oldMsg;
	while (!quit)
>>>>>>> Stashed changes
	{
		sf::Packet packetSend;
		globalMutex.lock();
		packetSend << msgSend;
		globalMutex.unlock();

		socket.send(packetSend);

<<<<<<< Updated upstream
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

=======
		std::string msg;
		sf::Packet packetReceive;

		socket.receive(packetReceive);
		if ((packetReceive >> msg) && oldMsg != msg && !msg.empty())
		{
			std::cout << msg << std::endl;
			oldMsg = msg;
		}
>>>>>>> Stashed changes
	}
}

<<<<<<< Updated upstream
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
=======
void Server(void)
{
	sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
}
>>>>>>> Stashed changes

bool Client(void)
{
	if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
	{
		std::cout << "Connected\n";
		return true;
	}
	return false;
}

void GetInput(void)
{
	std::string s;
	std::cout << "\nEnter \"exit\" to quit or message to send: ";
	getline(std::cin, s);
	if (s == "exit")
		quit = true;
	globalMutex.lock();
	msgSend = s;
	globalMutex.unlock();
}


<<<<<<< Updated upstream

=======
int main(int argc, char* argv[])
{
	sf::Thread* thread = nullptr;
>>>>>>> Stashed changes

	char who;
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin >> who;

	if (who == 's')
		Server();
	else if (who == 'c')
		Client();
	else
	{
		std::cout << "Unknown option";
		return 1;
	}

	thread = new sf::Thread(&DoStuff);
	thread->launch();

	while (!quit)
	{
		GetInput();
	}

	if (thread)
	{
		thread->wait();
		delete thread;
	}
	return 0;
}