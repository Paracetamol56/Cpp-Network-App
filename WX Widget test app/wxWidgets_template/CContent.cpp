/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CContent.h"

CContent::CContent(std::string textMessage, std::string filePath)
{
	// Update the time atribut to the current system time
	m_contentTime = std::chrono::system_clock::now();

	// Initialize the message string atribut
	m_textMessage = textMessage;

	// Initialize the file path string atribut
	m_filePath = filePath;

	// ========== GUI GENERATION ========== //
	


	// ======== END GUI GENERATION ======== //
}

CContent::~CContent()
{
}
