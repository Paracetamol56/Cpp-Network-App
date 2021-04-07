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
	// Menu bar creation
	m_mainMenuBar = new wxMenuBar();
	// Menus creation
	m_fileMenu = new wxMenu();
	m_helpMenu = new wxMenu();
	// UIs creation
	m_panelOutput = new wxPanel(this, wxID_ANY, wxPoint(5, 5), wxSize(590, 715));
	m_panelInput = new wxPanel(this, wxID_ANY, wxPoint(5, 725), wxSize(590, 75));
	m_buttonSend = new wxButton(m_panelInput, wxID_ANY, "Envoyer", wxPoint(475, 5), wxSize(110, 30));
	m_buttonAddfile = new wxButton(m_panelInput, wxID_ANY, "Ajouter un fichier", wxPoint(475, 40), wxSize(110, 30));
	m_textBox = new wxTextCtrl();

	SetMenuBar(m_mainMenuBar);

	m_mainMenuBar->Append(m_fileMenu, _T("&File"));
	m_mainMenuBar->Append(m_helpMenu, _T("&Help"));
	// File menu
	m_fileMenu->Append(myID_SETTINGS, _T("Connection Settigs\tCtrl+T"));
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT, _T("&Quit"));
	// Help menu
	m_helpMenu->Append(wxID_ABOUT, _T("&About\tF1"));
}

/// <summary>
/// Destructor
/// </summary>
CMain::~CMain()
{
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
