/*
 * TestNetClient.cpp
 *
 *  Created on: Aug 30, 2013
 *      Author: lvanlv
 */

#include <iostream>
#include <stdlib.h>

#include <CommonHeadFile.h>
#include <Socket.h>
#include <SocketAct.h>
#include <InetAddress.h>

using namespace netlib::net;
using namespace netlib::net::socketAct;

int main(int argc, char* argv[])
{
	std::string serverAddr = "127.0.0.1";

	int port;
	if(argc > 1)
	{
		port = atoi(argv[1]);
	}
	else
	{
		port = 1988;
	}

	InetAddress inetAddr(serverAddr, port);

//	int socketFd = createSockfd();
	int socketFd = ::socket(AF_INET, SOCK_STREAM /* | SOCK_NONBLOCK  */ | SOCK_CLOEXEC, IPPROTO_TCP);
	netlib::net::socketAct::connect(socketFd, inetAddr.getNetAddress());

	char buf[20] = "this is client";

//	netlib::net::socketAct::read(socketFd, buf, 20);

	ssize_t len = netlib::net::socketAct::write(socketFd, buf, 20);
	if(len == -1)
	{
		printf("write error!\n");
	}
	else
	{
		printf("write %d bytes\n", int(len));
	}

	netlib::net::socketAct::read(socketFd, buf, 20);

	printf("%s\n", buf);

	return 0;
}

