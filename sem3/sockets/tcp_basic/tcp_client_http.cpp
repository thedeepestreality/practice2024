#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <netdb.h>

const int PORT = 80;

int main(int argc, char const* argv[])
{
	const char* hello = "GET /todos HTTP/1.1\nHost: pmpubest.free.beeceptor.com\nUser-Agent: curl/7.81.0\nAccept: */*\n\n";
	char buffer[1024] = { 0 };
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (client_fd < 0) {
		perror("Socket creation error");
		exit(EXIT_FAILURE);
	}

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);

	// addrinfo hints, *res;
	// memset(&hints, 0, sizeof hints);
	// if (getaddrinfo("pmpubest.free.beeceptor.com", NULL, &hints, &res) != 0)
    // 	return false;

	// const char * inetAddr;
	// inetAddr = inet_ntoa(((sockaddr_in *) res -> ai_addr) -> sin_addr);
	// std::cout << "addr = " << inetAddr << "\n";

    // servaddr.sin_addr.s_addr = inet_addr("70.38.95.141");//INADDR_ANY;
	servaddr.sin_addr.s_addr = inet_addr(inetAddr);//INADDR_ANY;

    int status = connect(
        client_fd,
        (struct sockaddr*)&servaddr,
		sizeof(servaddr)
    );
	if (status < 0)
    {
        perror("Connection Failed");
		exit(EXIT_FAILURE);
	}
	send(client_fd, hello, strlen(hello), 0);
	std::cout << "Hello message sent\n";
	int valread = read(client_fd, buffer, 1024);
	std::cout << "Message1: " << buffer << '\n';
	valread = read(client_fd, buffer, 1024);
	std::cout << "Message2: " << buffer << '\n';
	valread = read(client_fd, buffer, 1024);
	std::cout << "Message3: " << buffer << '\n';

	// closing the connected socket
	close(client_fd);
	return 0;
}
