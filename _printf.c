#include "main.h"
/**
* _printf - good
* @format: good
* Return: (0)
*/
int _printf(const char *format, ...)
{
int sm = 0;
va_list a;
char *end, *st;
prm_t param = PRMS_I;
va_start(a, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (end = (char*)format; *end; end++)
{
prms(&param, a);
if (*end != '%')
{
sm += _ptchar(*end);
continue;
}
st = end;
end++;
while (gt_flag(end, &param))
{
end++;
}
end = gt_wdth(end, &param, a);
end = gt_prcs(end, &param, a);
if(gt_mod(end, &param))
end++;
if (!gt_spcfr(end))
sm += prnt_frm_t(st, end, param.l_mod || param.h_mod ? end - 1 : 0);
else
sm += gt_prnt(end, a, &param);
}
_ptchar(BF_FLSH);
va_end(a);
return(sm);
}
