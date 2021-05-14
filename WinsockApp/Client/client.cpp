#include<stdio.h>	
#include<ws2tcpip.h>
#include <iostream>
#include "Donnee.h"

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

#define N 1000
#define BUFFER_SIZE 1024 
#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32") 

void main()
{
	std::cout << "\t\t\t\tBienvenue sur BETTER MSN.\n\n";

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 0), &wsa);

	SOCKET sock;
	SOCKADDR_IN sin;
	char ip[15];
	int port;
	SDonnee MesDonneesClient;

	//initialisation et saisi des informations
	std::cout << "Ip : ";
	std::cin >> ip;

	std::cout << "\nPort : ";
	std::cin >> port;

	sin.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &sin.sin_addr.s_addr);
	sin.sin_port = htons(port);

	//creation de la socket
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//connexion a la socket
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		std::cout << "La connection a echoue\n";

		system("PAUSE");
		exit(0);
	}

	char buffer[BUFFER_SIZE];
	memset(buffer, 0, sizeof(buffer));

	int err = 0;
	bool read = false;
	std::cout << "Votre nom : ";
	std::cin >> MesDonneesClient.name;

	//envoie fichier
	char file_name[1000]="coucou";
	int length = 0;
	

	std::cout << "entrez nom du fichier a recevoir :";
	std::cin >> file_name;


	while (err > -1)
	{
		if (MesDonneesClient.read == false)
		{
			std::cout << MesDonneesClient.name << " :\n";
			memset(MesDonneesClient.message, 0, sizeof MesDonneesClient.message);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			std::cin.getline(MesDonneesClient.message,4096);
			err = send(sock, (char*)&MesDonneesClient, sizeof(MesDonneesClient), 0);
			MesDonneesClient.read = !MesDonneesClient.read;
		}
		else
		{
			//SDonnee DonneeServeur;

			
			FILE* fp = fopen(file_name, "wb");
			

			memset(buffer, 0, BUFFER_SIZE);
			int length = 0;
			while ((length = recv(sock, buffer, BUFFER_SIZE, 0)) > 0)
			{
				if (fwrite(buffer, sizeof(char), length, fp) < length)
				{
					std::cout << "File: Write Failedn" << file_name;
					break;
				}
				memset(buffer, 0, BUFFER_SIZE);
			}

			std::cout << "Receive File: From Server Successful!n", file_name;



			//recv(sock, (char*)&DonneeServeur, sizeof(DonneeServeur), 0);
			//std::cout << DonneeServeur.name << " : ";
			
			//std::cout << DonneeServeur.message<<"\n\n";
			MesDonneesClient.read = !MesDonneesClient.read;
		}
	}
	closesocket(sock);

	std::cout << "Connection termin�e\n\n";

	WSACleanup();

}
