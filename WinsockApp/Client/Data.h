/*
 * Created on Fri May 21 2021
 *
 * Copyright (c) 2021 - Mathéo G & Sahel H - All Right Reserved
 *
 * Licensed under the Apache License, Version 2.0
 * Available on GitHub at https://github.com/Paracetamol56/Cpp-Network-App
 */

#pragma once

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

 /// <summary>
 /// Structure containing information about a single message
 /// </summary>
struct SData
{
	char m_username[256];			// Sender's name
	char m_message[4096];			// Text message
	bool m_read = true;				// Writing/Reading state
	char m_type = '\0';				// Content kind ('f' = file; 't' = text; '\0' = undefined)

};

#endif // DATA_H_INCLUDED