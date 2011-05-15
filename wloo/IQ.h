#pragma once
#include "stanza.h"

class IQ :
	public Stanza
{
public:
	IQ(void);
	virtual ~IQ(void);
};
