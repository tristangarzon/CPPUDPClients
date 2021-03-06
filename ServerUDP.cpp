// ServerUDP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Network.h"




int main()
{

	try
	{
		WSASession Session;
		UDPSocket Socket;

		SOCKET newConnection = socket(AF_INET, SOCK_STREAM, NULL);

		char buffer[256];

		Socket.Bind(256);

		const int NUM_SECONDS = 10;
		int i;


		while (1)
		{
			sockaddr_in add = Socket.RecvFrom(buffer, sizeof(buffer));

			std::string input(buffer);


			Socket.SendTo(add, input.c_str(), input.size());


		


			//Client connected
			std::cout << "Client Connected" << std::endl;

			//Displays IP & Port of incoming clients
			char *connected_ip = inet_ntoa(add.sin_addr);
			int port = ntohs(add.sin_port);
			std::cout << "Client Information:" << std::endl;
			std::cout << "-[IP:" << connected_ip << ", Connected on PORT:" << port << "]" << std::endl;

			//Testing
			
			char MSG[256];
			recv(newConnection, MSG, sizeof(MSG), NULL);
			
			while (*connected_ip = true)
			{
				for (i = 0; i < NUM_SECONDS; i++)
					printf(MSG);
				Sleep(5000);
			}


		}
	}
	catch (std::system_error& e)
	{
		std::cout << e.what();
	}

}
