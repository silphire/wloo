#pragma once

class XmppClient
{
public:
	static const int DefaultPort;

	XmppClient(void);
	virtual ~XmppClient(void);

protected:
	int Connect(const std::string &hostname, int port);
	int Resolve(const std::string &hostname, int port);
	int Establish(const std::string &hostname, int port);
	int OpenStream(void);
	int StartTLS(void);
	int Authenticate(void);
	int BindResource(void);
	int CloseStream(void);
	int Shutdown(void);
};
