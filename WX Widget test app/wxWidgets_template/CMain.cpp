/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CMain.h"

// Event table
wxBEGIN_EVENT_TABLE(CMain, wxFrame)
EVT_MENU(wxID_EXIT, CMain::OnQuit)
EVT_MENU(myID_SETTINGS, CMain::OnSettings)
EVT_MENU(wxID_ABOUT, CMain::OnAbout)
EVT_BUTTON(myID_SENDBUTTON, CMain::OnAbout)
EVT_BUTTON(myID_FILEBUTTON, CMain::OnAbout)
wxEND_EVENT_TABLE()

/// <summary>
/// Constructor with PARENT, ID, TITLE
/// </summary>
CMain::CMain() : wxFrame(nullptr, wxID_ANY, "WX Window template", wxPoint(30, 30), wxSize(615, 865))
{
	// ======== MENU BAR CREATION ========//
	// Main menu bar
	m_mainMenuBar = new wxMenuBar();
	// Menus creation
	m_fileMenu = new wxMenu();
	m_helpMenu = new wxMenu();
	
	SetMenuBar(m_mainMenuBar);

	m_mainMenuBar->Append(m_fileMenu, _T("&File"));
	m_mainMenuBar->Append(m_helpMenu, _T("&Help"));
	// File menu
	m_fileMenu->Append(myID_SETTINGS, _T("Connection Settigs\tCtrl+T"));
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT, _T("&Quit"));
	// Help menu
	m_helpMenu->Append(wxID_ABOUT, _T("&About\tF1"));

	// ========== GUI CREATION ========== //
	// Sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* secondaryInputSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* secondaryInputButtonSizer = new wxBoxSizer(wxVERTICAL);
	// Panels
	wxPanel* panelOutput = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100), wxTE_MULTILINE);
	wxPanel* panelInput = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100), wxTE_MULTILINE);
	mainSizer->Add(panelOutput, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(panelInput, 0,wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT, 5);
	// Text input
	wxTextCtrl* textCtrlBox = new wxTextCtrl(panelInput, wxID_ANY, m_inputText, wxDefaultPosition, wxSize(110, 100), wxTE_MULTILINE);
	secondaryInputSizer->Add(textCtrlBox, 1, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 5);
	// Buttons
	wxButton* buttonSend = new wxButton(panelInput, wxID_ANY, "Send", wxDefaultPosition, wxSize(110, 30), wxTE_MULTILINE);
	wxButton* buttonAddfile = new wxButton(panelInput, wxID_ANY, "Add a file", wxDefaultPosition, wxSize(110, 30), wxTE_MULTILINE);
	secondaryInputButtonSizer->Add(buttonSend, 0, wxEXPAND | wxALL, 5);
	secondaryInputButtonSizer->Add(buttonAddfile, 0, wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT, 5);
	secondaryInputSizer->Add(secondaryInputButtonSizer);

	// Sizer structuration
	this->SetSizer(mainSizer);
	panelInput->SetSizer(secondaryInputSizer);
	mainSizer->Layout();
}

/// <summary>
/// Destructor
/// </summary>
CMain::~CMain()
{
}


wxString CMain::getInputData()
{
	if (m_inputText.IsEmpty() == false)
	{
		if (m_inputFilePath.IsEmpty() == false)
		{
			// The '\f' is use specify that a file path is following
			m_inputText = m_inputText + '\f' + m_inputFilePath;
		}
		return(m_inputText);
	}
	return("");
}

void CMain::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void CMain::OnSettings(wxCommandEvent& WXUNUSED(event))
{

}

void CMain::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxLaunchDefaultBrowser("https://github.com/Paracetamol56/Cpp-Network-App");
}

void CMain::OnButtonSend(wxCommandEvent& event)
{
}

void CMain::OnButtonAddfile(wxCommandEvent& event)
{
}
