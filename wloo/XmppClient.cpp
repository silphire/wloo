#include "StdAfx.h"
#include "XmppClient.h"

const int XmppClient::DefaultPort = 5222;

XmppClient::XmppClient(void)
{
}

XmppClient::~XmppClient(void)
{
}

int XmppClient::Connect(const std::string &hostname, int port)
{
	return 0;
}

// Determine the IP address and port at which to connect, typically
// based on resolution of a fully qualified domain name
int XmppClient::Resolve(const std::string &hostname, int port)
{
	return 0;
}

// Open a Transmission Control Protocol TCP connection
int XmppClient::Establish(const std::string &hostname, int port)
{
	// ÉTÅ[ÉoÇ…ê⁄ë±
	//
	return 0;
}

// Open an XML stream over TCP
int XmppClient::OpenStream(void)
{
	return 0;
}

// Preferably negotiate Transport Layer Security [TLS] for channel encryption
int XmppClient::StartTLS(void)
{
	return 0;
}

// Authenticate using a Simple Authentication and Security Layer SASL mechanism
int XmppClient::Authenticate(void)
{
	return 0;
}

// Bind a resource to the stream
int XmppClient::BindResource(void)
{
	return 0;
}

// Close the XML stream
int XmppClient::CloseStream(void)
{
	return 0;
}

// Close the TCP connection
int XmppClient::Shutdown(void)
{
	return 0;
}
