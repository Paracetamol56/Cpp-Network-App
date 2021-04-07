#include<stdio.h>	
#include<ws2tcpip.h>
#include <iostream>
#include "Donnee.h"

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

void main()
{
	std::cout << "\t\t\t\tBienvenue sur \"T\'Chat\".\n\n";

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 0), &wsa);

	SOCKET sock;
	SOCKADDR_IN sin;
	char ip[15];
	int port;
	SDonnee DonneesClient;

	//initialisation et saisi des informations
	std::cout << "Ip : ";
	std::cin >> ip;

	std::cout << "Port : ";
	std::cin >> port;

	sin.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &sin.sin_addr.s_addr);
	sin.sin_port = htons(port);

	//creation de la socket
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SDonnee MesDonneeClient;
	MesDonneeClient.read = true;

	std::cout << "Votre nom : ";
	std::cin >> MesDonneeClient.nom;

	//connexion a la socket
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		std::cout << "La connection a echoue\n";

		system("PAUSE");
		exit(0);
	}

	int err = 0;
	bool read = false;


	while (err > -1)
	{
		if (MesDonneeClient.read == false)
		{
			std::cout << '\n' << MesDonneeClient.nom << " :\n";
			memset(MesDonneeClient.message, 0, sizeof(MesDonneeClient.message));
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			std::cin.getline(MesDonneeClient.message, 4096);
			err = send(sock, (char*)&MesDonneeClient, sizeof(MesDonneeClient), 0);
			MesDonneeClient.read = !MesDonneeClient.read;
		}
		else
		{
			SDonnee DonneeServeur;
			recv(sock, (char*)&DonneeServeur, sizeof(DonneeServeur), 0);
			std::cout << DonneeServeur.nom << " :\n";
			std::cout << DonneeServeur.message << " :\n";
			MesDonneeClient.read = DonneeServeur.read;
		}
	}
	closesocket(sock);

	std::cout << "Connection termin�e\n\n";

	WSACleanup();

}
