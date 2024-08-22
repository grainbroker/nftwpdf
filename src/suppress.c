/* Suppress poppler warnings */

#include <glib.h>
#include <stdio.h>


void suppress_poppler_warnings(const gchar *log_domain, GLogLevelFlags log_level,
					const gchar *message, gpointer user_data) {
//	if (log_domain && g_strcmp0(log_domain, "Poppler") == 0) {
		return;  // Suppress the warning
//	}
	//g_log_default_handler(log_domain, log_level, message, user_data);
}
