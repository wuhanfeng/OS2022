#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		assert(argv[i]);
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	DIR* d1 = opendir("/proc/");
	struct dirent* dent1;
	dent1 = readdir(d1);

	while((dent1 = readdir(d1)) !=NULL)
	{
		printf("%s\n", dent1->d_name);
	}

	closedir(d1);
	assert(!argv[argc]);
	return 0;
}
