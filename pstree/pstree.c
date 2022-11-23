#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		assert(argv[i]);
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	DIR* d1 = opendir("/proc/");
	char* s;
	struct dirent* dent1;
	dent1 = readdir(d1);

	while((dent1 = readdir(d1)) !=NULL)
	{
		s = dent1->d_name;
		printf("%s, is_digit = %d, pid = %d\n", s, (strspn(s, "0123456789")==strlen(s)),
		(pid_t) strtol(s, NULL, 10) );


	}

	closedir(d1);
	assert(!argv[argc]);
	return 0;
}
