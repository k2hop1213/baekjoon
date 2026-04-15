#include <stdio.h>
#include <string.h>
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
    if (isEmpty(LQ))return -1;
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

element peekfront(LQueueType* LQ) {
    element item;
    if (isEmpty(LQ))return -1;
    else {
        item = LQ->front->data;
        return item;
    }
}

element peekback(LQueueType* LQ) {
    element item;
    if (isEmpty(LQ))return -1;
    else {
        item = LQ->rear->data;
        return item;
    }
}

void printLQ(LQueueType* LQ) {
    QNode* temp = LQ->front;
    printf("Linked Queue : [");
    while (temp) {
        printf("%c", temp->data);
        temp = temp->link;
    }
    printf("]");
}

int main() {
    LQueueType* LQ = createLinkedQueue();
    int n;
    scanf("%d", &n);
    char buf[10];
    int num;
    int size = 0;
    while (n--) {
        scanf("%s", buf);

        if (strcmp(buf, "push") == 0) {
            scanf("%d", &num);
            enQueue(LQ,num);
            size++;
        }
        else if (strcmp(buf, "pop") == 0) {
            int temp = deQueue(LQ);
            printf("%d\n",temp);
            if (temp > 0) {
                size--;
            }
        }
        else if (strcmp(buf, "size") == 0) {
            printf("%d\n", size);
        }
        else if (strcmp(buf, "empty") == 0) {
            printf("%d\n", isEmpty(LQ));
        }
        else if (strcmp(buf, "front") == 0) {
            printf("%d\n", peekfront(LQ));
        }
        else {
            printf("%d\n", peekback(LQ));
        }
    }



    return 0;
}