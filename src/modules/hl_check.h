#ifndef HL_CHECK_H
#define HL_CHECK_H

#include <poppler/glib/poppler.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>


unsigned long get_hl_count();

int nftw_hl_check(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf);

#endif
