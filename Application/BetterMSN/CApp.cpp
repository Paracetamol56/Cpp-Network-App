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

    
    // IF SERVER SIDE
    if (m_mainFrame->getSettings()->getStatusIsServer())
    {
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
    }
    // IF CLIENT SIDE
    else
    {
        //todo
    }
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
        // THINGS HERE
        evt.RequestMore(); // render continuously, not only once on idle
    }
}
