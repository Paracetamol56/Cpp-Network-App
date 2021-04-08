/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#pragma once

#include "wx/wx.h"
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

class CContent : public wxPanel
{
public:
	// Public constructor and destructor
	CContent(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString textMessage = "", const wxString filePath = "");
	~CContent();

protected:
	// Message time
	std::chrono::time_point<std::chrono::system_clock> m_contentTime;
	// Message string
	wxString m_textMessage = "";
	// File path
	wxString m_filePath = "";
};

