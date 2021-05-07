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
wxIMPLEMENT_APP(CApp);

/// <summary>
/// Constructor
/// </summary>
CApp::CApp()
{
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
    m_frame01 = new CMain;
    m_frame01->Show();

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
