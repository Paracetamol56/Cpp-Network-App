/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CContent.h"

CContent::CContent(wxWindow* parent, wxWindowID id, const wxString textMessage, const wxString filePath) : wxPanel(parent, id, wxDefaultPosition, wxSize(500, 100))
{
	// Update the time atribut to the current system time
	m_contentTime = std::chrono::system_clock::now();
	std::string strTime = "";
	// Time point to string conversion
	// >>> CREDIT : Adrian Maire
	{
		std::time_t tt = std::chrono::system_clock::to_time_t(m_contentTime);
		std::tm tm = *std::gmtime(&tt); //GMT (UTC)
		std::stringstream ss;
		std::string format = "%Y-%m-%d %H:%M:%S";
		ss << std::put_time(&tm, format.c_str());
		strTime = ss.str();
	}

	// Initialize the message string atribut
	m_textMessage = textMessage;

	// Initialize the file path string atribut
	m_filePath = filePath;

	// ========== GUI GENERATION ========== //
	
	// Set panel background color
	this->SetBackgroundColour(wxColour(220, 230, 240));

	// Sizer
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	// Static text
	/*wxStaticText* timeLabel = new wxStaticText(this, wxID_ANY, strTime);
	mainSizer->Add(timeLabel, 1, wxEXPAND);*/
	


	// ======== END GUI GENERATION ======== //
}

CContent::~CContent()
{
}
