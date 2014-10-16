/*
 *  Generic linked list ADT
 *  by Julian Camara 2014
 *  This is an implementation of a linked list that will take as data anything 
 *  from primitives to structs. See more details in the README.
 */

#ifndef GEN_LLIST
#define GEN_LLIST

#include "gen_llist.h"

#define HEAD (*list)

/* initialise the list head, returns pointer to a node */
node** ll_init_list() {
    node** list = safe_malloc(sizeof **list);
    HEAD = NULL;
    return list;
}

/* add an element in sort order (comparison defined in function passed in) */
bool ll_sorted_insert(node** list, void* data, 
                      bool(*cmp_data)(void* data_a, void* data_b)) {
    node* new_node = gen_node(data);
    node* curr, * prev;
    
    if(!HEAD) {
        HEAD = new_node;
        return true;
    }

    curr = HEAD;
    prev = NULL;

    while(curr && cmp_data(data, curr->data)) {
        prev = curr;
        curr = curr->next;
    }

    new_node->next = curr;
    if(!prev) {
        HEAD = new_node;
    } else { 
        prev->next = new_node;
    }
          
    return true;
}

/* create a new node from a void pointer */
node* gen_node(void* data) {
    node* node = safe_malloc(sizeof *node);
    node->data = data;
    node->next = NULL;
    return node;
}

/* get an element by id (defined in function passed in) */
void* ll_retrieve(node** list, int id, int(*get_id)(void* data)) {
    node* curr = HEAD;
    while(curr != NULL && get_id(curr->data) != id) {
        curr = curr->next;
    }
    if(curr) {
        return curr->data;
    } else {
        return NULL;
    }
}

/* delete an element by id (defined in function passed in) */
bool ll_delete(node** list, int id, int(*get_id)(void* data)) {
    node *curr, *prev;

    prev = NULL;
    curr = HEAD;

    while(curr->next && get_id(curr->data) != id) {
        prev = curr;
        curr = curr->next;
    }

    if(get_id(curr->data) != id) {
        return false;
    } else {
        if(!prev) {
            HEAD = curr->next;
        } else {
            prev->next = curr->next;
        }
        curr->next = NULL;
        free(curr->data);
        free(curr);
        return true;
    }
}

/* count elements (list length) */
int ll_count(node** list) {
    node* curr = HEAD;
    int count = 0;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}

/* print all elements in list order */
void ll_print(node** list, void(*print_fn)(void* data)) {
    node* curr = HEAD;
    while(curr) {
        print_fn(curr->data);
        curr = curr->next;
    }
}

/* free all elements, call before program ends */
void ll_destroy(node** list) {
    node* curr = HEAD;
    node* prev = NULL;
    while(curr) {
        prev = curr;
        curr = curr->next;
        free(prev->data);
        free(prev);
    }
    free(list);
}

/* end of linked list definitions */

#endif
