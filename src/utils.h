#ifndef UTILS_H
#define UTILS_H

#define NFTW_FD_DEFAULT 28

/* strip first 7 char from the uri string */
#define strip_uri(uri) (uri+7)

#define is_pdf(str) (1)

void suppress_poppler_warnings(const gchar *log_domain, GLogLevelFlags log_level, const gchar *message, gpointer user_data);

#endif
