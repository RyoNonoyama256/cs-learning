#include <stdio.h>
#include <stdlib.h>

void list_append(int **arr, int *size, int *capacity, int num) {
    if(*size >= *capacity) {
        *capacity = *capacity * 2;
        int *tmp = realloc(*arr, sizeof(**arr) * (*capacity));
        if(tmp == NULL) {
            fprintf(stderr, "realloc failed\n");
            free(*arr);
            exit(1);
        }
        
        *arr = tmp;
    }
    (*arr)[*size] = num;
    ++(*size);
}

void list_print(int *arr, int *size) {
    for(int i = 0; i < *size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int capacity = 4;
    int size = 0;
    int *arr = malloc(sizeof(*arr) * capacity);
    if(arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    
    list_append(&arr, &size, &capacity, 1);
    list_append(&arr, &size, &capacity, 2);
    list_append(&arr, &size, &capacity, 3);
    list_append(&arr, &size, &capacity, 4);
    list_append(&arr, &size, &capacity, 5);
    list_append(&arr, &size, &capacity, 6);

    list_print(arr, &size);

    free(arr);
    return 0;
}
