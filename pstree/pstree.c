#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pstree_list.h"

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		assert(argv[i]);
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	DIR* d1 = opendir("/proc/");
	FILE* fp;
	char* s, path[128], comm[128], state;
	struct dirent* dent1;
	int _pid, ppid;
	dent1 = readdir(d1);

	struct pstree_list *head = create_list();
	struct Node node;

	while((dent1 = readdir(d1)) !=NULL)
	{
		s = dent1->d_name;
		pid_t pid = (pid_t) strtol(s, NULL, 10);
		if(pid <=0 ) continue;

		// printf("%s, pid = %d", s, pid);
		sprintf(path, "/proc/%d/stat", pid);
		fp = fopen(path, "r");

		fscanf(fp,"%d %s %c %d", &_pid, comm, &state, &ppid);
		fclose(fp);
		// printf("_pid = %d, comm = %s, state = %c, ppid = %d\n", _pid, comm, state, ppid);
		node.pid = pid;
		node.ppid = ppid;
		strcpy(node.name, comm);
		add_list(head, node);
	}

	closedir(d1);

	print_list(head);

	assert(!argv[argc]);
	return 0;
}
