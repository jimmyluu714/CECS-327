/*
Jimmy Luu, Harry Hoang
CECS 327 Sec 03
2/24/19
HM2
*/

// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	// Global variables
	struct sockaddr_in address; 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char input[1024];
	char ip[20];
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 
	// If connection between IP and socket does not work
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	}
	else
	{
		printf("\nConnecton established! Press Ctrl+C on your keyboard to exit\n");
		// Convert IP address into a string
		inet_ntop(AF_INET, &serv_addr.sin_addr, ip, 20);
		// Print IP address
		printf("IP: %s", ip);
		// Print Port number
		printf(" Port: %d\n\n", ntohs(serv_addr.sin_port));
	}
	// Continues forever until the user presses Ctrl+C on their keyboard
	while(1)
	{
		// Clear the buffer
		bzero(input, 1024);
		// Get user input
		fgets(input, 1024, stdin);
		// Write the inputted message to the Server terminal
		write(sock , input , strlen(input)+1);
		// Read the next inputted message from Server terminal
		read( sock , input, 1024); 
		// Print the inputted message from the Server terminal
		printf("\nServer: %s\n",input );
	}
	return 0;
}
