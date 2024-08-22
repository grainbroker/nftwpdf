#ifndef ANNOT_CHECK_H
#define ANNOT_CHECK_H

#include <poppler/glib/poppler.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>


unsigned long get_annotations_number();

int annot_check(const char *file);
int nftw_annot_check(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf);

#endif
