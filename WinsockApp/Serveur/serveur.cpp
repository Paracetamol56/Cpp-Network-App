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

#define BUFFER_SIZE 1024 
#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32") 

int main()
{
	std::cout << "\t\t\t\tBienvenue sur BETTER MSN.\n\n";

	// ################## Network objects ################## //

	WSADATA wsa;									// Structure containing information about the Windows Sockets implementation
	WSAStartup(MAKEWORD(2, 0), &wsa);				// Initiates the use of the Winsock DLL

	SOCKET server;									// Server socker
	SOCKET sock;									// Socket to accept the external connection

	SOCKADDR_IN sinserv;							// Structure containing information about the 'server' socket
	SOCKADDR_IN sin;								// Structure containing information about the 'sock' socket (initiate empty)

	// ##################################################### //

	// ################# Connection inputs ################# //

	// Port input
	int port;
	std::cout << "Port : ";
	std::cin >> port;								// Should be between 1024 and 49150

	// sinserv initialization
	sinserv.sin_family = AF_INET;					// Set the family
	sinserv.sin_addr.s_addr = INADDR_ANY;			// Set thi IP adress
	sinserv.sin_port = htons(port);					// Set the port

	// Socket creation
	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Socket configuration to listen the port
	bind(server, (SOCKADDR*)&sinserv, sizeof(sinserv));

	//pas de file d'attente
	listen(server, 0);

	// ##################################################### //

	// ############## Communication variables ############## //

	int sinsize;									// Size of sin structure
	int err = 0;									// Keep the error code
	SData ServerData;								// Data structure of a message
													// (This structure is modified and send for each new message)

	bool read = false;								// Writing/Reading state (true = listening for client message)

	char file_name[1000];							// File path in case of file sendin
	int length;										// Index of file chunk to send
	char buffer[BUFFER_SIZE];						// Size of file chunk send at a time

	// Set the consol mode to color support
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Color codes	used							== DEFAULT VALUES ==
	const int classiqueColor = 15;					// (15) - White
	const int serveurColor = 55;					// (55) - Blue
	const int clientColor = 95;						// (95) - Purple
	const int infoColor = 8;						// (8)  - Gray

	// ##################################################### //

	// ############### Other Information UI ################ //

	// Username input
	std::cout << "\nVotre nom : ";
	std::cin >> ServerData.m_username;

	// Display informative message
	SetConsoleTextAttribute(hConsole, infoColor);
	std::cout << "Pour garder la parole, inserer un '%' dans votre texte \n\n";
	SetConsoleTextAttribute(hConsole, classiqueColor);

	// ##################################################### //

	// ##################### Main loop ##################### //

	while (1)
	{
		sinsize = sizeof(sin);						// Update sinsize

		// Connection acceptance (or not)
		if ((sock = accept(server, (SOCKADDR*)&sin, &sinsize)) != INVALID_SOCKET)
		{
			while (err > -1)
			{

				// ################### Sending state ################### //

				if (read == false)
				{
					// Empty the old message structure
					memset(ServerData.m_message, 0, sizeof(ServerData.m_message));
					// Set the consol to support getline
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

					// Define the sending kind
					SetConsoleTextAttribute(hConsole, infoColor);
					std::cout << "Entrez 'f' pour envoyer un fichier et 't' si vous voulez envoyer un texte :";
					std::cin >> ServerData.m_type;
					SetConsoleTextAttribute(hConsole, classiqueColor);

					// Send the message structure to the client (to let it know the sending kind)
					err = send(sock, (char*)&ServerData, sizeof(ServerData), 0);

					// ==== File sending ==== //

					if (ServerData.m_type == 'f')
					{

						// Send file name (usefull to inform about extention)
						std::cout << "entrez nom du fichier a envoyer :";
						std::cin >> file_name;
						err = send(sock, file_name, sizeof(file_name), 0);

						// Send the file
						FILE* fp = fopen(file_name, "rb");

						// Subdivide the file in chunks
						while ((length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
						{
							if (send(sock, buffer, length, 0) < 0)
							{
								// In case of error
								std::cout << "Send File: Failed" << file_name;
								break;
							}
							// Reset the buffer
							memset(buffer, 0, BUFFER_SIZE);
						}
						fclose(fp);

						// Switch the state
						read = !read;

					}

					// ==== Text Sending ==== //

					if (ServerData.m_type == 't')
					{
						// Display the username of the sender
						SetConsoleTextAttribute(hConsole, serveurColor);
						std::cout << ServerData.m_username << " :\n";
						SetConsoleTextAttribute(hConsole, classiqueColor);

						// Message input
						memset(buffer, 0, BUFFER_SIZE);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						std::cin.ignore();
						std::cin.getline(ServerData.m_message, 4096);
						std::cout << "\n";

						// Send the message
						err = send(sock, (char*)&ServerData, sizeof(ServerData), 0);

						// If '%' is in the message : flip the state
						std::string chaine = ServerData.m_message;

						if (chaine.find('%') == std::string::npos)
						{
							read = !read;
						}

					}
				}

				// ################## Receiving state ################## //

				else
				{
					// New SData structure to store the client message
					SData ClientData;
					// Wait for the sending kind
					while (ClientData.m_type == '\0')
					{
						recv(sock, (char*)&ClientData, sizeof(ClientData), 0);
					}

					// ==== File receiving ==== //

					if (ClientData.m_type == 'f')
					{
						// Get file name
						recv(sock, file_name, sizeof(file_name), 0);

						FILE* fp = fopen(file_name, "wb");

						// Initiate buffer and chunk index
						memset(buffer, 0, BUFFER_SIZE);
						int length = 1;

						// File reception loop
						while (length > 0)
						{
							length = recv(sock, buffer, BUFFER_SIZE, 0);
							if (fwrite(buffer, sizeof(char), length, fp) < length)
							{
								std::cout << "File: Write Failed" << file_name;
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

					if (ClientData.m_type == 't')
					{
						// Receiving the message structure
						recv(sock, (char*)&ClientData, sizeof(ClientData), 0);

						// Display the username of the sender
						SetConsoleTextAttribute(hConsole, clientColor);
						std::cout << ClientData.m_username << " :";
						SetConsoleTextAttribute(hConsole, classiqueColor);

						// Display the message
						std::cout << ClientData.m_message << "\n\n";
						std::string chaineRecv = ClientData.m_message;

						// Looking for the character '%' in the buffer in order to know if the client wants to keep speaking
						if (chaineRecv.find('%') == std::string::npos)
						{
							read = !read;
						}
					}
				}
			}
			closesocket(sock);
		}
		// End of the connection
		closesocket(server);
		WSACleanup();
	}

	return 0;
}
