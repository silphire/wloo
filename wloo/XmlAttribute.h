#pragma once

#include <string>

class XmlAttribute
{
public:
	XmlAttribute(void);
	virtual ~XmlAttribute(void);

	std::string name;
	std::string value;
};
