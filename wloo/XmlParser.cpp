#include "StdAfx.h"
#include "XmlParser.h"
#include <cctype>

XmlParser::XmlParser(void)
{
	Init();
}

XmlParser::~XmlParser(void)
{
}

void XmlParser::Init(void)
{
	ParserState = ST_TEXT;
	buffer.clear();
}

//
// 新しい文字列を追加して、パーサを回す。
//
void XmlParser::Parse(const std::string &toAppend)
{
	for(std::string::size_type i = 0; i < toAppend.length(); ++i) {
		switch(ParserState) {
			case ST_TEXT:
				// ST_TEXTの間は、要素の先頭を探す。見つからない間はテキストを解析しているとして扱う。
				if(toAppend[i] == '<') {
					if(buffer.length() > 0) {
						OnText(buffer);
						buffer.clear();
					}
					ParserState = ST_ELEMENT;
				} else {
					buffer += toAppend[i];
				}
				break;
			case ST_ELEMENT:
				// ST_ELEMENTの間は、要素の終了('>')を探す。
				if(toAppend[i] == '>') {
					ParseElement(buffer);
					buffer.clear();
					ParserState = ST_TEXT;
				} else {
					buffer += toAppend[i];
				}
				break;
		}
	}

	return;
}

static bool SkipSpace(const std::string &str, std::string::size_type &position)
{
	std::string::size_type prevPos = position;
	while(isspace(str[position])) {
		++position;
	}
	return position > prevPos;
}

bool XmlParser::ParseElement(const std::string &elemBuffer)
{
	std::string::size_type i = 0;
	std::string elemName;
	std::map<std::string, std::string> attrPairs;
	
	if(elemBuffer[0] == '/') {
		i = 1;
		SkipSpace(elemBuffer, i);
		for(; i < elemBuffer.length() && !isspace(elemBuffer[i]); ++i) {
			elemName += elemBuffer[i];
		}

		OnEndElement(elemName);
	} else {
		// 要素名
		SkipSpace(elemBuffer, i);
		for(; i < elemBuffer.length() && !isspace(elemBuffer[i]); ++i) {
			elemName += elemBuffer[i];
		}

		// 属性 Name S? '=' S? AttValue 
		for(; i < elemBuffer.length(); ++i) {
			std::string attrName, attrValue;
			char delim;

			SkipSpace(elemBuffer, i);
			if(elemBuffer[i] == '/') {	// 開始タグ中に '/' があったら空要素
				break;
			}

			// 属性名
			for(; i < elemBuffer.length() && !isspace(elemBuffer[i]) && elemBuffer[i] != '='; ++i) {
				attrName += elemBuffer[i];
			}
			SkipSpace(elemBuffer, i);
			++i;
			SkipSpace(elemBuffer, i);

			// 属性値
			delim = elemBuffer[i];
			++i;
			if(delim == '\'' || delim == '\"') {
				for(; i < elemBuffer.length() && elemBuffer[i] != delim; ++i) {
					attrValue += elemBuffer[i];
				}
				++i;
				attrPairs[attrName] = attrValue;
			} else {
				// 属性値を区切るデリミタとして不当
				return false;
			}
		}

		OnStartElement(elemName, attrPairs);
	}

	return true;
}

void XmlParser::OnStartElement(const std::string &elemName, const std::map<std::string, std::string> &attributes)
{
}

void XmlParser::OnEndElement(const std::string &elemName)
{
}

void XmlParser::OnText(const std::string &text)
{
}
