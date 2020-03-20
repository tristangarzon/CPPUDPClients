// ClientUDP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Network.h"
#include <stdio.h>



int main()
{


	try
	{
		WSASession Session;
		UDPSocket Socket;

		SOCKET Connection = socket(AF_INET, SOCK_STREAM, IPPROTO_UDP);


		//Client has connected to the server
		std::string data = "Welcome to the server";
		char buffer[256];



		//Sends to IP address
		Socket.SendTo("127.0.0.1", 256, data.c_str(), data.size());

		Socket.RecvFrom(buffer, 256);
		std::cout << buffer;

		struct hostent *hinf;
		char host_name[256];

		//Shows connected host name
		gethostname(host_name, sizeof(host_name));
		hinf = gethostbyname(host_name);
		std::cout << "\nYou are connected to: " << host_name << std::endl;

		//Testing


		char MSG[256] = "Ping";
		send(Connection, MSG, sizeof(MSG), NULL);
		
		//std::string MSG = "Ping";
		




	}
	catch (std::exception &ex)
	{
		std::cout << ex.what();
	}
	char c;
	std::cin >> c;


}