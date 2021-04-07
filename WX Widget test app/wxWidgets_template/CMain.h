/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#pragma once

#include "wx/wx.h"
#include "wx/menu.h"
#include "wx/utils.h"

wxDEFINE_EVENT(myID_SETTINGS, wxCommandEvent);

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

private:
	void OnQuit(wxCommandEvent& event);
	void OnSettings(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};