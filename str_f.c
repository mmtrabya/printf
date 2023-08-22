#include "main.h"
/**
* gt_prcs - good
* @pr: good
* @prm: good
* @a: good
* Return: (0)
*/
char *gt_prcs(char *pr, prm_t *prm, va_list a)
{
int b = 0;
if (*pr != '.')
return (pr);
pr++;
if (*pr == '*')
{
b = va_arg(a, int);
pr++;
}
else
{
while (_isdigit(*pr))
b = b * 10 + (*pr++ - '0');
}
prm->prcs = b;
return (pr);
}
