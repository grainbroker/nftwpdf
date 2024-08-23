#include <glib.h>
#include <stdio.h>


/* TODO check if file or DIR */
/* TODO check PDF MACRO suffix */

#define strip_uri(uri) (uri+7)


/* Suppress poppler warnings */
void suppress_poppler_warnings(const gchar *log_domain, GLogLevelFlags log_level,
					const gchar *message, gpointer user_data) {
		return;
}
