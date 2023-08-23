#include "main.h"
/**
* _isdigit - good
* @n: good
* Return: (0)
*/
int _isdigit(int n)
{
return (n >= '0' && n <= '9');
}
/**
* _strlength - good
* @str: good
* Return: (0)
*/
int _strlength(char *str)
{
int n = 0;
while (*str++)
n++;
return (n);
}
/**
* prnt_num - good
* @string: good
* @prm: good
* Return: (0)
*/
int prnt_num (char*string, prm_t *prm)
{
unsigned int n = _strlength(string);
int ng = (!prm->us && *string == '-');
if (!prm->prcs && *string == '0' && !string[1])
string = "";
if (ng)
{
string++;
n--;
}
if (prm->prcs != UINT_MAX)
while (n++ < prm->prcs)
*--string = '0';
if (ng)
*--string = '-';
if (!prm->min_f)
return (prnt_num_rt(string, prm));
else
return (prnt_num_lt(string, prm));
/**
* prnt_num_rt - good
* @string: good
* @prm: good
*Return: (0)
*/
int prnt_num_rt(char *string, prm_t *prm)
unsigned int i = 0, ng, ng2, n = _strlength(string);
char p_c = ' ';
if (prm->z_f && !prm->min_f)
p_c = '0';
ng = ng2 = (!prm->us && *string == '-');
if (ng && n < prm->wdth && p_c == '0' && !prm->min_f)
string++;
else
ng = 0;
if ((prm->pls_f && !ng2) || (!prm->pls_f && prm->spc_f && ng2))
n++;
if (ng && p_c == '0')
i += _ptchar('-');
if (prm->pls_f && !ng2 && p_c == '0' && !prm->us)
i += _ptchar('+');
else if (!prm->pls_f && prm->spc_f && !ng2 && !prm->us && prm->z_f)
i += _ptchar(' ');
while (n++ < prm->wdth)
i += _ptchar(p_c);
if (ng && p_c == ' ')
i += _ptchar('-');
if (prm->pls_f && !ng2 && p_c == ' ' && !prm->us)
i += _ptchar('+');
else if (!prm->pls_f && prm->spc_f && !ng2 && !prm->us && !prm->z_f)
i += _ptchar(' ');
i += _pt(string);
return (i);
}
/**
* prnt_num_lt - good
* @string: good
* @prm: good
* Return: (0)
*/
int prnt_num_lt(char *string, prm_t prm)
{
unsigned int i = 0, ng, ng2, n = _strlength(string);
char p_c = ' ';
if (prm->z_f && !prm->min_f)
p_c = '0';
ng = ng2 = (!prm->ud && *string == '-');
if(ng && n < prm->wdth && p_c == '0' && !prm->min_f)
string++;
else
ng = 0;
if (prm->pls_f && !ng2 && !prm->us)
i += _ptchar('+'), n++;
else if (prm->spc_f && !ng2 && !prm->us)
i += _ptchar(' ') ,n++;
i += pt(string);
while (n++ < prm->wdth)
i += _ptchar(p_c);
return (i);
}
