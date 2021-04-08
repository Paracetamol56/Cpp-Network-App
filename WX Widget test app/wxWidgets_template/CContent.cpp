/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CContent.h"

CContent::CContent(wxWindow* parent, wxWindowID id, const wxString username, const wxString textMessage, const wxString filePath) : wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	// Update the time atribut to the current system time
	m_contentTime = std::chrono::system_clock::now();
	std::string strTime = "";
	// Time point to string conversion
	// >>> CREDIT : Adrian Maire
	{
		std::time_t tt = std::chrono::system_clock::to_time_t(m_contentTime);
		//std::tm tm = *std::gmtime(&tt); // GMT (UTC)
		std::tm tm = *std::localtime(&tt); // Local time
		std::stringstream ss;
		std::string format = "%Y-%m-%d %H:%M:%S";
		ss << std::put_time(&tm, format.c_str());
		strTime = ss.str();
	}

	// Initialize the username string atribute
	m_username = username;

	// Initialize the message string atribut
	m_textMessage = textMessage;

	// Initialize the file path string atribut
	m_filePath = filePath;

	// ========== GUI GENERATION ========== //
	
	// Set panel background color
	this->SetBackgroundColour(wxColour(220, 230, 240));

	// Sizer
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* headerSizer = new wxBoxSizer(wxHORIZONTAL);

	// Static text
	wxStaticText* timeLabel = new wxStaticText(this, wxID_ANY, strTime, wxDefaultPosition, wxSize(100, -1), wxALIGN_RIGHT);
	timeLabel->SetForegroundColour(wxColor(90, 100, 100));
	timeLabel->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));

	wxStaticText* usernameLabel = new wxStaticText(this, wxID_ANY, m_username, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	usernameLabel->SetForegroundColour(wxColor(90, 100, 100));
	usernameLabel->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false));
	
	headerSizer->Add(usernameLabel, 2, wxEXPAND);
	headerSizer->Add(timeLabel, 1, wxEXPAND);

	wxStaticText* mainMessage = new wxStaticText(this, wxID_ANY, m_textMessage, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP);
	mainMessage->SetForegroundColour(wxColor(20, 20, 20));
	mainMessage->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
	mainMessage->Wrap(this->GetSize().GetWidth());

	// Add everything to the sizer
	mainSizer->Add(headerSizer, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(mainMessage, 1, wxEXPAND | wxALL, 5);
	// Sizer structuration
	this->SetSizer(mainSizer);

	// ======== END GUI GENERATION ======== //
}

CContent::~CContent()
{
}
