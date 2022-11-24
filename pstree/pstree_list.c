
#include "pstree_list.h"


// struct pstree_list pstree_list[];
struct pstree_list* create_list()
{
    struct pstree_list* head = malloc(sizeof(struct pstree_list));
    return head;
}

void add_list(struct pstree_list* head, struct Node node)
{
    struct pstree_list* p = malloc(sizeof(struct pstree_list));
    struct pstree_list* p_tmp = head;
    if(p)
    {
        p->node = node;
        while(p_tmp->next) p_tmp = p_tmp->next;
        p_tmp->next = p;
        p->next = NULL;
    }
}

void print_list(struct pstree_list* head)
{
    struct pstree_list* p = head;
    while (p)
    {
        printf("Node = %p, pid = %d, ppid = %d, name = %d\n", 
            p, p->node.pid, p->node.ppid, p->node.name);
        p = p->next;
    }
}


void destory_list(struct pstree_list* head)
{
    struct pstree_list* p = head;
    if(p)
    {
        free(p);
        p = p->next;
    }
}



