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
	bool read = true;
	std::cout << "\nVotre nom : ";
	std::cin >> MesDonneesClient.name;

	//envoie fichier
	char file_name[1000]="coucou";
	int length = 0;
	
	//Color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int classiqueColor = 15;
	int serveurColor = 55;
	int clientColor = 95;
	int infoColor = 8;


	while (err > -1)
	{
		if (read == false)
		{
			
			memset(MesDonneesClient.message, 0, sizeof(MesDonneesClient.message));
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

			SetConsoleTextAttribute(hConsole, infoColor);
			std::cout << "Entrez 'f' pour envoyer un fichier et 't' si vous voulez envoyer un texte :";
			std::cin >> MesDonneesClient.TypeCom;
			SetConsoleTextAttribute(hConsole, classiqueColor);

			//envoie d'image
			if (MesDonneesClient.TypeCom == 'f') {
				//envoie de la Struct pour que le serveur sache le type d'envoie
				err = send(sock, (char*)&MesDonneesClient, sizeof(MesDonneesClient), 0);
				//envoie du nom du fichier
				std::cout << "entrez nom du fichier a envoyer :";
				std::cin >> file_name;

				//ecriture du fichier
				FILE* fp = fopen(file_name, "rb");

				while ((length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
				{
					if (send(sock, buffer, length, 0) < 0)
					{
						std::cout << "Send File:  Failed" << file_name;
						break;
					}
					memset(buffer, 0, BUFFER_SIZE);
				}
				fclose(fp);

				read = !read;
			}
			//Envoie de texte
			if (MesDonneesClient.TypeCom == 't') {
				SetConsoleTextAttribute(hConsole, clientColor);
				std::cout << MesDonneesClient.name<<" :\n";
				SetConsoleTextAttribute(hConsole, classiqueColor);

				memset(buffer, 0, BUFFER_SIZE);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				std::cin.ignore();
				std::cin.getline(MesDonneesClient.message, 4096);
				std::cout << "\n";
				err = send(sock, (char*)&MesDonneesClient, sizeof(MesDonneesClient), 0);
				read = !read;
			}
		}
		else
		{

			SDonnee DonneeServeur;
			while (DonneeServeur.TypeCom == NULL) {
				recv(sock, (char*)&DonneeServeur, sizeof(DonneeServeur), 0);
				
			}

			//reception d'image
			if (DonneeServeur.TypeCom == 'f') {
				std::cout << "entrez nom du fichier a recevoir :";
				std::cin >> file_name;

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
				
				fclose(fp);
				read = !read;
			}

			//reception de texte 
			if (DonneeServeur.TypeCom == 't') {
				if (DonneeServeur.message[0] == '\0') {
					recv(sock, (char*)&DonneeServeur, sizeof(DonneeServeur), 0);
				}
				SetConsoleTextAttribute(hConsole, serveurColor);
				std::cout << DonneeServeur.name << " :";
				SetConsoleTextAttribute(hConsole, classiqueColor);
				std::cout << DonneeServeur.message<<"\n\n";
				read = !read;
			}
		}
	}
	closesocket(sock);

	std::cout << "Connection termin�e\n\n";

	WSACleanup();

}
