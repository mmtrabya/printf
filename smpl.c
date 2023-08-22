#include "main.h"
/**
 * prnt_frm_t - good
 * @strt: good
 * @stp: good
 * @excpt: good
 * Return (0)
*/
int prnt_frm_t(char *strt, char *stp, char *excpt)
{
int plus = 0;
while (strt <= stp)
{
if (strt != excpt)
plus += _ptchar(*strt);
strt++;
}
return (plus);
}
/**
 * prnt_rv
 * @a: good
 * @prm: good
*/
int prnt_rv(va_list a, prm_t *prm)
{
int l, plus = 0;
char *string = va_arg(a, char*);
(void)prm;
if (string)
{
for (l = 0; *string; string++)
l++;
for (; l > 0; l--, string--)
plus += _ptchar(*string);
}
return (plus);
}
/**
 * prnt_rt3 - good
 * @a: good
 * @prm: good
*/
int prnt_rt3(va_list a, prm_t *prm)
{
int n, ind;
int cnt = 0;
char array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
char *alpha = va_arg(a, char*);
(void)prm;
n = 0;
ind = 0;
while (alpha[n])
{
if ((alpha[n] >= 'A' && alpha[n] <= 'Z') || (alpha[n] >= 'a' && alpha[n] <= 'z'))
{
ind = alpha[n] - 65;
cnt += _ptchar(array[ind]);
}
else
cnt += _ptchar(alpha[n]);
n++;
}
return (cnt);
}
