/*
 * setlocale, localeconv : internationalize your locale.
 *                         (Only "C" or null supported).
 */

#include <locale.h>
#include <string.h>
#include <limits.h>

static struct lconv lconv = {
  ".", "", "", "", "", "", "", "", "", "",
  CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
  CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
};

char *
setlocale(int category, const char * locale)
{
  if (locale && strcmp(locale, "C") && strcmp(locale, ""))
    return(NULL);
  return("C");
}


struct lconv *
  localeconv(void)
{
  return(&lconv);
}
