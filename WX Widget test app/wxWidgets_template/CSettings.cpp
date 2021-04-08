/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CSettings.h"

// Event table
wxBEGIN_EVENT_TABLE(CSettings, wxFrame)
EVT_BUTTON(myID_OKBUTTON, CSettings::onButtonOk)
EVT_BUTTON(myID_CANCELBUTTON, CSettings::onButtonCancel)
wxEND_EVENT_TABLE()

CSettings::CSettings() : wxFrame(nullptr, wxID_ANY, "Settings", wxPoint(-1, -1), wxSize(290, 170), wxDEFAULT_FRAME_STYLE &~(wxRESIZE_BORDER))
{
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
	wxTextCtrl* ipTextBox1 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress01Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox2 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress02Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox3 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress03Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox4 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress04Input, wxDefaultPosition, wxSize(30, -1));
	wxStaticText* ipSemicolon1 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon2 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon3 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	ipSizer->Add(ipTextBox1, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon1);
	ipSizer->Add(ipTextBox2, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon2);
	ipSizer->Add(ipTextBox3, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon3);
	ipSizer->Add(ipTextBox4, 1, wxEXPAND);
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
	Centre();
}

CSettings::~CSettings()
{

}

void CSettings::onButtonOk(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void CSettings::onButtonCancel(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}
