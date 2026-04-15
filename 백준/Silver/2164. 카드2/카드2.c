#include <stdio.h>
#include <malloc.h>
typedef int element;
typedef struct QNode {
    element data;
    struct QNode* link;
}QNode;

typedef struct {
    QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue() {
    LQueueType* LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) {

        return 1;
    }
    return 0;
}

void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

element deQueue(LQueueType* LQ) {
    QNode* old = LQ->front;
    element item;
    if (isEmpty(LQ))return 0;
    else {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL) {
            LQ->rear = NULL;
        }
        free(old);
        return item;
    }
}

element peek(LQueueType* LQ) {
    element item;
    if (isEmpty(LQ))return 0;
    else {
        item = LQ->front->data;
        return item;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    LQueueType* LQ = createLinkedQueue();
    int size = n;
    for (int i = 1; i <= n; i++) {
        enQueue(LQ,i);
    }
    while (size > 1) {
        deQueue(LQ);
        size--;
        int temp = deQueue(LQ);
        size--;
        enQueue(LQ, temp);
        size++;
    }
    printf("%d", deQueue(LQ));
    return 0;
}