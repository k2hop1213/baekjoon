#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef int element;
typedef struct DQNode {
    element data;
    struct DQNode* llink;
    struct DQNode* rlink;
}DQNode;

typedef struct {
    DQNode* front, * rear;
}DQueType;

DQueType* createDQue() {
    DQueType* DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isEmpty(DQueType* DQ) {
    if (DQ->front == NULL) {
        
        return 1;
    }
    return 0;
}

void insertFront(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
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

void insertRear(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
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

element deleteFront(DQueType* DQ) {
    DQNode* old = DQ->front;
    element item;
    if (isEmpty(DQ))return -1;
    else {
        item = old->data;
        if (DQ->front->rlink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    }
}

element deleteRear(DQueType* DQ) {
    DQNode* old = DQ->rear;
    element item;
    if (isEmpty(DQ))return -1;
    else {
        item = old->data;
        if (DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

element peekFront(DQueType* DQ) {
    element item;
    if (isEmpty(DQ))return -1;
    else {
        item = DQ->front->data;
        return item;
    }
}

element peekRear(DQueType* DQ) {
    element item;
    if (isEmpty(DQ))return -1;
    else {
        item = DQ->rear->data;
        return item;
    }
}

void printDQ(DQueType* DQ) {
    DQNode* temp = DQ->front;
    printf("DeQue : [");
    while (temp) {
        printf("%c", temp->data);
        temp = temp->rlink;
    }
    printf("]");
}

int main() {
    DQueType* DQ1 = createDQue();
    int n;
    scanf("%d", &n);
    char buf[11];
    int num = 0;
    int size = 0;
    while (n--) {
        scanf("%s", buf);
        if (strcmp(buf, "push_front") == 0) {
            scanf("%d", &num);
            insertFront(DQ1, num);
            size++;
        }
        else if (strcmp(buf, "push_back") == 0) {
            scanf("%d", &num);
            insertRear(DQ1, num);
            size++;
        }
        else if (strcmp(buf, "pop_front") == 0) {
            int temp = deleteFront(DQ1);
            printf("%d\n", temp);
            if (temp > 0) {
                size--;
            }
        }
        else if (strcmp(buf, "pop_back") == 0) {
            int temp = deleteRear(DQ1);
            printf("%d\n", temp);
            if (temp > 0) {
                size--;
            }
        }
        else if (strcmp(buf, "size") == 0) {
            printf("%d\n", size);
        }
        else if (strcmp(buf, "empty") == 0) {
            printf("%d\n", isEmpty(DQ1));
        }
        else if (strcmp(buf, "front") == 0) {
            printf("%d\n", peekFront(DQ1));
        }
        else {
            printf("%d\n", peekRear(DQ1));
        }
    }
    

    return 0;
}