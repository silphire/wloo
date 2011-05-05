#pragma once

#include <string>
#include <map>

//
// ������x���������ȍ\����XML�ł��ǂ��ɂ��ǂ�ł��܂�����ړI�Ƃ����A
// SAX�^�C�v��XML�p�[�T�N���X�B
// XML���ۂ����͂�ǂ݂͂��镨�́A���؂͂��Ȃ��B
//
// OnXXX()���p�����Ă�����Ďg���B
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
