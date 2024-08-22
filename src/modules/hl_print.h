#ifndef HL_PRINT_H
#define HL_PRINT_H

void hl_print(const char *file);
int nftw_hl_print(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf);

#endif
