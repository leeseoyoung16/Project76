#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int n;
int move, compare;

//버블

void print_array(int arr[], int size) { //과정 출력
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble(int list[], int n) {
    int i, j, temp;
    move = 0;
    compare = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            compare += 1;  // 한 칸씩 뒤로 가며 한 번씩 비교
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                move += 1;  // 비교 후 조건 달성 시 이동
            }
        }
        print_array(list, n);  // 배열 전체 순회마다 1회 출력
    }
}


void bubble2(int list[], int n) { // 중간 과정 출력 생략
    int i, j, temp;
    move = 0;
    compare = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            compare += 1;  
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                move += 1;  
            }
        }
       //print_array(list, n);  
    }
}

int main(void) {
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    n = MAX_SIZE;
    int list[MAX_SIZE];

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("Bubble Sort\n");
    bubble(list, n);

    move_count += move;
    compare_count += compare;

    for (j = 1; j <= 19; j++) { //19번 반복
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        
        bubble2(list, n);

        move_count += move;
        compare_count += compare;

    }
    //평균
    printf("Average Move Count: %d\n", move_count / 20);
    printf("Average Compare Count: %d\n", compare_count / 20);



    return 0;
}