#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <glib.h>
#include <poppler/glib/poppler.h>

#include "utils.h"
#include "nftw_wrappers/nftw_wrappers.h"

int main(int argc, char **argv){

	char cwd[PATH_MAX];


	int check_flag = 0;
	int opt;

	int (*nftw_func)(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf);
	nftw_func = &nftw_hl_check;

	/* Default case */

	char **rargs;
	char full_path[PATH_MAX];


	while((opt = getopt(argc, argv, "ch")) != -1){
		switch(opt){
			default:
				/* fall through */
			case 'c':
				nftw_func = &nftw_hl_check;
				check_flag = 1;
				break;
			case 'h':
				nftw_func = &nftw_hl_print;
				break;
			case '?':
				fprintf(stderr, "Unknown option: -%c\n", optopt);
				exit(EXIT_FAILURE);
		}
	}

	if (optind == argc) {
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			if (nftw(cwd, nftw_func, NFTW_FD_DEFAULT, 0) == -1){
				fprintf(stderr, "Error traversing: %s -- %s", cwd, strerror(errno));
				exit(EXIT_FAILURE);
			}
		} else {
			fprintf(stderr, "could not get current working directory: %s -- %s", cwd, strerror(errno));
			exit(EXIT_FAILURE);
		}
	} else for (int i = optind; i < argc; i++){
		if(realpath(argv[i], full_path) == NULL ){
			fprintf(stderr, "Error resolving: %s -- %s", argv[i], strerror(errno));
			continue;
		}

		if (nftw(full_path, nftw_func, NFTW_FD_DEFAULT, 0) == -1){
			fprintf(stderr, "Error traversing: %s -- %s", argv[i], strerror(errno));
			continue;
		}
	}

	if ( check_flag )
		if ( get_hl_count() ) exit(EXIT_SUCCESS);
		else exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
