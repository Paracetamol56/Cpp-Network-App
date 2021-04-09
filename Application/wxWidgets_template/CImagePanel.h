/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 * 
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#pragma once

#include <wx/wx.h>

// >>> CREDIT : wxWidgets Wiki > https://wiki.wxwidgets.org/An_image_panel
class CImagePanel : public wxPanel
{
private:
    wxImage image;
    wxBitmap resized;
    int w, h;

public:
    CImagePanel(wxPanel* parent, wxString filePath, wxBitmapType format);
    CImagePanel(wxFrame* parent, wxString filePath, wxBitmapType format);
    ~CImagePanel();

    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);

    wxDECLARE_EVENT_TABLE();
};