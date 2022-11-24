#ifndef _PSTREE_LIST_H
#define _PSTREE_LIST_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    pid_t pid, ppid;
	char name[128];
};

struct pstree_list
{
	struct Node node;
	struct pstree_list* next;
};

typedef struct _proc
{
    struct Node node;
    PROC *next, *parent;
    CHILD* children;
}PROC;

typedef struct _child
{
    PROC* child;
    CHILD *next;
}CHILD;


struct pstree_list* create_list();
void add_list(struct pstree_list* head, struct Node node);
void print_list(struct pstree_list* head);
void destory_list(struct pstree_list* head);

#endif