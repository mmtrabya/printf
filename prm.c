#include "main.h"
/**
 * prms - good
 * @prm: good
 * @a: good
*/
void prms(prm_t *prm, va_list a)
{
prm->us = 0;
prm->pls_f = 0;
prm->spc_f = 0;
prm->z_f = 0;
prm->hsh_f = 0;
prm->min_f = 0;
prm->wdth = 0;
prm->prcs = UINT_MAX;
prm->h_mod = 0;
prm->l_mod = 0;
(void)a;
}
