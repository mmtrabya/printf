#include "main.h"
/**
 * _pt - good
 * @string: good
 * Return: (1)
*/
/**
 * _ptchar - good
 * @ch: good
 * Return (1)
*/
int _pt(char *string)
{
char *begin = string;
while (*string)
_ptchar(*string++);
return (string - begin);
}

int _ptchar(int ch)
{
static int n;
static char bf[bf_size];
if (ch == bf_flsh || n >= bf_size)
{
write (1, bf, n);
n = 0;
}
if (c != bf_flsh)
bf[n++] = ch;
return (1);
}
