/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Math�o G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CImagePanel.h"

CImagePanel::CImagePanel(wxFrame* parent, wxString filePath) : wxPanel(parent)
{
	wxBitmap* bitmapImage = new wxBitmap(this, wxID_ANY, wxBitmap(m_filePath, wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(-1, 200), 0);
	wxImage* image = new wxImage(bitmapImage->ConvertToImage());
	image->Rescale(0.5, 0.5);
	wxDC* dc = new wxDC(this);
	dc->DrawBitmap(*bitmapImage, 0, 0, false);
}

CImagePanel::~CImagePanel()
{
}