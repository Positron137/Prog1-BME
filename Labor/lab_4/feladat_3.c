#include <stdio.h>

int keres_1(int list[], int list_size, int val) {
    for (int i = 0; i < list_size; i++) {
        if (list[i] == val) {
            return i;
        }
    }
    return -1;
}

int *keres_2(int list[], int list_size, int val) {
    for (int i = 0; i < list_size; i++) {
        if (list[i] == val) {
            return &list[i];
        }
    }
    return NULL;
}

int *keres_3(int *list, int list_size, int val) {
    for (int* i = list; i < list + list_size; i++)
    {
        if (*i == val)
        {
            return i;
        }
    }
    
    return NULL;
}

int main(void) {
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int list_size = 10;
    int val = 5;
    int index = keres_1(list, list_size, val);
    int *ptr = keres_2(list, list_size, val);
    int *ptr2 = keres_3(list, list_size, val);
    printf("index: %d\nvalue: %d\n", index, list[index]);
    printf("ptr: %d\nvalue: %d\n", ptr, *ptr);
    printf("ptr2: %d\nvalue: %d\n", ptr2, *ptr2);
    return 0;
}