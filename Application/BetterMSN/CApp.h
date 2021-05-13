/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#pragma once

#include <ws2tcpip.h>
#include <wx/wx.h>
#include <stdio.h>
#include "CMain.h"
#include "CDataStructure.h"

// Memory leaks detection
#include "wxmemdbg.h"

#pragma comment(lib,"ws2_32.lib")

#define _WINSOCKAPI_ // This is to avoid conflict between winsock2 an wxWidget

/// <summary>
/// Main app class
/// </summary>
class CApp : public wxApp
{
private:

	bool m_renderLoopOn;
	bool m_listen;
	int m_error = 0;

public:
	
	// Public constructor and destructor
	CApp();
	~CApp();

private:
	
	// Private data to store the main frame
	CMain* m_mainFrame = nullptr;

public:
	
	// Launcher methode
	virtual bool OnInit();
	// Update server/client state
	void updateState();
	// Idle loop handler
	void activateIdleLoop(bool on);
	// Idle loop
	void OnIdle(wxIdleEvent& evt);
	// Sending function
	void OnSend(wxString username, wxString textMessage);

private:
	
	// Network stuff
	WSADATA wsa;

	int m_sinsize;
	int err = 0;
	CDataStructure* m_transfertData;

	// Socket initialisation
	SOCKET server;
	SOCKET sock;

	SOCKADDR_IN sinserv;
	SOCKADDR_IN sin;
	
};
