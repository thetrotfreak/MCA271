#ifndef LIST_H
#define LIST_H

typedef struct List {
    int data;
    struct List *next;
} List;

extern List *head;
extern List *tail;

extern unsigned int length;

/*
 * Porcelain functions
 * High level list operations
 */
void list_new ();
void list_prepend(int);
void list_append(int);
void list_insert (unsigned int, int);
void list_del ();

/*
 * Plumbing functions
 * Low level functions consumed by Porcelain list functions
 */
static List *_new_node ();
static void _link_update (List *, List *);

#endif // LIST_H