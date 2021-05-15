#include "stdio.h"
#include "string.h"

void chint(char* p ,int x)
{
    printf("p is \"%c\" and x is %d\n",*p,x);
}

int main()
{
    printf("Hello world!\n");

    char ch1[] = "Hello";
    char ch2[] = " world!";
    strcat(ch1,ch2);
    puts(ch1);

    chint("alma",4);
    chint("C",66);
    chint("B",9);
    chint(ch1,3);
}