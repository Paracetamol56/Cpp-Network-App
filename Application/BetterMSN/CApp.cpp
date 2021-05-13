/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CApp.h"

// Entry point definition
wxDECLARE_APP(CApp);
wxIMPLEMENT_APP(CApp);

/// <summary>
/// Constructor
/// </summary>
CApp::CApp()
{
    m_renderLoopOn = true;
}

/// <summary>
/// Destructor
/// </summary>
CApp::~CApp()
{
    activateIdleLoop(false);
}

/// <summary>
/// Main launcher methode
/// </summary>
/// <returns></returns>
bool CApp::OnInit()
{
    m_mainFrame = new CMain;
    m_mainFrame->Show();

    activateIdleLoop(true);
    return true;
}

void CApp::updateState()
{
    // Network initialization

    // IF SERVER SIDE
    if (m_mainFrame->getSettings()->getStatusIsServer())
    {
        // Change the main window title
        m_mainFrame->SetTitle("Better MSN - Serveur");

        // Socket initializing
        WSAStartup(MAKEWORD(2, 0), &wsa);

        sinserv.sin_family = AF_INET;
        sinserv.sin_addr.s_addr = INADDR_ANY;
        sinserv.sin_port = htons(m_mainFrame->getSettings()->getPort());

        // Socket creation
        server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Socket configuration to listen the port
        bind(server, (SOCKADDR*)&sinserv, sizeof(sinserv));

        // No queue
        listen(server, 0);

        m_error = 0;
        m_listen = false;
    }
    // IF CLIENT SIDE
    else
    {
        // Change the main window title
        m_mainFrame->SetTitle("Better MSN - Client");

        // Socket initializing
        WSAStartup(MAKEWORD(2, 0), &wsa);

        sin.sin_family = AF_INET;
        inet_pton(AF_INET, m_mainFrame->getSettings()->getIPAdressChar(), &sin.sin_addr.s_addr);
        sin.sin_port = htons(m_mainFrame->getSettings()->getPort());

        // Socket creation
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Socket connection
        if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
        {
            wxMessageDialog ErrorEmptyDialog(nullptr, "Socket connection failed", "ERROR", wxICON_EXCLAMATION | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
            ErrorEmptyDialog.ShowModal();
            exit(0);
        }

        m_error = 0;
        m_listen = true;
    }
}


void CApp::activateIdleLoop(bool on)
{
    if (on && !m_renderLoopOn)
    {
        Connect(wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(CApp::OnIdle));
        m_renderLoopOn = true;
    }
    else if (!on && m_renderLoopOn)
    {
        Disconnect(wxEVT_IDLE, wxIdleEventHandler(CApp::OnIdle));
        m_renderLoopOn = false;
    }
}

void CApp::OnIdle(wxIdleEvent& evt)
{
    if (m_renderLoopOn)
    {
        int sinsize = sizeof(sin);
        if ((sock = accept(server, (SOCKADDR*)&sin, &sinsize)) != INVALID_SOCKET)
        {
            if (err > -1)
            {
                if (m_listen == true)
                {
                    CDataStructure ClientData;
                    recv(sock, (char*)&ClientData, sizeof(ClientData), 0);
                    m_mainFrame->addContent(ClientData.m_name, ClientData.m_message);
                    m_listen = !m_listen;
                }
            }
            else
            {
                closesocket(sock);
            }
        }

        evt.RequestMore(); // render continuously, not only once on idle
    }
}

void CApp::OnSend(wxString username, wxString textMessage)
{
    CDataStructure ServerData(username, textMessage);
    
    err = send(sock, (char*)&ServerData, sizeof(ServerData), 0);
    m_listen = !m_listen;
}