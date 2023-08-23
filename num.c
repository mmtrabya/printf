#include "main.h"
/**
* conv - good
* @nm: good
* @bs: good
* @fl: good
* @prm: good
* Return: (0)
*/
char *conv(long int nm, int bs, int fl, prm_t *prm)
{
static char *arr;
static char buf[50];
char sn = 0;
char *pt;
unsigned long i = nm;
(void)prm;
if (!(fl & CONV_UNS) && nm < 0)
{
i = -nm;
sn = '-';
}
arr = fl & CONV_LWR ? "0123456789abcdef" : "0123456789ABCDEF";
pt = &buf[49];
*pt = '\0';
do {
*--pt = arr[i % bs];
i /= bs;
} while (i != 0);
if (sn)
*--pt = sn;
return (pt);
}
/**
* prnt_uns - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_uns(va_list a, prm_t *prm)
{
unsigned long lg;
if (prm->l_mod)
lg = (unsigned long)va_arg(a, unsigned long);
else if (prm->h_mod)
lg = (unsigned short int)va_arg(a, unsigned int);
else
lg = (unsigned int)va_arg(a, unsigned int);
prm->us = 1;
return (prnt_num(conv(1, 10, CONV_UNS, prm), prm));
}
/**
* prnt_addrss - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_addrss(va_list a, prm_t *prm)
{
unsigned long int num = va_arg(a, unsigned long int);
char *string;
if (!num)
return (_pt("(nil)"));
string = conv(num, 16, CONV_UNS | CONV_LWR, prm);
*--string = 'x';
*--string = '0';
return (prnt_num(string, prm));
}

