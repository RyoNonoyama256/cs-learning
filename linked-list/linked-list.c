#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct {
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
} LinkedList;

LinkedListNode* node_init(int num) {
    LinkedListNode *node = malloc(sizeof(*node));
    if(node == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    }
    node->data = num;
    node->next = NULL;
    return node;
}

void list_free(LinkedList *list) {
    LinkedListNode *now = list->head;
    while(now) {
        LinkedListNode *next = now->next;
        free(now);
        now = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

LinkedList list_init() {
    LinkedList list = {NULL, NULL, 0};
    return list;
}

void list_append(LinkedList *list, int num) {
    LinkedListNode *node = node_init(num);
    if(list->tail == NULL) {
        list->head = node;
    }
    else {
        list->tail->next = node;
    }
    list->tail = node;
    ++(list->size);
}

void list_print(LinkedList *list) {
    LinkedListNode *now = list->head;
    while(now) {
        printf("%d ", now->data);
        now = now->next;
    }
    printf("\n");
}

int main(void) {
    LinkedList list = list_init();
    
    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 3);
    list_append(&list, 4);
    list_print(&list);
    
    list_free(&list);
    return 0;
}
