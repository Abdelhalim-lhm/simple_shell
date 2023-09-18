#include "shell.h"

/**
 * print - Custom printf-like function .
 * @format: The format string with optional %d and %s specifiers.
 * @...: Additional arguments corresponding to %d and %s specifiers.
 */
void print(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	const char *ptr = format;

	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
				break;
			if (*ptr == 'd')
				printf("%d", va_arg(args, int));
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
					printf("%s", str);
				else
					printf("(null)");
			}
			else
			{
				putchar('%');
				putchar(*ptr);
			}
		}
		else
		{
			putchar(*ptr);
		}
		ptr++;
	}
	va_end(args);
}
