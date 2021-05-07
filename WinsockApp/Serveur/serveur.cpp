#include <stdio.h>	
#include <ws2tcpip.h>
#include <iostream>
#include "Donnee.h"

#pragma comment(lib,"ws2_32.lib")

#define N 1000

void main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 0), &wsa);

	SOCKET server;
	SOCKET sock;

	SOCKADDR_IN sinserv;
	SOCKADDR_IN sin;

	int port;
	//initialisation et saisi des informations
	std::cout << "Port : ";
	std::cin >> port;

	sinserv.sin_family = AF_INET;
	sinserv.sin_addr.s_addr = INADDR_ANY;
	sinserv.sin_port = htons(port);

	//creation de la socket
	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//la socket est configur� pour �couter l'adresse et le port saisi
	bind(server, (SOCKADDR*)&sinserv, sizeof(sinserv));

	//pas de file d'attente
	listen(server, 0);

	int sinsize;
	int err = 0;
	SDonnee MesDonneeServeur;
	MesDonneeServeur.read = false;

	std::cout << "Votre nom : ";
	std::cin >> MesDonneeServeur.name;

	while (1)
	{
		sinsize = sizeof(sin);
		//acceptation ou non des appels
		if ((sock = accept(server, (SOCKADDR*)&sin, &sinsize)) != INVALID_SOCKET)
		{
			while (err > -1)
			{
				if (MesDonneeServeur.read == false)
				{
					std::cout << MesDonneeServeur.name << " :\n";
					memset(MesDonneeServeur.message, 0, sizeof(MesDonneeServeur.message));
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			        std::cin.getline(MesDonneeServeur.message,4096);
					err = send(sock, (char *)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);
					MesDonneeServeur.read = !MesDonneeServeur.read;
				}
				else
				{
					SDonnee SesDonneeClient;
					recv(sock, (char*)&SesDonneeClient, sizeof(SesDonneeClient), 0);
					std::cout << SesDonneeClient.name << " : ";
					std::cout << SesDonneeClient.message<<"\n\n";
					MesDonneeServeur.read = !MesDonneeServeur.read;
				}
			}
			closesocket(sock);
		}
	}
	closesocket(server);
	WSACleanup();

}
