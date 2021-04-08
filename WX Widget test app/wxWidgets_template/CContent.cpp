/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CContent.h"

CContent::CContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, const wxString textMessage, const wxString filePath) : wxPanel(parent, id, pos, size, style, name)
{
	// Update the time atribut to the current system time
	m_contentTime = std::chrono::system_clock::now();

	// Initialize the message string atribut
	m_textMessage = textMessage;

	// Initialize the file path string atribut
	m_filePath = filePath;

	// ========== GUI GENERATION ========== //
	
	this->SetBackgroundColour(wxColour(255, 0, 0));

	// ======== END GUI GENERATION ======== //
}

CContent::~CContent()
{
}
