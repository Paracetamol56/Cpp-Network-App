/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#include "CApp.h"

// Entry point definition
wxIMPLEMENT_APP(CApp);

/// <summary>
/// Constructor
/// </summary>
CApp::CApp()
{
}

/// <summary>
/// Destructor
/// </summary>
CApp::~CApp()
{
}

/// <summary>
/// Main launcher methode
/// </summary>
/// <returns></returns>
bool CApp::OnInit()
{
	m_frame01 = new CMain;
	m_frame01->Show();

	return true;
}
