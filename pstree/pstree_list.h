#ifndef _PSTREE_LIST_H
#define _PSTREE_LIST_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    struct _proc *next, *parent;
    struct _child *children;
}PROC;

typedef struct _child
{
    struct _proc *child;
    struct _child *next;
}CHILD;


void add_proc(struct Node node);


struct pstree_list* create_list();
void add_list(struct pstree_list* head, struct Node node);
void print_list(struct pstree_list* head);
void destory_list(struct pstree_list* head);

#endif