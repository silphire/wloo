#pragma once

#include <winsock2.h>
#include <windows.h>

class Socket
{
public:
	Socket(void);
	virtual ~Socket(void);

	void Init(void);
	void Connect(const std::string &hostname, int port);
	void Connect(const std::string &hostname, const std::string &service);
	void Close(void);

protected:
	SOCKET sock;
};
