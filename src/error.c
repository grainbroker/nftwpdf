#include <stdio.h>
#include <stdlib.h>

void pidieffe_error(char *str){
	fprintf(stderr, "%s\n", str);
	exit(EXIT_FAILURE);
}
