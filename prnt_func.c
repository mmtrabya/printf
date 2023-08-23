#include "main.h"
/**
* prnt_chr -good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_chr(va_list a, prm_t *prm)
{
char p_c = ' ';
unsigned int pd = 1, sm = 0, char = va_arg(a, int);
if (prm->min_f)
sm += _ptchar(char);
while (pd++ < prm->wdth)
sm += _ptchar(p_c);
if (!prm->min_f)
sm += _ptchar(char);
return (sm);
}
/**
* prnt_strng - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_strng(va_list a, prm_t *prm)
{
char *string = va_arg(a, char *), p_c = ' ';
unsigned int pd = 0, sm = 0, n = 0, g;
(void)prm;
switch ((int)(!string))
case 1:
string = NLL_STR;
g = pd = _strlength(string);
if (prm->prcs < pd)
g = pd = prm->prcs;
if (prm->min_f)
{
if (prm->prcs != UINT_MAX)
for (n = 0; n < pd; n++)
sm += _pt(*string++);
else
sm += _pt(string);
}
while (g++ < prm->wdth)
sm += _ptchar(p_c);
if (!prm->min_f)
{
if (prm->prcs != UINT_MAX)
for (n = 0; n < pd; n++)
sm += _ptchar(*string++);
else
sm += _pt(string);
}
return (sm);
}
/**
* prnt_prcnt - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_prcnt(va_list a, prm_t *prm)
{
(void)a;
(void)prm;
return (_ptchar('%'));
}
/**
* prnt_sc - good
* @a: good
* @prm: good
* Return: (0)
*/
int prnt_sc(va_list a, prm_t *prm)
{
char *string = va_arg(a, char*);
char *hx;
int sm = 0;
if ((int)(!string))
return (_pt(NLL_STR));
for (; *string; string++)
{
if ((*string > 0 && *string < 32) || *string >= 127)
{
sm += _ptchar('\\');
sm += _ptchar('x');
hx = conv(*string, 16, 0, prm)
if (!hx[1])
sm += _ptchar('0');
sm += _pt(hx);
}
else
{
sm += _ptchar(*string);
}
}
return (sm);
}
