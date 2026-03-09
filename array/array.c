#include <stdio.h>

int main(void) {
    int arr[4] = {1, 2, 3, 4};
    arr[2] = 10;

    for(int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}