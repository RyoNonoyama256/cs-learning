#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} List;

void list_init(List *list) {
    list->capacity = 4;
    list->size = 0;
    list->data = malloc(sizeof(*(list->data)) * list->capacity);
    if(list->data == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
}

void list_free(List *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void list_append(List *list, int num) {
    if(list->size == list->capacity) {
        list->capacity = list-> capacity * 2;
        int *tmp = realloc(list->data, sizeof(*(list->data)) * list->capacity);
        if(tmp == NULL) {
            fprintf(stderr, "realloc failed\n");
            list_free(list);
            exit(1);
        }
        list->data = tmp;
    }
    (list->data)[list->size] = num;
    ++list->size;
}

void list_insert(List *list, int index, int num) {
    if(list->size == list->capacity) {
        list->capacity = list->capacity * 2;
        int *tmp = realloc(list->data, sizeof(*(list->data)) * list->capacity);
        if(tmp == NULL) {
            fprintf(stderr, "realloc failed\n");
            list_free(list);
            exit(1);
        }
        list->data = tmp;
    }
    for(int i = list->size - 1; i >= index; i--) {
        (list->data)[i + 1] = (list->data)[i];
    }
    (list->data)[index] = num;
    ++(list->size);
}

void list_print(List *list) {
    for(int i = 0; i < list->size; i++) {
        printf("%d ", (list->data)[i]);
    }
    printf("\n");
}

int main(void) {
    List list;
    list_init(&list);

    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 3);
    list_append(&list, 4);
    list_append(&list, 5);
    list_append(&list, 6);

    list_insert(&list, 2, 99);

    list_print(&list);

    list_free(&list);
    return 0;
}
