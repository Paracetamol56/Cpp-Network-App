#include "CSettings.h"

CSettings::CSettings() : wxFrame(nullptr, wxID_ANY, "Settings", wxPoint(-1, -1), wxSize(290, 140), wxDEFAULT_FRAME_STYLE &~(wxRESIZE_BORDER))
{
	// Panel
	wxPanel* panelGlobal = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500), wxTE_MULTILINE);
	// Sizer
	wxBoxSizer* mainBox = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* mainSizer = new wxFlexGridSizer(3, 2, 5, 30);
	wxBoxSizer* ipSizer = new wxBoxSizer(wxHORIZONTAL);
	// Static text labels
	wxStaticText* ipLabel = new wxStaticText(panelGlobal, -1, wxT("Destination IP"));
	wxStaticText* portLabel = new wxStaticText(panelGlobal, -1, wxT("Port"));
	wxStaticText* usernameLable = new wxStaticText(panelGlobal, -1, wxT("Username"));
	// IP inputs
	wxTextCtrl* ipTextBox1 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress01Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox2 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress02Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox3 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress03Input, wxDefaultPosition, wxSize(30, -1));
	wxTextCtrl* ipTextBox4 = new wxTextCtrl(panelGlobal, wxID_ANY, m_IPAdress04Input, wxDefaultPosition, wxSize(30, -1));
	wxStaticText* ipSemicolon1 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon2 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	wxStaticText* ipSemicolon3 = new wxStaticText(panelGlobal, -1, wxT(" : "));
	ipSizer->Add(ipTextBox1, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon1);
	ipSizer->Add(ipTextBox2, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon2);
	ipSizer->Add(ipTextBox3, 1, wxEXPAND);
	ipSizer->Add(ipSemicolon3);
	ipSizer->Add(ipTextBox4, 1, wxEXPAND);
	// Port input
	wxTextCtrl* portTextBox = new wxTextCtrl(panelGlobal, -1);
	// Username input
	wxTextCtrl* usernameTextBox = new wxTextCtrl(panelGlobal, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));

	// Add everything to the sizer
	mainSizer->Add(ipLabel);
	mainSizer->Add(ipSizer, 1, wxEXPAND);
	mainSizer->Add(portLabel);
	mainSizer->Add(portTextBox, 1, wxEXPAND);
	mainSizer->Add(usernameLable);
	mainSizer->Add(usernameTextBox, 1, wxEXPAND);
	mainBox->Add(mainSizer, 1, wxEXPAND | wxALL, 10);

	panelGlobal->SetSizer(mainBox);
	Centre();
}

CSettings::~CSettings()
{

}
