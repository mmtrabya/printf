#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define BF_SIZE 1024
#define BF_FLSH -1
#define NLL_STR "(null)"
#define PRMS_I {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONV_LWR 1
#define CONV_UNS 2
/**
* struct paramets - good
* @us: good
* @pls_f: good
* @spc_f: good
* @hsh_f: good
* @z_f: good
* @min_f: good
* @wdth: good
* @prcs: good
* @h_mod: good
* @l_mod: good
*/
/**
* struct sp - good
* @sp: good
* @f: good
*/
typedef struct paramets
{
unsigned int us : 1;
unsigned int pls_f : 1;
unsigned int spc_f : 1;
unsigned int hsh_f : 1;
unsigned int z_f : 1;
unsigned int min_f : 1;
unsigned int wdth;
unsigned int prcs;
unsigned int h_mod : 1;
unsigned int l_mod : 1;
} prm_t;
typedef struct sp
{
char *sp;
int (*f)(va_list, prm_t *);
} spcfr_t;
int _pt(char *string);
int _ptchar(int ch);
int prnt_chr(va_list a, prm_t *prm);
int prnt_int(va_list a, prm_t *prm);
int prnt_strng(va_list a, prm_t *prm);
int prnt_prcnt(va_list a, prm_t *prm);
int prnt_sc(va_list a, prm_t *prm);
int (*gt_spcfr(char *str))(va_list a, prm_t *prm);
int gt_prnt(char *str, va_list a, prm_t *prm);
int gt_flag(char *str, prm_t *prm);
int gt_mod(char *str, prm_t *prm);
char *gt_wdth(char *str, prm_t *prm, va_list a);
int prnt_frm_t(char *strt, char *stp, char *excpt);
int prnt_rv(va_list a, prm_t *prm);
int prnt_rt3(va_list a, prm_t *prm);
char *conv(long int nm, int bs, int fl, prm_t *prm);
int prnt_uns(va_list a, prm_t *prm);
int prnt_addrss(va_list a, prm_t *prm);
int _isdigit(int n);
int _strlength(char *str);
int prnt_num(char*string, prm_t *prm);
int prnt_num_rt(char *string, prm_t *prm);
int prnt_num_lt(char *string, prm_t *prm);
int prnt_hx(va_list a, prm_t *prm);
int prnt_HX(va_list a, prm_t *prm);
int prnt_bin(va_list a, prm_t *prm);
int prnt_oct(va_list a, prm_t *prm);
void prms(prm_t *prm, va_list a);
char *gt_prcs(char *pr, prm_t *prm, va_list a);
int _printf(const char *format, ...);
#endif
