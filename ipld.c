#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
#include<err.h>

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	// char *message;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		err(1, "Cannot create socket");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(1234);

	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		err(1, "Cannot bind");
	}

	listen(socket_desc, 3);

	for (;;) {
		c = sizeof(struct sockaddr_in);
		new_socket =
		    accept(socket_desc, (struct sockaddr *)&client,
			   (socklen_t *) & c);
		if (new_socket < 0) {
			return 3;
		}

		// int client_port = ntohs(client.sin_port);
		char *client_ip = inet_ntoa(client.sin_addr);
		for (int i = 0; i < 100; ++i) {
			if (client_ip[i] == 0)
				break;
			printf("%c", client_ip[i]);
		}
		printf("\n");
		write(new_socket, client_ip, strlen(client_ip));
		write(new_socket, "\n", 1);
	}
	return 0;
}
