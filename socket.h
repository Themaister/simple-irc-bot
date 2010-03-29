#ifndef IRC_SOCKET_H
#define IRC_SOCKET_H

int get_socket(const char* host, const char* port);
int sck_send(int socket, const char* data, size_t size);
