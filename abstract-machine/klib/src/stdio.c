#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char *get_parse_out_d(int d, char *p_out)
{
	int len = 0, tmp[20];
	
	if (d == 0)
	{
		*p_out++ = '0';
	}
	else if (d > 0)
	{
		len = 0;
		while (d)
		{
			tmp[len++] = d % 10 + '0';
			d /= 10;
		}
		while (len--)
			*p_out++ = tmp[len];
	}
	else
	{
		*p_out++ = '-';
		d = -d;
		len = 0;
		while (d)
		{
			tmp[len++] = d % 10 + '0';
			d /= 10;
		}
		while (len--)
			*p_out++ = tmp[len];
	}
	return p_out;
}

static char *get_parse_out_x(unsigned int d, char* p_out)
{
	unsigned int len = 0, tmp[20];
	
	if (d == 0)
	{
		*p_out++ = '0';
	}
	else
	{
		len = 0;
		while (d)
		{
			tmp[len++] = d % 16;
			d /= 16;
		}
		while (len--)
			if (tmp[len] < 10)
				*p_out++ = tmp[len] + '0';
			else
				*p_out++ = tmp[len] + 'a' - 10;
	}
	return p_out;
}


static char *get_parse_out_p(unsigned int* pd, char *p_out)
{
	unsigned int len = 0, tmp[20];
	
	// pd = va_arg(ap, unsigned int*);
	uintptr_t d = (uintptr_t)pd;
	*p_out++ = '0';
	*p_out++ = 'x';
	if (d == 0)
	{
		*p_out++ = '0';
	}
	else
	{
		len = 0;
		while (d)
		{
			tmp[len++] = d % 16;
			d /= 16;
		}
		while (len--)
			if (tmp[len] < 10)
				*p_out++ = tmp[len] + '0';
			else
				*p_out++ = tmp[len] + 'a' - 10;
	}
	return p_out;
}

static char* get_parse_out_s(char* s, char *p_out)
{
	// s = va_arg(*ap, char *);
	while (*s)
		*p_out++ = *s++;
	return p_out;
}

static char *get_parse_out_ld(__uint64_t ld, char* p_out)
{
	int len = 0, tmp[20];
	
	len = 0;
	while (ld)
	{
		tmp[len++] = ld % 10 + '0';
		ld /= 10;
	}
	while (len--)
		*p_out++ = tmp[len];
	return p_out;
}

static int parse_para(char *out, const char *fmt, va_list ap)
{
	char c, *p_out = (char *)out;
	// va_list tmp_ap = *ap;
	char *s;
	int d;
	unsigned int* pd;
	unsigned int ud;
	__uint64_t ld;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			switch (*fmt++)
			{
			case 's': /* string */
				s = va_arg(ap, char *);
				p_out = get_parse_out_s(s, p_out);
				break;
			case 'd': /* int */
				d = va_arg(ap, int);
				p_out = get_parse_out_d(d, p_out);
				break;
			case 'p':
				pd = va_arg(ap, unsigned int*);
				p_out = get_parse_out_p(pd, p_out);
				break;
			case 'x':
				ud = va_arg(ap, unsigned int);
				p_out = get_parse_out_x(ud, p_out);
				break;
			case 'l':
				switch (*fmt++)
				{
				case 'd':
					ld = va_arg(ap, __uint64_t);
					p_out = get_parse_out_ld(ld, p_out);
					break;
				default:
					break;
				}
				break;
			case 'c': /* char */
				c = (char)va_arg(ap, int);
				*p_out++ = c;
				break;
			}
		}
		else
			*p_out++ = *fmt++;
	}
	*p_out++ = '\0';
	return 0;
}

int printf(const char *fmt, ...)
{
	char out[2048];
	va_list ap;
	va_start(ap, fmt);
	parse_para(out, fmt, ap);
	va_end(ap);
	putstr(out);
	return 0;
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
	panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	parse_para(out, fmt, ap);
	va_end(ap);
	return 0;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
	panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
	panic("Not implemented");
}

#endif
