/*************************************************************************
	> File Name: bugging.cpp
	> Author: gaopengfei
	> Mail:  
	> Created Time: 2021年07月18日 星期日 19时57分15秒
 ************************************************************************/

/*
 *  gcc bugging.c -o bug
 *  gcc bugging.c -g -o bug.g
 *  gcc bugging.c -g -O2 bug.gO2
 *  gdb(cgdb) bug(bug.g/bug.gO2)    r n b p 
 *  gdb(cgdb) bug(bug.g/bug.gO2) + core.file bt 
 * */

#include <stdio.h>

static char buff[256];
static char* string;

int main()
{
    printf("Please input a string: ");

    gets(buff);
    printf("\n Your string is: %s \n", buff);

    gets(string);
    printf("\n Your string is: %s \n", string);

    return 0;
}
