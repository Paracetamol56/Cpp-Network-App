/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Math�o Galuba
 */

#pragma once

#include "wx/wx.h"
#include "wx/menu.h"
#include "wx/utils.h"

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

	// UIs
	wxPanel* m_panelOutput = nullptr;
	wxPanel* m_panelInput = nullptr;
	wxButton* m_buttonSend = nullptr;
	wxButton* m_buttonAddfile = nullptr;
	wxTextCtrl* m_textBox = nullptr;

private:
	// Data from input
	wxString m_inputText = "";
	wxString m_filePath = "";

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