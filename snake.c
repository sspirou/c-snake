#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char* buff = {"hello world - c\n"};
    write(STDOUT_FILENO, buff, strlen(buff));
    _exit(EXIT_SUCCESS);
}