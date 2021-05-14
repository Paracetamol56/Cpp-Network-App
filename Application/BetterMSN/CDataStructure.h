#pragma once

#ifndef CDATASTRUCTURE_H_INCLUDED
#define CDATASTRUCTURE_H_INCLUDED

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

#endif // CDATASTRUCTURE_H_INCLUDED