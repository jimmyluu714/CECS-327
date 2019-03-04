CECS 327 Assignment 2

Authors: Jimmy Luu , Harry Hoang

Description: The goal of this project is to create an echo client using socket programming. We use two terminals to represent the server and the client. We created a program that represents the 'State Diagram for Socket connectivity'. This means that the client must send a message first in order for the server to reply. If the server sends first, it will not work correctly.  Also, the client is blocked from sending any further messages after sending a message until the server replies. Extra credit was offered to make the program work both ways and no blocking when sending messages, but this program only follows the bare minimum. There was no changes to the given makefile. Server.c and Client.c is an edited version of the files we were given.

References: Basic concept of Socket Programming in C/C++ (https://www.geeksforgeeks.org/socket-programming-cc/), Get the IP address and port of the server(https://www.geeksforgeeks.org/explicitly-assigning-port-number-client-socket/), Echo server (https://vcansimplify.wordpress.com/2013/03/14/c-socket-tutorial-echo-server/)

Instructions: 
Use command ‘make’ on one of the terminals to compile the code
First, run the server by typing ./server on the first terminal
Second, run the client by typing ./client on the second terminal