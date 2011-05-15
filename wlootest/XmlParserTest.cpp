#include "XmlParserTest.h"
#include <iostream>

XmlParserTest::XmlParserTest(void)
{
}

XmlParserTest::~XmlParserTest(void)
{
}

void XmlParserTest::SetUp(void)
{
}

void XmlParserTest::TearDown(void)
{
}

class TestParser : public XmlParser {
public:
	TestParser() {
	}

	virtual ~TestParser() {
	}

	virtual void OnStartElement(const std::string &elemName, const std::map<std::string, std::string> &attributes) {
		std::cout << "ST (" << elemName << ")" << std::endl;
		for(std::map<std::string, std::string>::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
			std::cout << "AT (" << it->first << "=" << it->second << ")" << std::endl;
		}
	}

	virtual void OnEndElement(const std::string &elemName) {
		std::cout << "ED (" << elemName << ")" << std::endl;
	}

	virtual void OnText(const std::string &text) {
		std::cout << "TX (" << text << ")" << std::endl;
	}
};

TEST(XmlParserTest, EmptyElement) {
	TestParser p;
	std::string xml = "<hoge /><fuga abc=\"def\" ghi='jkl'/><foo bar = \" baz \">text</foo>";

	p.Parse(xml);
}
