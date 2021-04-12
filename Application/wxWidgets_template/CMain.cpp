/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Math�o G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CMain.h"

// Event table
wxBEGIN_EVENT_TABLE(CMain, wxFrame)
EVT_MENU(wxID_EXIT, CMain::OnQuit)
EVT_MENU(myID_SETTINGS, CMain::OnSettings)
EVT_MENU(wxID_ABOUT, CMain::OnAbout)
EVT_BUTTON(myID_SENDBUTTON, CMain::OnButtonSend)
EVT_BUTTON(myID_FILEBUTTON, CMain::OnButtonAddfile)
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

	// ========== GUI GENERATION ========== //
	
	// Sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	m_secondaryOutputSizer = new wxBoxSizer(wxVERTICAL);
	m_secondaryInputSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* secondaryInputButtonSizer = new wxBoxSizer(wxVERTICAL);
	
	// Panels
	m_panelOutput = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100), wxTE_MULTILINE);
	m_panelOutput->SetScrollbar(wxVERTICAL, 0, 10, 100, true);
	m_panelInput = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100), wxTE_MULTILINE);
	mainSizer->Add(m_panelOutput, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(m_panelInput, 0, wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT, 5);
	
	// Text input
	wxTextCtrl* textCtrlBox = new wxTextCtrl(m_panelInput, wxID_ANY, m_inputText, wxDefaultPosition, wxSize(110, 100), wxTE_MULTILINE);
	m_secondaryInputSizer->Add(textCtrlBox, 1, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 5);
	
	// Buttons
	wxButton* buttonSend = new wxButton(m_panelInput, myID_SENDBUTTON, "Send", wxDefaultPosition, wxSize(110, 30), wxTE_MULTILINE);
	wxButton* buttonAddfile = new wxButton(m_panelInput, myID_FILEBUTTON, "Add a file", wxDefaultPosition, wxSize(110, 30), wxTE_MULTILINE);
	secondaryInputButtonSizer->Add(buttonSend, 0, wxEXPAND | wxALL, 5);
	secondaryInputButtonSizer->Add(buttonAddfile, 0, wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT, 5);
	m_secondaryInputSizer->Add(secondaryInputButtonSizer);

	// Sizer structuration
	m_panelOutput->SetSizer(m_secondaryOutputSizer);
	this->SetSizer(mainSizer);
	m_panelInput->SetSizer(m_secondaryInputSizer);
	mainSizer->Layout();

	// ========= END GUI GENERATION ======== //

	// Test content
	/*m_contentList.push_back(new CContent(m_panelOutput, wxID_ANY, "C'est moi le boss", "Hello world", ""));
	m_contentList.push_back(new CContent(m_panelOutput, wxID_ANY, "Non, c'est moi", "world Hello\nPutain, le mec qui a fait ca, il est trop malin\nWoaw on ecrit sur trois lignes !\nEt maintenant une ligne super longue pour voir si le retour de ligne marche bien, donc l� par exemple, je sais pas trop quoi dire donc je pense que je vais m'arreter", ""));
	m_contentList.push_back(new CContent(m_panelOutput, wxID_ANY, "C'est moi le boss", "Voila un fichier", "files/image.jpg"));*/

	updateContent();
}

/// <summary>
/// Destructor
/// </summary>
CMain::~CMain()
{
}

void CMain::updateContent()
{
	m_secondaryOutputSizer->Clear();
	for (CContent* iContent : m_contentList)
	{
		m_secondaryOutputSizer->Add(iContent, 0, wxEXPAND | wxALL, 5);
	}
	Layout();
}

void CMain::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void CMain::OnSettings(wxCommandEvent& WXUNUSED(event))
{
	m_settingsFrame = new CSettings;
	m_settingsFrame->Show();
}

void CMain::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxLaunchDefaultBrowser("https://github.com/Paracetamol56/Cpp-Network-App");
}

void CMain::OnButtonSend(wxCommandEvent& event)
{
	if (m_inputText.empty())
	{
		wxMessageDialog WarnEmptyDialog(nullptr, "You should enter a message", "WARNING", wxOK | wxCENTER, wxDefaultPosition);
		WarnEmptyDialog.ShowModal();
	}
	else
	{
		m_contentList.push_back(new CContent(m_panelOutput, wxID_ANY, "C'est moi le boss", m_inputText, ""));
		updateContent();
	}
}

void CMain::OnButtonAddfile(wxCommandEvent& event)
{

}
