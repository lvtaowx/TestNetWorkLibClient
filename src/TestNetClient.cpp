/*
 * TestNetClient.cpp
 *
 *  Created on: Aug 30, 2013
 *      Author: lvanlv
 */

#include <iostream>

#include <CommonHeadFile.h>
#include <Socket.h>
#include <SocketAct.h>
#include <InetAddress.h>

using namespace netlib::net;
using namespace netlib::net::socketAct;

int main(void)
{
	std::string serverAddr = "127.0.0.1";
	int port = 1988;
	InetAddress inetAddr(serverAddr, port);

	int socketFd = createSockfd();
	netlib::net::socketAct::connect(socketFd, inetAddr.getNetAddress());

	char buf[20] = "this is client";

	netlib::net::socketAct::write(socketFd, buf, 20);
	netlib::net::socketAct::read(socketFd, buf, 20);
	printf("%s\n", buf);

	return 0;
}

