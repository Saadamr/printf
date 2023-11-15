#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; /* Move to the next character after % */

            switch (*format) {
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count += snprintf(NULL, 0, "%d", num);
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

