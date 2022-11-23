#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s)
{
	size_t len = 0;
	char *p = (char*)s;
	while (*p++ != '\0')
		len++;
	return len;
	// panic("Not implemented");
}

char *strcpy(char *dst, const char *src)
{
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return dst;
	// panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dst[i] = src[i];
	for (; i < n; i++)
		dst[i] = '\0';
	return dst;
	// panic("Not implemented");
}

char *strcat(char *dst, const char *src)
{
	size_t dest_len = strlen(dst);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dst[dest_len + i] = src[i];
	dst[dest_len + i] = '\0';

	return dst;
	// panic("Not implemented");
}

int strcmp(const char *s1, const char *s2)
{
	int ret = 0;
	while ( *s2 && !(ret = *s1 - *s2) ) //相等且没有结束
		++s1, ++s2;
	return (ret);
	// panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	int ret = 0;
	while ( *s2 && n-- && !(ret = *s1 - *s2)) //相等且没有结束
		++s1, ++s2;
	return (ret);
	// panic("Not implemented");
}

void *memset(void *s, int c, size_t n)
{
	size_t i;
	char* p_s = (char*)s;
	for(i = 0; i < n; i ++)
		p_s[i] = (char)c;
	return s;
	// panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n)
{
	char* p_out = (char*)dst;
	char* p_in = (char*)src;
	if(src >= dst)
	{
		while(n --) *p_out++ = *p_in++;
	}
	else
	{
		p_out += n; p_in += n;
		while(n --) *p_out-- = *p_in--;
	}
	return dst;
	// panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n)
{
	// size_t i;
	char* p_out = (char*)out;
	char* p_in = (char*)in;
	while(n --) *p_out++ = *p_in++;
	return out;
	// panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	int ret = 0;
	char *p_s1 = (char*)s1;
	char *p_s2 = (char*)s2;
	while ( n-- && !(ret = *p_s1 - *p_s2) ) //相等且没有结束
		++p_s1, ++p_s2;
	return (ret);
	// panic("Not implemented");
}

#endif
