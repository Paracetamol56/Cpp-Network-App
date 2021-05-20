/*
 * Created on Fri May 21 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include <stdio.h>	
#include <fstream>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#include "Data.h"

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

// #define N 1000
#define BUFFER_SIZE 1024 
#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32") 

int main()
{
	std::cout << "\t\t\t\tBienvenue sur BETTER MSN.\n\n";

	// ################## Network objects ################## //

	WSADATA wsa;									// Structure containing information about the Windows Sockets implementation
	WSAStartup(MAKEWORD(2, 0), &wsa);				// Initiates the use of the Winsock DLL

	SOCKET sock;									// Connection socket
	SOCKADDR_IN sin;								// Structure containing information about the 'sock' socket

	// ##################################################### //

	// ################# Connection inputs ################# //

	// IP Address
	char ip[15];
	std::cout << "Ip : ";
	std::cin >> ip;									// Should be between 1.1.1.1 and 254.254.254.254

	int port;
	std::cout << "\nPort : ";
	std::cin >> port;								// Should be between 1024 and 49150

	sin.sin_family = AF_INET;						// Set the family
	inet_pton(AF_INET, ip, &sin.sin_addr.s_addr);	// Set thi IP adress
	sin.sin_port = htons(port);						// Set the port

	// Socket creation
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Socket connection
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		std::cout << "La connection a echoue\n";

		system("PAUSE");
		exit(0);
	}

	// ##################################################### //

	// ############## Communication variables ############## //

	int err = 0;									// Keep the error code
	SData ClientData;								// Data structure of a message
	bool read = true;								// Writing/Reading state (true = listening for client message)
	char buffer[BUFFER_SIZE];						// Size of file chunk send at a time

	char file_name[1000];							// File path in case of file sendin
	int length = 0;									// Index of file chunk to send

	// Set the consol mode to color support
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Color codes	used							== DEFAULT VALUES ==
	const int classiqueColor = 15;					// (15) - White
	const int serveurColor = 55;					// (55) - Blue
	const int clientColor = 95;						// (95) - Purple
	const int infoColor = 8;						// (8)  - Gray

	// ##################################################### //

	// ############### Other Information UI ################ //

	std::cout << "\nVotre nom : ";
	std::cin >> ClientData.m_username;

	SetConsoleTextAttribute(hConsole, infoColor);
	std::cout << "Pour garder la parole, inserer un '%' dans votre texte \n\n";
	SetConsoleTextAttribute(hConsole, classiqueColor);

	// ##################################################### //

	// ##################### Main loop ##################### //

	while (err > -1)
	{

		// ################### Sending state ################### //

		if (read == false)
		{
			// Empty the old message structure
			memset(ClientData.m_message, 0, sizeof(ClientData.m_message));
			// Set the consol to support getline
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

			// Define the sending kind
			SetConsoleTextAttribute(hConsole, infoColor);
			std::cout << "Entrez 'f' pour envoyer un fichier et 't' si vous voulez envoyer un texte :";
			std::cin >> ClientData.m_type;
			SetConsoleTextAttribute(hConsole, classiqueColor);

			// Send the message structure to the client (to let it know the sending kind)
			err = send(sock, (char*)&ClientData, sizeof(ClientData), 0);

			// ==== File sending ==== //

			if (ClientData.m_type == 'f')
			{
				
				// Send file name (usefull to inform about extention)
				std::cout << "entrez nom du fichier a envoyer :";
				std::cin >> file_name;
				err = send(sock, file_name, sizeof(file_name), 0);


				// Send the file
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
				
				// Switch the state
				read = !read;
			}

			// ==== Text Sending ==== //

			if (ClientData.m_type == 't')
			{
				// Display the username of the sender
				SetConsoleTextAttribute(hConsole, clientColor);
				std::cout << ClientData.m_username << " :\n";
				SetConsoleTextAttribute(hConsole, classiqueColor);

				// Message input
				memset(buffer, 0, BUFFER_SIZE);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				std::cin.ignore();
				std::cin.getline(ClientData.m_message, 4096);
				std::cout << "\n";

				// Send the message
				err = send(sock, (char*)&ClientData, sizeof(ClientData), 0);

				// If '%' is in the message : flip the state
				std::string chaine = ClientData.m_message;

				if (chaine.find('%') == std::string::npos)
				{
					read = !read;
				}
			}
		}

		// ################## Receiving state ################## //

		else
		{
			// New SData structure to store the server message
			SData ServerData;
			// Wait for the sending kind
			while (ServerData.m_type == NULL)
			{
				recv(sock, (char*)&ServerData, sizeof(ServerData), 0);
			}

			// ==== File receiving ==== //

			if (ServerData.m_type == 'f')
			{
				// Get file name
				recv(sock, file_name, sizeof(file_name), 0);

				FILE* fp = fopen(file_name, "wb");

				// Initiate buffer and chunk index
				memset(buffer, 0, BUFFER_SIZE);
				int length = 1;
				
				// File reception loop
				while (length >0)
				{
					length = recv(sock, buffer, BUFFER_SIZE, 0);
					if (fwrite(buffer, sizeof(char), length, fp) < length)
					{
						std::cout << "File: Write Failedn" << file_name;
						break;
					}
					memset(buffer, 0, BUFFER_SIZE);

					// Checks if the size of the reception is equal to the maximum size
					// If false then it's the last buffer of the file
					if (length < BUFFER_SIZE)
					{
						length = 0;
						SetConsoleTextAttribute(hConsole, infoColor);
						std::cout << "fichier : " << file_name << " recu \n";
						SetConsoleTextAttribute(hConsole, classiqueColor);
					}

				}
				fclose(fp);

				// Switch the state
				read = !read;
			}

			// ==== File receiving ==== //

			if (ServerData.m_type == 't')
			{
				// Receiving the message structure
				if (ServerData.m_message[0] == '\0')
				{
					recv(sock, (char*)&ServerData, sizeof(ServerData), 0);
				}

				// Display the username of the sender
				SetConsoleTextAttribute(hConsole, serveurColor);
				std::cout << ServerData.m_username << " :";
				SetConsoleTextAttribute(hConsole, classiqueColor);

				// Display the message
				std::cout << ServerData.m_message << "\n\n";
				std::string chaineRecv = ServerData.m_message;

				// Looking for the character '%' in the buffer in order to know if the client wants to keep speaking
				if (chaineRecv.find('%') == std::string::npos)
				{
					read = !read;
				}
			}
		}
	}
	// End of the connection
	closesocket(sock);
	WSACleanup();

	return 0;
}
