#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int sorted[MAX_SIZE];
int n;
int move, compare;

void print_array(int arr[], int size) { // 배열 출력 함수
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int list[], int left, int right, int print) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do {
            low++;
            compare++;
        } while (list[low] < pivot);
        do {
            high--;
            compare++;
        } while (list[high] > pivot);
        if (low < high) {
            SWAP(list[low], list[high], temp);
            move++;
        }
    } while (low < high);
    move++;
    SWAP(list[left], list[high], temp);
    if (print == 0) {
        print_array(list, n);
    }
    return high;
}

void quick_sort(int list[], int left, int right, int print) { // 퀵 정렬 함수
    int mid;
    if (left < right) {
        int q = partition(list, left, right, print);
        quick_sort(list, left, q - 1, print);
        quick_sort(list, q + 1, right, print);
    }
}

void quick_sort_iter(int list[], int left, int right, int print) { // 반복적인 퀵 정렬
    int stack[MAX_SIZE];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0) {
        right = stack[top--];
        left = stack[top--];

        int q = partition(list, left, right, print);

        if (q - 1 > left) {
            stack[++top] = left;
            stack[++top] = q - 1;
        }

        if (q + 1 < right) {
            stack[++top] = q + 1;
            stack[++top] = right;
        }
    }
}

int main(void) {
    int list[MAX_SIZE];
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    double count = 1; 

    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("\nQuick Sort iter\n");
    quick_sort_iter(list, 0, n - 1, 0);
    //printf("\nQuick Sort\n");
    //quick_sort(list, 0, n - 1, 0);

    move_count += move;
    compare_count += compare;

    for (j = 1; j <= 19; j++) {
        move = 0;
        compare = 0;
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        quick_sort(list, 0, n - 1, 1);

        move_count += move;
        compare_count += compare;
        count++;
    }
    printf("Average Move Count: %lf\n", (double)move_count / count);
    printf("Average Compare Count: %lf\n", (double)compare_count / count);

    return 0;
}
