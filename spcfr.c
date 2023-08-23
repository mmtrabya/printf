#include "main.h"
/**
* gt_spcfr - good
* @str: good
* Return: (0)
*/
/**
* gt_prnt - good
* @str: good
* @a: good
* @prm: good
* Return: (0)
*/
/**
* gt_flag - good
* @str: good
* @prm: good
* Return: (0)
*/
/**
* gt_mod - good
* @str: good
* @prm: good
* Return: (0)
*/
/**
* gt_wdth - good
* @str: good
* @prm: good
* @a: good
* Return: (0)
*/
int (*gt_spcfr(char *str))(va_list a, prm_t *prm)
{
spcfr_t spcfrs[] = {
{"c", prnt_chr},
{"s", prnt_strng},
{"%", prnt_prcnt},
{"o", prnt_oct},
{"u", prnt_uns},
{"b", prnt_bin},
{"x", prnt_hx},
{"X", prnt_hx},
{"P", prnt_addrss},
{"S", prnt_sc},
{"r", prnt_rv},
{"R", prnt_rt3},
{NULL, NULL}
};
int n = 0;
while (spcfrs[n].sp)
{
if (*str == spcfrs[n].sp[0])
{
return (spcfrs[n].f);
}
n++;
}
return (NULL);
}
int gt_prnt(char *str, va_list a, prm_t *prm)
{
int (*f)(va_list, prm_t *) = gt_spcfr(str);
if (f)
return (f(a, prm));
return (0);
}
int gt_flag(char *str, prm_t *prm)
{
int n = 0;
switch (*str)
{
case '+':
n = prm->pls_f = 1;
break;
case ' ':
n = prm->spc_f = 1;
break;
case '#':
n = prm->hsh_f = 1;
break;
case '-':
n = prm->min_f = 1;
break;
case '0':
n = prm->z_f = 1;
break;
}
return (n);
}
int gt_mod(char *str, prm_t *prm)
{
int n = 0;
switch (*str)
{
case 'h':
n = prm->h_mod = 1;
break;
case 'l':
n = prm->l_mod = 1;
break;
}
return (n);
}
char *gt_wdth(char *str, prm_t *prm, va_list a)
{
int b = 0;
if (*str == '*')
{
b = va_arg(a, int);
str++;
}
else
{
while (_isdigit(*str))
b = b * 10 + (*str++ - '0');
}
prm->wdth = b;
return (str);
}
