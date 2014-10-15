/*
 *  Generic linked list ADT
 *  by Julian Camara 2014
 *  This is an implementation of a linked list that will take as data anything from primitives
 *  to structs. See more details in the README.
 */

#include "gen_llist.h"

#define HEAD (*list)

/* initialise the list head, returns pointer to a node */
node** ll_init_list() {
    node** list = safe_malloc(sizeof **list);
    HEAD = NULL;
    return list;
}

/* add an element in sort order (comparison defined in function passed in) */
bool ll_sorted_insert(node** list, void* data, bool(*cmp_data)(void* data_a, void* data_b)) {
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


/* int datatype functions */

int get_int(void* data) {
    return *(int*)data;
}

void print_int(void* data) {
    printf("%d\n", get_int(data));
}

bool cmp_int(void* data_a, void* data_b){
    int a = get_int(data_a);
    int b = get_int(data_b);
    return a > b ? true : false;
}

void* gen_int_data(int num) {
    int *data = safe_malloc(sizeof *data);
    *data = num;
    return (void*)data;
}

/* end of int datatype */

int main(void) {
    node** list;
    int i;
    void* out;
    
    list = ll_init_list();

    for(i = 0; i < 10; i++) {
        void* data = gen_int_data((i * 7) % 10);

        printf("Inserting: %d\n", get_int(data));
        ll_sorted_insert(list, data, &cmp_int);
    }

    printf("%d nodes inserted.\n", ll_count(list));
    ll_print(list, &print_int);

    ll_delete(list, 0, &get_int);
    ll_delete(list, 5, &get_int); 
    ll_delete(list, 9, &get_int);
    if(!ll_delete(list, 45, &get_int)) {
        printf("Node to delete could not be found\n");
    }
    
    printf("%d nodes left.\n", ll_count(list));
    ll_print(list, &print_int);
    
    out = ll_retrieve(list, 5, &get_int);
    if(out) {
        printf("Node %d found\n", get_int(out));
    } else {
        printf("Id not found\n");
    }

    out = ll_retrieve(list, 7, &get_int);
    if(out) {
        printf("Node %d found\n", get_int(out));
    } else {
        printf("Id not found\n");
    }
    
    ll_destroy(list);
    return 0;
}
