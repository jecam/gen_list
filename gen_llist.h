#include <stdlib.h>
#include "util.h"

typedef struct llist_node node;

/* Generic linked list node */
struct llist_node {
    void* data;
    node* next;
};

/* Supported operations: initialise list, add element, sorted add element, get element, delete element, count */

/* initialise the list head, returns pointer to a node */
node** ll_init_list();
/* add an element in sort order */
bool ll_sorted_insert(node** head, void* data, bool(*cmp_data)(void* data_a, void* data_b));
/* get an element by some sort of id */
void* ll_retrieve(node** head, int id, int(*get_id)(void* data));
/* delete an element */
bool ll_delete(node** head, int id, int(*get_id)(void* data));
/* count elements (list length) */
int ll_count(node** head);
/* print all elements in list order */
void ll_print(node** list, void(*print_fn)(void* data));
/* destroy the whole list */
void ll_destroy(node** head);
/* generate a fresh new node wrapper for data and next pointer */
node* gen_node(void* data);
