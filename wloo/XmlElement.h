#pragma once

class XmlElement
{
public:
	XmlElement(void);
	virtual ~XmlElement(void);

	const char *GetName(void) const;
	const char *GetAttribute(const char *key) const;
};
