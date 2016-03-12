#include <stdarg.h>

static void
serial_out_hex (volatile int *out, unsigned int n)
{
  static char *digit = "0123456789abcdef";
  int i;

  for (i = 7; i >= 0; i--)
    *out = digit[(n >> (4 * i)) & 15];
}

static void
serial_out_chars (volatile int *out, int n, char c)
{
  while (n-- > 0)
    *out = c;
}

static void
serial_out_str (volatile int *out, char *s, int left, int field)
{
  char *p;
  int len;

  if (s == 0)
    s = "<NULL>";

  if (field)
    {
      for (p = s, len = 0; *p; p++)
	len++;

      if (!left)
	serial_out_chars (out, field - len, ' ');

      while (*s)
	*out = *s++;

      if (left)
	serial_out_chars (out, field - len, ' ');
    }
  else
    {
      while (*s)
	*out = *s++;
    }
}

void
serial_out_dec (volatile int *out, int n, int is_signed, int left, int field)
{
  char buff[40], *s = &buff[39];
  unsigned int un, negative;

  if (is_signed && n < 0)
    {
      negative = 1;
      un = (unsigned int) -n;
    }
  else
    {
      negative = 0;
      un = (unsigned int) n;
    }

  *s = '\0';

  do
    {
      *(--s) = '0' + un % 10;
      un /= 10;
    }
  while (un > 0);

  if (negative)
    *(--s) = '-';

  serial_out_str (out, s, left, field);
}

static void
formated_out (volatile int *out, char *format, va_list arg_list)
{
  int field, left;

  if (format == 0)
    format = "<NULL>";

  while (*format)
    {
      if (*format != '%')
	{
	  *out = *format++;
	  continue;
	}

      format++;

      if (*format == '-')
	{
	  format++;
	  left = 1;
	}
      else
	left = 0;

      field = 0;
      while (*format >= '0' && *format <= '9')
	field = 10 * field + *format++ - '0';

      switch (*format)
	{
	case 's':
	  serial_out_str (out, va_arg (arg_list, char *), left, field);
	  break;
	case 'u':
	  serial_out_dec (out, va_arg (arg_list, int), 0, left, field);
	  break;
	case 'd':
	  serial_out_dec (out, va_arg (arg_list, int), 1, left, field);
	  break;
	case 'x':
	  serial_out_hex (out, va_arg (arg_list, int));
	  break;
	case 'p':
	  serial_out_hex (out, va_arg (arg_list, int));
	  break;
	case 'c':
	  *out = va_arg (arg_list, int);
	  break;
	case '%':
	  *out = *format;
	  break;
	default:
	  *out = '%';
	  *out = *format;
	  (void) va_arg (arg_list, int);
	  break;
	}

      format++;
    }
}

int
printf (char *format, ...)
{
  va_list arg_list;

  va_start (arg_list, format);

  formated_out ((volatile int *) 0xb0c2000c, format, arg_list);

  va_end (arg_list);

  return 0;
}
