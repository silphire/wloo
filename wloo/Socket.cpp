#include "StdAfx.h"
#include "Socket.h"

#include <tchar.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

static class WinsockInitializer
{
public:
	WinsockInitializer() {
		ZeroMemory(&wsaData, sizeof(wsaData));
		WSAStartup(MAKEWORD(2, 2), &wsaData);
		MessageBox(NULL, _T("Init"), _T(""), MB_OK);
	}

	virtual ~WinsockInitializer() {
		WSACleanup();
		MessageBox(NULL, _T("Destroy"), _T(""), MB_OK);
	}

	void Nop(void) {}

protected:
	WSADATA wsaData;
} theWinsockInitializer;

Socket::Socket(void)
{
	theWinsockInitializer.Nop();
}

Socket::~Socket(void)
{
}

void Socket::Init(void)
{
}

void Socket::Connect(const std::string &hostname, int port)
{
	int err;
	struct addrinfo hints, *result;
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET) {
		return;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family   = AF_INET;
	err = getaddrinfo(hostname.c_str(), NULL, &hinsts, &result);
	if(err != 0) {
		closesocket(sock);
		return;
	}

	memcpy_s(addr, sizeof(addr), hints.ai_addr, sizeof(*(hints.ai_addr)));
	addr.sin_port = htons(port);
	err = connect(socket, reinterpret_cast<struct sockaddr *>(&addr), sizeof(struct sockaddr));
	if(err != 0) {
		closesocket(sock);
		return;
	}

	freeaddrinfo(result);
	return;
}

void Socket::Close(void)
{
	closesocket(sock);
}

void Socket::Connect(const std::string &hostname, const std::string &service)
{
	servent *ent = getservbyname(service.c_str(), "tcp");
	Connect(hostname, ntohs(ent->s_port));
}

int Socket::Send(const char *buffer, int length)
{
	int nWroteLen = 0;
	return nWroteLen;
}

int Socket::Receive()
{
	int nWroteLen = 0;
	return nWroteLen;
}
