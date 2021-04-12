/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CSettings.h"

// Event table
wxBEGIN_EVENT_TABLE(CSettings, wxFrame)
EVT_BUTTON(myID_OKBUTTON, CSettings::onButtonOk)
EVT_BUTTON(myID_CANCELBUTTON, CSettings::onButtonCancel)
wxEND_EVENT_TABLE()

CSettings::CSettings() : wxFrame(nullptr, wxID_ANY, "Settings", wxPoint(-1, -1), wxSize(290, 170), wxDEFAULT_FRAME_STYLE &~(wxRESIZE_BORDER))
{
	// ========== GUI GENERATION ========== //
	
	// Panel
	wxPanel* panelGlobal = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500), wxTE_MULTILINE);

	// Sizer
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* flexSizer = new wxFlexGridSizer(3, 2, 5, 30);
	wxBoxSizer* ipSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	
	// Static text labels
	wxStaticText* ipLabel = new wxStaticText(panelGlobal, -1, wxT("Destination IP"));
	wxStaticText* portLabel = new wxStaticText(panelGlobal, -1, wxT("Port"));
	wxStaticText* usernameLable = new wxStaticText(panelGlobal, -1, wxT("Username"));
	
	// IP inputs
	for (size_t i = 0; i < 3; i++)
	{
		m_ipTextBox[i] = new wxTextCtrl(panelGlobal, wxID_ANY, "", wxDefaultPosition, wxSize(30, -1));
	}
	wxStaticText* ipSemicolon1 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon2 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon3 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	
	// Add everything to the sizer
	ipSizer->Add(m_ipTextBox[0], 1, wxEXPAND);
	ipSizer->Add(ipSemicolon1);
	ipSizer->Add(m_ipTextBox[1], 1, wxEXPAND);
	ipSizer->Add(ipSemicolon2);
	ipSizer->Add(m_ipTextBox[2], 1, wxEXPAND);
	ipSizer->Add(ipSemicolon3);
	ipSizer->Add(m_ipTextBox[3], 1, wxEXPAND);
	
	// Port input
	wxTextCtrl* portTextBox = new wxTextCtrl(panelGlobal, -1);
	
	// Username input
	wxTextCtrl* usernameTextBox = new wxTextCtrl(panelGlobal, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));
	
	// Buttons
	wxButton* buttonOk = new wxButton(panelGlobal, myID_OKBUTTON, "OK", wxDefaultPosition, wxSize(110, 30));
	wxButton* buttonCancel = new wxButton(panelGlobal, myID_CANCELBUTTON, "Cancel", wxDefaultPosition, wxSize(110, 30));
	buttonSizer->Add(buttonCancel, 1, wxALL, 5);
	buttonSizer->Add(buttonOk, 1, wxALL, 5);

	// Add everything to the sizer
	flexSizer->Add(ipLabel);
	flexSizer->Add(ipSizer, 1, wxEXPAND);
	flexSizer->Add(portLabel);
	flexSizer->Add(portTextBox, 1, wxEXPAND);
	flexSizer->Add(usernameLable);
	flexSizer->Add(usernameTextBox, 1, wxEXPAND);
	mainSizer->Add(flexSizer, 1, wxEXPAND | wxALL, 10);
	mainSizer->Add(buttonSizer, 1, wxEXPAND);

	panelGlobal->SetSizer(mainSizer);
	mainSizer->Layout();

	// ======== END GUI GENERATION ======== //
}

CSettings::~CSettings()
{

}



void CSettings::onButtonOk(wxCommandEvent& WXUNUSED(event))
{
	for (size_t i = 0; i < 3; i++)
	{
		m_IPAdressInput[i] = m_ipTextBox[i]->GetValue();
	}
	Close(true);
}

void CSettings::onButtonCancel(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

bool CSettings::isValid()
{
	// Checking for errors in IP adress
	wxString IPAdressToTest[4];

	for (size_t i = 0; i < 3; i++)
	{
		IPAdressToTest[i] = m_ipTextBox[i]->GetValue();
	}
	
	for (wxString iIP : IPAdressToTest)
	{
		if (iIP.size() > 3)
		{
			wxMessageDialog WarnEmptyDialog(nullptr, "The IP Adress is not valid", "WARNING", wxICON_EXCLAMATION | wxOK_DEFAULT | wxCENTER, wxDefaultPosition);
			WarnEmptyDialog.ShowModal();
			return false;
		}
	}
	return true;
}
