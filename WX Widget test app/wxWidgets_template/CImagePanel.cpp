/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#include "CImagePanel.h"

CImagePanel::CImagePanel(wxFrame* parent, wxString file, wxBitmapType format)
{
	image.LoadFile(file, format);
}

CImagePanel::~CImagePanel()
{
}

void CImagePanel::paintEvent(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void CImagePanel::render(wxDC& dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}
