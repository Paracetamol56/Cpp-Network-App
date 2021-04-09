/*
 * Created on Tue Apr 07 2021
 *
 * Copyright (c) 2021 - Mathéo Galuba
 */

#pragma once

#include <wx/wx.h>
#include "CMain.h"

/// <summary>
/// Main app class
/// </summary>
class CApp : public wxApp
{
public:
	
	// Public constructor and destructor
	CApp();
	~CApp();

private:
	
	// Private data to store the main frame
	CMain* m_frame01 = nullptr;

public:
	
	// Launcher methode
	virtual bool OnInit();
};
