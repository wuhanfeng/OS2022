#include "pstree_list.h"

static PROC *list = NULL;

static PROC* find_proc(pid_t pid)
{
    PROC* walk;
    for(walk = list; walk; walk = walk->next)
    {
        if(walk->node.pid == pid) return walk;
    }
    return NULL;
}

// static PROC* create_proc
static void add_child(PROC* parent, PROC* child)
{
    CHILD *new, **walk;
    new = malloc(sizeof(CHILD));
    new->child = child;
    new->next = parent->children;
    parent->children = new;
}

PROC* new_proc(struct Node node)
{
    PROC* new;
    new = malloc(sizeof(PROC));
    new->node = node;
    new->children = NULL;
    new->next = NULL;
    new->parent = NULL;
    list = new;
    return list;
}

static void rename_proc(PROC* this, struct Node node)
{
    this->node = node;
}

void add_proc(struct Node node)
{
    PROC* this;
    struct Node parent_node;

    if( (this = find_proc(node.pid)) != NULL )
    {
        rename_proc(this, node);
    }
    else
    {
        this = new_proc(node);
        this->next = list;
        list = this;
    }
    // add the parent
    PROC* parent;
    if( (parent = find_proc(node.ppid)) == NULL )
    {
        // parent = 
        parent_node.pid = node.ppid;
        strcpy(parent_node.name, "???");
        parent = new_proc(parent_node);
        parent->next = list;
        list = parent;
    }
    this->parent = parent;

    add_child(parent, this);

}


