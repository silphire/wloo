#pragma once
#include "XmlParser.h"
#include <gtest/gtest.h>

class XmlParserTest : public ::testing::Test
{
public:
	XmlParserTest(void);
	virtual ~XmlParserTest(void);

	virtual void SetUp(void);
	virtual void TearDown(void);
};
