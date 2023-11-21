#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
int move, compare;

//버블

void print_array(int arr[], int size) { //과정 출력
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble(int list[], int n) {
    int i, j,temp;
    move = 0;
    compare = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            compare += 1;
            if (list[j] > list[j + i]) {
                SWAP(list[j], list[j + 1], temp);
                move += 1;
                print_array(list, n);
            }
        }
   }
}

void bubble2(int list[], int n) {
    int i, j, temp;
    move = 0;
    compare = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            compare += 1;
            if (list[j] > list[j + i]) {
                SWAP(list[j], list[j + 1], temp);
                move += 1;
                //print_array(list, n);
            }
        }
    }
}
int main(void) {
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("Bubble Sort\n");
    bubble(list, n);

    printf("Move Count: %d\n", move);
    printf("Compare Count: %d\n\n", compare);

    move_count += move;
    compare_count += compare;

    for (j = 1; j <= 19; j++) {
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        printf("Original list\n");
        print_array(list, n);

        printf("BUbble Sort\n");
        bubble2(list, n);
        print_array(list, n);

        move_count += move;
        compare_count += compare;
        printf("\n");

    }
    printf("Average Move Count: %d\n", move_count / 20);
    printf("Average Compare Count: %d\n", compare_count / 20);



    return 0;
}