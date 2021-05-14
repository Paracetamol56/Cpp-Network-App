/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CApp.h"

#pragma comment(lib, "Ws2_32.lib")

// Entry point definition
wxIMPLEMENT_APP(CApp);
wxDECLARE_APP(CApp);

/// <summary>
/// Constructor
/// </summary>
CApp::CApp()
{
    // Socket initializing
    WSAStartup(MAKEWORD(2, 0), &wsa);
}

/// <summary>
/// Destructor
/// </summary>
CApp::~CApp()
{
    closesocket(sock);
    WSACleanup();
}

/// <summary>
/// Main launcher methode
/// </summary>
/// <returns>
/// Always true
/// </returns>
bool CApp::OnInit()
{
    m_mainFrame = new CMain;
    m_mainFrame->Show();

    m_mainFrame->getSettings()->atach(this);
    m_mainFrame->atach(this);

    return true;
}

/// <summary>
/// Update the state (server/client) when the Ok button is pressed in settings
/// </summary>
void CApp::update(Notification notif)
{
    switch (notif)
    {
        // CASE : update the state (Client/Server)
    case Notification::Notification_State:
    {
        // Destroying the old socket

        // closesocket(sock);

        // Network initialization

        // IF SERVER SIDE
        if (m_mainFrame->getSettings()->getStatusIsServer())
        {
            // Change the main window title
            m_mainFrame->SetTitle("Better MSN - Serveur");

            // Socket creation
            sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

            // Create the structure describing various Server parameters
            sin.sin_family = AF_INET;
            sin.sin_addr.s_addr = INADDR_ANY;
            sin.sin_port = htons(m_mainFrame->getSettings()->getPort());

            // Socket configuration to listen the port
            if (bind(sock, (SOCKADDR*)&sin, sizeof(sin)) < 0)
            {
                wxMessageDialog ErrorEmptyDialog(nullptr, "Socket bind failed", "ERROR", wxICON_STOP | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
                ErrorEmptyDialog.ShowModal();
            }

            // No queue
            listen(sock, 0);

   
            m_listen = false;
        }
        // IF CLIENT SIDE
        else
        {
            // Change the main window title
            m_mainFrame->SetTitle("Better MSN - Client");

            // Socket creation
            sock = socket(AF_INET, SOCK_STREAM, 0);

            // Create the structure describing various Server parameters
            sin.sin_family = AF_INET;
            inet_pton(AF_INET, m_mainFrame->getSettings()->getIPAdressChar(), &sin.sin_addr.s_addr);
            sin.sin_port = htons(m_mainFrame->getSettings()->getPort());

            // Socket connection
            if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0 )
            {
                wxMessageDialog ErrorEmptyDialog(nullptr, "Socket connection failed", "ERROR", wxICON_STOP | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
                ErrorEmptyDialog.ShowModal();
            }

            m_listen = true;
            Listen();
        }
    }
        break;
        // CASE : send a message
    case Notification::Notification_Send:
        if(m_listen == false)
        {
            if (sock == INVALID_SOCKET)
            {
                wxMessageDialog ErrorEmptyDialog(nullptr, "Invalid socket", "ERROR", wxICON_STOP | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
                ErrorEmptyDialog.ShowModal();
            }
            else
            {
                CDataStructure transfertData(m_mainFrame->getSettings()->getUsername(), m_mainFrame->getInputText());

                if (send(sock, (char*)&transfertData, 1000, 0) < 0)
                {
                    wxMessageDialog ErrorEmptyDialog(nullptr, "Send failed", "ERROR", wxICON_WARNING | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
                    ErrorEmptyDialog.ShowModal();
                }
            }
        }
        else
        {
            wxMessageDialog ErrorEmptyDialog(nullptr, "This is not your turn", "ERROR", wxICON_WARNING | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
            ErrorEmptyDialog.ShowModal();
        }
        break;
    default:
        break;
    }
}

void CApp::Listen()
{
    if (m_listen)
    {
        if (m_mainFrame->getSettings()->getStatusIsServer())
        {
            SOCKET server;
            SOCKADDR_IN sinserv;

            m_sinsize = sizeof(sinserv);

            if ((server = accept(sock, (SOCKADDR*)&sinserv, &m_sinsize)) != INVALID_SOCKET)
            {
                CDataStructure ClientData;
                recv(server, (char*)&ClientData, sizeof(ClientData), 0);
                m_mainFrame->addContent(ClientData.m_name, ClientData.m_message);
                m_listen = !m_listen;
            }
        }
        else
        {
            m_sinsize = sizeof(sin);

            CDataStructure ServerData;
            recv(sock, (char*)&ServerData, sizeof(ServerData), 0);
            m_mainFrame->addContent(ServerData.m_name, ServerData.m_message);
            m_listen = !m_listen;
        }
    }
}
