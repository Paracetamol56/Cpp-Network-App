#pragma once

#define NAME_LENGTH = 256;
#define MESSAGE_LENGTH = 65536;

class CDataStructure
{
private:
	char m_name[NAME_LENGTH];
	char m_message[MESSAGE_LENGTH];

public:
	
	// Constructor and destructor

	CDataStructure() {}
	~CDataStructure() {}

	// Getters

	char[NAME_LENGTH] getName()
	{
		return m_name;
	}

	char[MESSAGE_LENGTH] getMessage()
	{
		return m_message;
	}

	// Setters

	void setName(char[] name)
	{
		memset(m_name, 0, sizeof(m_name));
		m_name = name;
	}

	void setMessage(char[] message)
	{
		memset(m_message, 0, sizeof(m_message));
		m_message = message;
	}
};