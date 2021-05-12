#pragma once

class CDataStructure
{
public:
	char m_name[256];
	char m_message[65536];

	// Default constructor
	CDataStructure()
	{
	}

	// Constructor whith wxString parameters
	CDataStructure(wxString name, wxString message)
	{
		memcpy(&m_name, name.c_str(), 256);
		memcpy(&m_message, message.c_str(), 65536);
	}
};