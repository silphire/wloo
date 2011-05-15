#pragma once

#include <string>
#include <vector>
#include <map>
#include "XmlAttribute.h"

class XmlElement
{
public:
	XmlElement(void);
	virtual ~XmlElement(void);

	std::string GetName(void) const;
	std::string GetAttribute(const std::string &key) const;

	bool AddChildElement(const XmlElement *elem);
	bool AddAttribute(const XmlAttribute *attr);
	bool AddAttribute(std::string &name, std::string &value);

	std::string elemName;
	std::map<std::string, XmlAttribute *> attributes;
	std::vector<XmlElement *> childElements;
};
