#include "gen_llist.h"
#include "util.h"

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
