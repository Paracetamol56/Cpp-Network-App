#include <stdio.h>	
#include <fstream>
#include <ws2tcpip.h>
#include <iostream>
#include "Donnee.h"

#pragma comment(lib,"ws2_32.lib")


#define BUFFER_SIZE 1024 
#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32") 

void main()
{
	std::cout << "\t\t\t\tBienvenue sur BETTER MSN.\n\n";

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
	bool read = false;

	//envoie de fichier
	char file_name[1000];
	int length ;
	char buffer[BUFFER_SIZE];



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
				if (read == false)
				{
					std::cout << MesDonneeServeur.name << " :\n";
					memset(MesDonneeServeur.message, 0, sizeof(MesDonneeServeur.message));
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

					//envoie du nom du fichier
					std::cout << "entrez nom du fichier a envoyer :";
					std::cin >> file_name;

					//ecriture du fichier
					FILE* fp = fopen(file_name, "rb");

					while ((length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
					{
						if (send(sock, buffer, length, 0) < 0)
						{
							std::cout << "Send File: %s Failed" << file_name;
							break;
						}
						memset(buffer, 0, BUFFER_SIZE);
					}
					fclose(fp);
					read = !read;
					
					/*memset(buffer, 0, BUFFER_SIZE);
					length = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
					send(sock, buffer, length, 0);*/
					

			        //std::cin.getline(MesDonneeServeur.message,4096);
					//err = send(sock, (char *)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);
					//MesDonneeServeur.read = !MesDonneeServeur.read;
				}
				else
				{
					
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
			}
			closesocket(sock);
		}
	}
	closesocket(server);
	WSACleanup();

}
