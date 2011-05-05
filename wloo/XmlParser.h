#pragma once

#include <string>
#include <map>

//
// ある程度いい加減な構造のXMLでもどうにか読んでしまう事を目的とした、
// SAXタイプのXMLパーサクラス。
// XMLっぽい文章を読みはする物の、検証はしない。
//
// OnXXX()を継承してもらって使う。
//

class XmlParser
{
public:
	XmlParser(void);
	virtual ~XmlParser(void);

	void Init(void);
	void Parse(const std::string &toAppend);

	std::string buffer;		// prefetch buffer

protected:
	virtual void OnStartElement(const std::string &elemName, const std::map<std::string, std::string> &attributes);
	virtual void OnEndElement(const std::string &elemName);
	virtual void OnText(const std::string &text);

private:
	enum {
		ST_NONE, 
		ST_ELEMENT, 
		ST_ATTRIBUTE_KEY, 
		ST_ATTRIBUTE_VALUE, 
		ST_TEXT, 
	} ParserState;

	bool ParseElement(const std::string &elemBuffer);
};
