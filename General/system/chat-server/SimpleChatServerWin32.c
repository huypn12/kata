#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <stdlib.h>
#include <stdio.h>

DWORD WINAPI ServerThreadFunction();