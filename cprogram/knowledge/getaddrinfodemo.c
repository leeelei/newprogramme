#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int ret = -1;
    struct addrinfo *res;
    struct addrinfo hint;
    struct addrinfo *curr;
    char ipstr[16];   

    if (argc != 2) {
        printf("parameter error\n");
        return -1;
    }

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(argv[1], NULL, &hint, &res);
    if (ret != 0) 
    {
        printf("getaddrinfo error\n");
        return -1;
    }

    for (curr = res; curr != NULL; curr = curr->ai_next) 
    {
        inet_ntop(AF_INET,&(((struct sockaddr_in *)(curr->ai_addr))->sin_addr), ipstr, 16);
        printf("%s\n", ipstr);
    }

    freeaddrinfo(res);

    return 0;
}
