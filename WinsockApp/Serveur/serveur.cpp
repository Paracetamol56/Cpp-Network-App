#include <stdio.h>	
#include <fstream>
#include <ws2tcpip.h>
#include <iostream>
#include "Donnee.h"
#include <string>

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

	//Color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int classiqueColor = 15;
	int serveurColor = 55;
	int clientColor = 95;
	int infoColor = 8;



	std::cout << "\nVotre nom : ";
	std::cin >> MesDonneeServeur.name;

	SetConsoleTextAttribute(hConsole, infoColor);
	std::cout << "Pour garder la parole, inserer un '%' dans votre texte \n\n";
	SetConsoleTextAttribute(hConsole, classiqueColor);

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

					memset(MesDonneeServeur.message, 0, sizeof(MesDonneeServeur.message));
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	
					SetConsoleTextAttribute(hConsole, infoColor);
					std::cout << "Entrez 'f' pour envoyer un fichier et 't' si vous voulez envoyer un texte :";
					std::cin >> MesDonneeServeur.TypeCom;
					SetConsoleTextAttribute(hConsole, classiqueColor);

					//envois de la Struct au Client pour qu'il sache le type d'envoie
					err = send(sock, (char*)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);

					//envoie fichier 
					if (MesDonneeServeur.TypeCom == 'f') {
						
						//envoie du nom du fichier
						std::cout << "entrez nom du fichier a envoyer :";
						std::cin >> file_name;

						//ecriture du fichier
						FILE* fp = fopen(file_name, "rb");

						while ((length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
						{
							if (send(sock, buffer, length, 0) < 0)
							{
								std::cout << "Send File: Failed" << file_name;
								break;
							}
							memset(buffer, 0, BUFFER_SIZE);
						}
						fclose(fp);
						
						read = !read;

					}

					//envoie txt
					if (MesDonneeServeur.TypeCom == 't') {

						SetConsoleTextAttribute(hConsole, serveurColor);
						std::cout << MesDonneeServeur.name << " :\n";
						SetConsoleTextAttribute(hConsole, classiqueColor);
						memset(buffer, 0, BUFFER_SIZE);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						std::cin.ignore();
						std::cin.getline(MesDonneeServeur.message, 4096);
						std::cout << "\n";
						err = send(sock, (char *)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);
						std::string chaine = MesDonneeServeur.message;
						if (chaine.find('%') == std::string::npos) {
							read = !read;
						}

					}
				}
				else
				{
					SDonnee DonneeClient;

					while (DonneeClient.TypeCom == NULL) {
						recv(sock, (char*)&DonneeClient, sizeof(DonneeClient), 0);
						
					}

					if (DonneeClient.TypeCom == 'f') {
						std::cout << "entrez nom du fichier a recevoir :";
						std::cin >> file_name;

						FILE* fp = fopen(file_name, "wb");


						memset(buffer, 0, BUFFER_SIZE);
						int length;
						while ((length = recv(sock, buffer, BUFFER_SIZE, 0)) > 0)
						{
							if (fwrite(buffer, sizeof(char), length, fp) < length)
							{
								std::cout << "File: Write Failed" << file_name;
								break;
							}
							memset(buffer, 0, BUFFER_SIZE);

						}
						fclose(fp);
						read = !read;
					}
					if (DonneeClient.TypeCom == 't') {
						if (DonneeClient.message[0] == '\0') {
							recv(sock, (char*)&DonneeClient, sizeof(DonneeClient), 0);
						}
						SetConsoleTextAttribute(hConsole, clientColor);
						std::cout << DonneeClient.name << " :";
						SetConsoleTextAttribute(hConsole, classiqueColor);

						std::cout << DonneeClient.message << "\n\n";
						std::string chaineRecv = DonneeClient.message;
						if (chaineRecv.find('%') == std::string::npos) {
							read = !read;
						}
					}
				}
			}
			closesocket(sock);
		}
	}
	closesocket(server);
	WSACleanup();

}
