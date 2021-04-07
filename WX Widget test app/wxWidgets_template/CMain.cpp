/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CMain.h"

/// <summary>
/// Constructor with PARENT, ID, TITLE
/// </summary>
CMain::CMain() : wxFrame(nullptr, wxID_ANY, "WX Window template", wxPoint(30, 30), wxSize(1280, 720))
{
	// Menu bar creation
	m_mainMenuBar = new wxMenuBar();
	// Menus creation
	m_fileMenu = new wxMenu();
	m_helpMenu = new wxMenu();

	SetMenuBar(m_mainMenuBar);

	m_mainMenuBar->Append(m_fileMenu, _T("&File"));
	m_mainMenuBar->Append(m_helpMenu, _T("&Help"));
	// File menu
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT, _T("&Quit"));
	// Help menu
	m_helpMenu->Append(wxID_ABOUT, _T("&About"));
}

/// <summary>
/// Destructor
/// </summary>
CMain::~CMain()
{
}
