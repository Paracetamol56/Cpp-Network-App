#include "CSettings.h"

CSettings::CSettings() : wxFrame(nullptr, wxID_ANY, "Settings", wxPoint(-1, -1), wxSize(500, 500))
{
	// Panel
	wxPanel* panelGlobal = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500), wxTE_MULTILINE);
	// Sizer
	wxFlexGridSizer* mainSizer = new wxFlexGridSizer(3, 2, 5, 30);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* thetitle = new wxStaticText(panelGlobal, -1, wxT("Destination IP"));
	wxStaticText* author = new wxStaticText(panelGlobal, -1, wxT("Port"));
	wxStaticText* review = new wxStaticText(panelGlobal, -1, wxT("Username"));

	wxTextCtrl* tc1 = new wxTextCtrl(panelGlobal, -1);
	wxTextCtrl* tc2 = new wxTextCtrl(panelGlobal, -1);
	wxTextCtrl* tc3 = new wxTextCtrl(panelGlobal, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));

	mainSizer->Add(thetitle);
	mainSizer->Add(tc1, 1, wxEXPAND);
	mainSizer->Add(author);
	mainSizer->Add(tc2, 1, wxEXPAND);
	mainSizer->Add(review);
	mainSizer->Add(tc3, 1, wxEXPAND);

	hbox->Add(mainSizer, 1, wxALL | wxEXPAND, 15);
	panelGlobal->SetSizer(hbox);
	Centre();
}

CSettings::~CSettings()
{

}
