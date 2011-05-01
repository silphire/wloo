#pragma once
#include "stanza.h"

class Presence :
	public Stanza
{
public:
	Presence(void);
	virtual ~Presence(void);
};
