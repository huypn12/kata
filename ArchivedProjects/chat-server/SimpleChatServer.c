#include <stdio.h>  /* for printf() and fprintf() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for memset() */
#include <unistd.h> /* for close() */

#include <pthread.h>
#include <signal.h>

#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <sys/time.h>
#include <sys/types.h>

pthread_t gThrServer, gThrTimeout;

void handleServer() {}

void handleTimeout() {}

int initServer(int kUptime) {
  int resServer = pthread_create(&gThrServer, handleServer);
}