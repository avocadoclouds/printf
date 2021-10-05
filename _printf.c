<<<<<<< HEAD
#include "main.h"

/**
 * print_op - check which specifier to print
 * @format: string being passed
 * @print_arr: array of structed ops
 * @list: list of arguments to print
 *
 * Return: number of characters printed
 */
int _printop(const char *format, fmt_t *print_arr, va_list list)
{
  char a;
  int count = 0, b = 0, c = 0;

  a = format[b];
  while (a != '\0')
    {
      if (a == '%')
	{
	  c = 0;
	  b++;
	  a = format[b];
	  while (print_arr[c].type != NULL && a != *(print_arr[c].type))
	    c++;
	  if (print_arr[c].type != NULL)
	    count = count + print_arr[c].f(list);
	  else
	    {
	      if (a == '\0')
		return (-1);
	      if (a != '%')
		count += _putchar('%');
	      count += _putchar(a);
	    }
	}
      else
	count += _putchar(a);
      b++;
      a = format[b];
    }
  return (count);
}

/**
 * _printf - prints output according to format
 * @format: string being passed
 *
 * Return: character to be printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int a = 0;

	fmt_t ops[] = {
		{"c", ch},
		{"s", str},
		{"d", _int},
		{"b", _bin},
		{"i", _int},
		{"u", _ui},
		{"o", _oct},
		{"x", _hex_l},
		{"X", _hex_u},
		{"R", _rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
	a = print_op(format, ops, list);
	va_end(list);
	return (a);
=======
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* find_function - function that finds formats for _printf
* calls the corresponding function.
* @format: format (char, string, int, decimal)
* Return: NULL or function associated ;
*/
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
* _printf - function that produces output according to a format.
* @format: format (char, string, int, decimal)
* Return: size the output text;
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
>>>>>>> a44837781f11007a97a25295396637dc995434db
}
