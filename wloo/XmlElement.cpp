#include "StdAfx.h"
#include "XmlElement.h"
#include "XmlAttribute.h"

XmlElement::XmlElement(void)
{
}

XmlElement::~XmlElement(void)
{
}

std::string XmlElement::GetName(void) const
{
	return elemName.c_str();
}

std::string XmlElement::GetAttribute(const std::string &keyName) const
{
	std::map<std::string, XmlAttribute *>::const_iterator it = attributes.find(keyName);
	if(it == attributes.end()) {
		return std::string("");
	} else {
		return it->second->value;
	}
}

bool XmlElement::AddChildElement(const XmlElement *elem)
{
	return true;
}

bool XmlElement::AddAttribute(const XmlAttribute *attr)
{
	// Šù‚É“¯–¼‚Ì‘®«–¼‚ª“o˜^‚³‚ê‚Ä‚¢‚éê‡‚Í“o˜^‚µ‚È‚¢
	if(attributes.find(attr->name) == attributes.end()) {
		attributes[attr->name] = new XmlAttribute(*attr);
		return true;
	} else {
		return false;
	}
}

bool XmlElement::AddAttribute(std::string &name, std::string &value)
{
	// Šù‚É“¯–¼‚Ì‘®«–¼‚ª“o˜^‚³‚ê‚Ä‚¢‚éê‡‚Í“o˜^‚µ‚È‚¢
	if(attributes.find(name) == attributes.end()) {
		attributes[name] = new XmlAttribute();
		return true;
	} else {
		return false;
	}
}
