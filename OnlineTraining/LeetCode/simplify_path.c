#include "stdafx.h"

/*
This one is stack
*/

#define NAME_LEN 64

char *simplifyPath(char *path)
{
    if (path == NULL) {
        return NULL;
    }
    int pathLen = strlen(path);
    char *cPath = (char *) malloc(sizeof(char) * (pathLen + 1));
    memset(cPath, 0x0, pathLen + 1);

    int cPathIt = 0;
    int pathIt = 0;

    char token = '/';
    if (path[pathIt] != token) {
        return NULL;
    }
    cPath[0] = token;

    char buff[NAME_LEN] = {0};
    for (pathIt = 1; pathIt < pathLen;) {
        while (path[pathIt] == token) {
            pathIt++;
        }

        memset(buff, 0x0, NAME_LEN);
        int buffLen = 0, i = 0;
        while (i < NAME_LEN && pathIt + i < pathLen) {
            if (path[pathIt + i] == token) {
                break;
            }
            buff[i] = path[pathIt + i];
            i++;
        }
        if (i == 0) continue;
        buffLen = i;
        pathIt += buffLen;

        if (!strcmp(buff, ".")) {
            ;
        } else if (!strcmp(buff, "..")) {
            if (cPathIt == 0) {
                continue;
            } else {
                cPath[cPathIt] = 0;
                cPathIt -= 1; // omit '/'
                while (cPathIt > 0 && cPath[cPathIt] != token) {
                    cPath[cPathIt] = 0;
                    cPathIt -= 1;
                }
            }
        } else {
            cPathIt++;
            for (i = 0; i < buffLen; i++) {
                cPath[cPathIt + i] = buff[i];
            }
            cPath[cPathIt + buffLen] = '/';
            cPathIt += buffLen;
        }
        
    }

    if (cPathIt != 0 && cPath[cPathIt] == token) {
        cPath[cPathIt] = 0;
    }
    return cPath;
}

#define BUFF_SIZE 256

void test()
{
    char buf[BUFF_SIZE];
    char *cPath = NULL;
    
    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/home/");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/home"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/../");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/home//foo/");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/home/foo"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/a/./b/../../c/");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/c"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/a/../../b/../c//.//");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/c"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/a//b////c/d//././/..");
    cPath = simplifyPath(buf);
    printf("%s\n", cPath);
    assert(!strcmp(cPath, "/a/b/c"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/");
    cPath = simplifyPath(buf);
    printf("%s %ld\n", cPath, strlen(cPath));
    assert(!strcmp(cPath, "/"));
    free(cPath);

    memset(buf, 0x0, BUFF_SIZE);
    snprintf(buf, BUFF_SIZE, "/...");
    cPath = simplifyPath(buf);
    printf("%s %ld\n", cPath, strlen(cPath));
    assert(!strcmp(cPath, "/..."));
    free(cPath);
}

int main()
{
    test();

    return EXIT_SUCCESS;
}