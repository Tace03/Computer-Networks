#ifndef CLISERV_H
#define CLISERV_H
#endif

#include <sys/types.h>
#include <winsock.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Notes: There are many Linux/UNIX libraries of C/C++ that are not available on windows, which is such a shame
          While I try to code out the content of TCP/IP - T/TCP book, I will find the best replacement of libraries
          For the code
 */

//#include <unistd.h>
//#include <arpa/inet.h>
//#include <netinet/in.h>

#define REQUEST 400
#define REPLY   400

#define UDP_SERVER_PORT  7777
#define TCP_SERVER_PORT  8888
#define TTCP_SERVER_PORT 9999

void err_quit(const char *,...);
void err_sys(const char *,...);
int read_stream(int, char *, int);