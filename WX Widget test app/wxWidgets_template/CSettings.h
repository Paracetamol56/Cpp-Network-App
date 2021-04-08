/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#pragma once

#include "wx/wx.h"
#include "wx/utils.h"

wxDEFINE_EVENT(myID_OKBUTTON, wxCommandEvent);
wxDEFINE_EVENT(myID_CANCELBUTTON, wxCommandEvent);

class CSettings : public wxFrame
{
private:
	
	// IP adress
	wxString m_IPAdress01Input = "";
	wxString m_IPAdress02Input = "";
	wxString m_IPAdress03Input = "";
	wxString m_IPAdress04Input = "";
	
	// Port
	wxString m_portInput = "";
	
	// Username
	wxString m_usernameInput = "";

public:
	
	// Public constructor and destructor
	CSettings();
	~CSettings();

private:
	
	// UI events
	void onButtonOk(wxCommandEvent& event);
	void onButtonCancel(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};