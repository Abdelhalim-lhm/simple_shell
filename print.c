#include "shell.h"

/**
 * print - Custom printf-like function.
 * @format: The format string with optional %d and %s specifiers.
 * @...: Additional arguments corresponding to %d and %s specifiers.
 */
void print(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'd')
			{
				char buffer[32];
				int num = va_arg(args, int);
				int len = snprintf(buffer, sizeof(buffer), "%d", num);

				write(1, buffer, len);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
					write(1, str, strlen(str));
				else
					write(1, "(null)", 6);
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
			}
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(args);
}
