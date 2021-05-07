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
#include "CMain.h"

/// <summary>
/// Main app class
/// </summary>
class CApp : public wxApp
{
private:

	bool m_renderLoopOn;

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
	// Idle loop handler
	void activateIdleLoop(bool on);
	// Idle loop
	void OnIdle(wxIdleEvent& evt);
};
