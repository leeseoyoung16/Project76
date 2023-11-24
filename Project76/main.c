#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int n;
int move, compare;

//����

void print_array(int arr[], int size) { //���� ���
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
            compare += 1;  // �� ĭ�� �ڷ� ���� �� ���� ��
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                move += 1;  // �� �� ���� �޼� �� �̵�
            }
        }
        print_array(list, n);  // �迭 ��ü ��ȸ���� 1ȸ ���
    }
}


void bubble2(int list[], int n) { // �߰� ���� ��� ����
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

    for (j = 1; j <= 19; j++) { //19�� �ݺ�
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        
        bubble2(list, n);

        move_count += move;
        compare_count += compare;

    }
    //���
    printf("Average Move Count: %d\n", move_count / 20);
    printf("Average Compare Count: %d\n", compare_count / 20);



    return 0;
}