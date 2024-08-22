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

#include "error.h"
#include "suppress.h"
#include "annot_check.h"

int main(int argc, char **argv){


	g_log_set_handler("Poppler", G_LOG_LEVEL_WARNING, suppress_poppler_warnings, NULL);

	char cwd[PATH_MAX];

	if (argc < 2) {
		if (getcwd(cwd, sizeof(cwd)) != NULL){
			if (nftw(cwd, nftw_annot_check, 20, 0) == -1) {
				fprintf(stderr, "Error resolving: %s - %s", cwd, strerror(errno));
				return 1;
			}
		}

	} else for (int i = 0; i < argc; i++){
		char full_path[PATH_MAX];
		if (realpath(argv[i], full_path) == NULL) {
			fprintf(stderr, "Error resolving: %s - %s", argv[i], strerror(errno));
			continue;
		}
		if (nftw(full_path, nftw_annot_check, 20, 0) == -1) {
			fprintf(stderr, "Error traversing: %s - %s", argv[i], strerror(errno));
			continue;
		}
	}

	if ( get_annotations_number() ) exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

