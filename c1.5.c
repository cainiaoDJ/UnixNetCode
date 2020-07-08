#include "unp.h"

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2)
    {
        err_quit("usage: a.out <IPaddress>");
    }
    // 创建socket套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {

        err_sys("socket error");
    }

    // 服务器信息初始化
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    // htons 将16位主机字符顺序转换成网络字符顺序
    servaddr.sin_port = htons(13);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        err_quit("inet_pton error for %s", argv[1]);
    }

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        err_sys("connect error");
    }

    while ((n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
        {
            err_sys("fputs error");
        }
    }

    if (n < 0)
    {
        err_sys("read error");
    }
    exit(0);
}