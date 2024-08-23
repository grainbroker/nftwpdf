#ifndef NFTW_WRAPPERS_H
#define NFTW_WRAPPERS_H

unsigned long get_hl_count();

int nftw_hl_check(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf);
int nftw_hl_print(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf);

#endif
