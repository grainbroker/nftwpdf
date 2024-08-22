#ifndef SUPPRESS_H
#define SUPPRESS_H

#include <glib.h>
#include <stdio.h>

void suppress_poppler_warnings(const gchar *log_domain, GLogLevelFlags log_level, const gchar *message, gpointer user_data);

#endif
