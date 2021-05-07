/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Math�o G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#pragma once

#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include <string>

// Memory leaks detection
#include "wxmemdbg.h"

wxDEFINE_EVENT(myID_RADIOBUTTON, wxCommandEvent);
wxDEFINE_EVENT(myID_OKBUTTON, wxCommandEvent);
wxDEFINE_EVENT(myID_CANCELBUTTON, wxCommandEvent);

class CSettings : public wxFrame
{
private:
	// Client/Server
	wxRadioButton* m_clientRadioButton;
	wxRadioButton* m_serverRadioButton;
	bool m_isServer = false;

	// IP adress
	wxTextCtrl* m_ipTextBox[4];
	std::string m_IPAdressInput = "";
	
	// Port
	wxTextCtrl* m_portTextBox;
	int m_portInput = -1;
	
	// Username
	wxTextCtrl* m_usernameTextBox;
	std::string m_usernameInput = "";

public:
	// Public constructor and destructor
	CSettings();
	~CSettings();

public:
	bool getStatusIsServer();
	std::string getIPAdress();
	int getPort();
	std::string getUsername();


private:
	
	// UI events
	void onRadioButton(wxCommandEvent& event);
	void onButtonOk(wxCommandEvent& event);
	void onButtonCancel(wxCommandEvent& event);

	// Checkinf function
	bool isValid();

	wxDECLARE_EVENT_TABLE();
};