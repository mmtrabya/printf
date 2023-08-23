#include "main.h"
/**
* prnt_hx - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_hx(va_list a, prm_t *prm)
{
unsigned long lg;
int co = 0;
char *string;
if (prm->l_mod)
lg = (unsigned long)va_arg(a, unsigned long);
else if (prm->h_mod)
lg = (unsigned short int)va_arg(a, unsigned int);
else
lg = (unsigned int)va_arg(a, unsigned int);
string = conv(lg, 16, CONV_UNS | CONV_LWR, prm);
if (prm->hsh_f && lg)
{
*--string = 'x';
*--string = '0';
}
prm->us = 1;
return (co += prnt_num(string, prm));
}
/**
 * prnt_HX - good
 * @a: good
 * @prm: good
 * Return: (0)
 */
int prnt_HX(va_list a, prm_t *prm)
{
	unsigned long lg;
	int co = 0;
	char *string;
	if (prm->l_mod)
		lg = (unsigned long)va_arg(a, unsigned long);
	else if (prm->h_mod)
		lg = (unsigned short int)va_arg(a, unsigned int);
	string = conv(lg, 16, CONV_UNS, prm);
	if (prm->hsh_f && lg)
	{
		*--string = 'X';
		*--string = '0';
	}
	prm->us = 1;
	return (co += prnt_num(string, prm));
}
/**
* prnt_bin - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_bin(va_list a, prm_t *prm)
{
unsigned int i = va_arg(a, unsigned int);
char *string = conv(i, 2, CONV_UNS, prm);
int co = 0;
if (prm->hsh_f && i)
*--string = '0';
prm->us = 1;

return (co += prnt_num(string, prm));
}
/**
* prnt_oct - good
* @a: good
* @prm: good
*Return: (0)
*/
int prnt_oct(va_list a, prm_t *prm)
{
unsigned long lg;
char *string;
int co = 0;
if (prm->l_mod)
lg = (unsigned long)va_arg(a, unsigned long);
else if (prm->h_mod)
lg = (unsigned short int)va_arg(a, unsigned int);
else
lg = (unsigned int)va_arg(a, unsigned int);
string = conv(lg, 8, CONV_UNS, prm);
if (prm->hsh_f && lg)
*--string = '0';
prm->us = 1;
return (co += prnt_num(string, prm));
}
