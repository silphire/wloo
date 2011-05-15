#pragma once
#include "stanza.h"

class Message :
	public Stanza
{
public:
	Message(void);
	virtual ~Message(void);
};
