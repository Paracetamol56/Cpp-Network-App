/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Math�o G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#pragma once

#include "CSettings.h"
#include "CContent.h"
#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/utils.h>
#include <wx/filedlg.h>
#include <list>

wxDEFINE_EVENT(myID_SETTINGS, wxCommandEvent);
wxDEFINE_EVENT(myID_SENDBUTTON, wxCommandEvent);
wxDEFINE_EVENT(myID_FILEBUTTON, wxCommandEvent);

/// <summary>
/// Main frame class
/// </summary>
class CMain : public wxFrame
{
public:
	// Public constructor and destructor
	CMain();
	~CMain();

protected:
	// Menus
	wxMenuBar* m_mainMenuBar;
	wxMenu* m_fileMenu;
	wxMenu* m_helpMenu;
	// Child frame
	CSettings* m_settingsFrame;

private:
	// Output sizer
	wxBoxSizer* secondaryOutputSizer;
	// Data from input
	wxString m_inputText = "";
	wxString m_inputFilePath = "";
	std::list<CContent*> m_contentList = {};

public:
	// Getter for inputs data
	wxString getInputData();
	// Main update methode
	void updateContent();

private:
	// Menu events
	void OnQuit(wxCommandEvent& event);
	void OnSettings(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	// UI events
	void OnButtonSend(wxCommandEvent& event);
	void OnButtonAddfile(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};