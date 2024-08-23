#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <poppler/glib/poppler.h>
#include <glib.h>

#include <../utils.h>


static inline void print_highlights(const char *path, PopplerPage *page, GList *annotations) {
	for (GList *l = annotations; l != NULL; l = l->next) {
		PopplerAnnotMapping *annot_mapping = (PopplerAnnotMapping *)l->data;
		PopplerAnnot *annot = annot_mapping->annot;

		if (poppler_annot_get_annot_type(annot) == POPPLER_ANNOT_HIGHLIGHT) {
			PopplerRectangle area;
			poppler_annot_get_rectangle(annot, &area);

			char *highlight_text = poppler_page_get_text_for_area(page, &area);
			if (highlight_text && highlight_text[0] != '\0') {
				printf("%s: %s\n", strip_uri(path), highlight_text);
			}
			g_free(highlight_text);
		}
	}
}

static void hl_print(const char *file){
	GError *error = NULL;
	PopplerDocument *document = poppler_document_new_from_file(file, NULL, &error);
	int num_pages;

	if (!document) {
		g_error_free(error);
		return;
	}

	num_pages = poppler_document_get_n_pages(document);

	for (int i = 0; i < num_pages; i++){
		PopplerPage *page = poppler_document_get_page(document, i);

		if(!page) continue;

		GList *annotations = poppler_page_get_annot_mapping(page);

		print_highlights(file, page, annotations);

		g_list_free_full(annotations, (GDestroyNotify)poppler_annot_mapping_free);
		g_object_unref(page);
	}

	g_object_unref(document);
}


/* wrapper for ntfw syscall */
int nftw_hl_print(const char *fpath, const struct stat *sb, int typeflag,
							struct FTW *ftwbuf){
	char uri[PATH_MAX + 7];
	snprintf(uri, sizeof(uri), "file://%s", fpath);

	if ((typeflag == FTW_F && strstr(fpath, ".pdf") != NULL))
	hl_print(uri);


	return 0;
}
