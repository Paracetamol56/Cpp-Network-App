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
	int length;
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
				if (read == false) //mode d'envoie
				{

					memset(MesDonneeServeur.message, 0, sizeof(MesDonneeServeur.message));
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

					//définition du type d'envoie 
					SetConsoleTextAttribute(hConsole, infoColor);
					std::cout << "Entrez 'f' pour envoyer un fichier et 't' si vous voulez envoyer un texte :";
					std::cin >> MesDonneeServeur.TypeCom;
					SetConsoleTextAttribute(hConsole, classiqueColor);

					//envoie de la Struct au Client pour qu'il sache le type d'envoie
					err = send(sock, (char*)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);

					//envoie fichier 
					if (MesDonneeServeur.TypeCom == 'f') {

						//envoie du nom du fichier
						std::cout << "entrez nom du fichier a envoyer :";
						std::cin >> file_name;
						err = send(sock, file_name, sizeof(file_name), 0);

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

					/*	char KeepTalking ;
						SetConsoleTextAttribute(hConsole, infoColor);
						std::cout << "Voulez-vous garder la parole (y/n) :";
						std::cin >> KeepTalking;
						SetConsoleTextAttribute(hConsole, classiqueColor);

						send(sock, (char*)&KeepTalking, sizeof(KeepTalking), 0);

						if (KeepTalking == 'n') {
							
						}*/

						read = !read;

					}

					//envoie txt
					if (MesDonneeServeur.TypeCom == 't') {
						//affichage du nom de l'utilisateur
						SetConsoleTextAttribute(hConsole, serveurColor);
						std::cout << MesDonneeServeur.name << " :\n";
						SetConsoleTextAttribute(hConsole, classiqueColor);

						//input message
						memset(buffer, 0, BUFFER_SIZE);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						std::cin.ignore();
						std::cin.getline(MesDonneeServeur.message, 4096);
						std::cout << "\n";

						//envoie du message
						err = send(sock, (char*)&MesDonneeServeur, sizeof(MesDonneeServeur), 0);

						//echange de parole ou pas
						std::string chaine = MesDonneeServeur.message;

						if (chaine.find('%') == std::string::npos) {
							read = !read;
						}

					}
				}
				else  //mode de réception
				{
					SDonnee DonneeClient;
					//attente du type d'envoie
					while (DonneeClient.TypeCom == NULL) {
						recv(sock, (char*)&DonneeClient, sizeof(DonneeClient), 0);

					}

					if (DonneeClient.TypeCom == 'f') {
						//reception du nom du fichier
						recv(sock, file_name, sizeof(file_name), 0);

						FILE* fp = fopen(file_name, "wb");


						memset(buffer, 0, BUFFER_SIZE);
						int length = 1;

						//boucle de reception du fichier
						while (length > 0)
						{
							length = recv(sock, buffer, BUFFER_SIZE, 0);
							if (fwrite(buffer, sizeof(char), length, fp) < length)
							{
								std::cout << "File: Write Failedn" << file_name;
								break;
							}
							memset(buffer, 0, BUFFER_SIZE);

							//vérifie si la taille de ce qui est reçu est égale a la taille max si c'est faux alors c'est le dernier buffer du fichier
							if (length < BUFFER_SIZE) {
								length = 0;
								SetConsoleTextAttribute(hConsole, infoColor);
								std::cout << "fichier : " << file_name << " recu \n";
								SetConsoleTextAttribute(hConsole, classiqueColor);
							}

							/*char ClientKeepTalking = NULL;

							while (ClientKeepTalking == NULL) {
								recv(sock, (char*)ClientKeepTalking, sizeof(ClientKeepTalking), 0);
							}

							if (ClientKeepTalking == 'n')
							{
								read = !read;
							}
							else
							{
								SetConsoleTextAttribute(hConsole, infoColor);
								std::cout << DonneeClient.name << " garde la parole. \n";
								SetConsoleTextAttribute(hConsole, classiqueColor);
							}
							ClientKeepTalking = NULL;*/

						}
						fclose(fp);
						read = !read;
					}
					if (DonneeClient.TypeCom == 't') {

						//condition pour ce mettre en attente de texte
						if (DonneeClient.message[0] == '\0') {
							recv(sock, (char*)&DonneeClient, sizeof(DonneeClient), 0);
						}

						//affichage du nom du correspondant
						SetConsoleTextAttribute(hConsole, clientColor);
						std::cout << DonneeClient.name << " :";
						SetConsoleTextAttribute(hConsole, classiqueColor);

						//affichage du message envoyé par le correspondant
						std::cout << DonneeClient.message << "\n\n";
						std::string chaineRecv = DonneeClient.message;

						//cherche dans le buffer le caractère '%' afin de savoir si l'utilisateur veut garder la parole
						if (chaineRecv.find('%') == std::string::npos) {
							read = !read;
						}
					}
					
				}
				
			}
			closesocket(sock);
		}
		closesocket(server);
		WSACleanup();

	}
}
