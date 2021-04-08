#pragma once

#include "wx/wx.h"
#include "wx/utils.h"

class CSettings : public wxFrame
{
private:
	// IP adress
	wxString m_IPAdress01Input = "";
	wxString m_IPAdress02Input = "";
	wxString m_IPAdress03Input = "";
	wxString m_IPAdress04Input = "";
	// Port
	wxString m_portInput = "";
	// Username
	wxString m_usernameInput = "";

public:
	CSettings();
	~CSettings();
};

