#include <stdio.h>

int LinearSearch(int array[], int size, int element) {
    for(int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
        return -1;
}

int BinarySearch(int array[], int size, int element) {
    int high = size - 1, mid, low = 0;

    while (low <= high) {
        mid = (high + low) / 2;
        if (array[mid] == element) {
            return mid;
        }

        if (array[mid] < element) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int array[] = {56, 87, 25, 96, 24, 75, 56, 64, 73};
    int element, size = sizeof(array) / sizeof(int);
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int ReturnIndex = LinearSearch(array, size, element);
    printf("The element %d is found at index %d\n", element, ReturnIndex);
    int ArraySorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int Size = sizeof(ArraySorted) /sizeof(int);
    printf("Enter the element to search: ");
    scanf("%d", &element);
    ReturnIndex = BinarySearch(ArraySorted, Size, element); 
    printf("Element %d found at index %d\n", element, ReturnIndex);
    return 0;
}

