#include <stdio.h>
#include <malloc.h>
typedef int element;

struct Data {
    element data;
    element data1;
};

typedef struct DQNode {
    element data;
    element data1;
    struct DQNode* llink;
    struct DQNode* rlink;
} DQNode;

typedef struct {
    DQNode* front, * rear;
} DQueType;

DQueType* createDQue() {
    DQueType* DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isEmpty(DQueType* DQ) {
    return DQ->front == NULL;
}

void insertFront(DQueType* DQ, element item, element item1) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->data1 = item1;
    if (DQ->front == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        DQ->front = newNode;
    }
}

void insertRear(DQueType* DQ, element item, element item1) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->data1 = item1;
    if (DQ->rear == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->rear->rlink = newNode;
        newNode->rlink = NULL;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

struct Data deleteFront(DQueType* DQ) {
    struct Data item;
    if (isEmpty(DQ)) {
        // Handle empty queue (you might want to print an error or handle it differently)
        item.data = item.data1 = -1;  // You can set a default value or handle it differently
    }
    else {
        DQNode* old = DQ->front;
        item.data = old->data;
        item.data1 = old->data1;
        if (DQ->front->rlink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
    }
    return item;
}

struct Data deleteRear(DQueType* DQ) {
    struct Data item;
    if (isEmpty(DQ)) {
        // Handle empty queue (you might want to print an error or handle it differently)
        item.data = item.data1 = -1;  // You can set a default value or handle it differently
    }
    else {
        DQNode* old = DQ->rear;
        item.data = old->data;
        item.data1 = old->data1;
        if (DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
    }
    return item;
}


int main() {
    DQueType* DQ1 = createDQue();

    int n;
    scanf("%d", &n);
    int size = n;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertRear(DQ1, value, i + 1);
    }

    // 터진 풍선의 번호를 저장하는 배열 생성
    int* poppedBalloons = (int*)malloc(sizeof(int) * n);
    int poppedIndex = 0;

    
    struct Data currentValue1 = deleteFront(DQ1);
    poppedBalloons[poppedIndex++] = currentValue1.data1;
    size--;
    // 나머지 풍선을 터뜨리는 과정
    while (size--) {
        int moveAmount = currentValue1.data;  // 이동할 양을 현재 풍선의 값으로 설정
        
        // 터진 풍선과 이동할 양을 고려하여 다음 풍선으로 이동
        if (moveAmount > 0) {
            // 오른쪽으로 이동
            while (moveAmount > 1) {
                currentValue1 = deleteFront(DQ1);  // data 값은 사용하지 않음
                
                insertRear(DQ1, currentValue1.data, currentValue1.data1);
                moveAmount--;
            }
            currentValue1 = deleteFront(DQ1);
        }
        else {
            // 왼쪽으로 이동
            while (moveAmount < -1) {
                currentValue1 = deleteRear(DQ1);  // data 값은 사용하지 않음

                insertFront(DQ1, currentValue1.data, currentValue1.data1);
                moveAmount++;
            }

            currentValue1 = deleteRear(DQ1);
        }

        // 터진 풍선의 번호를 저장
        poppedBalloons[poppedIndex++] = currentValue1.data1;
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", poppedBalloons[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(poppedBalloons);

    return 0;
}
