#include <stdio.h>
#include <stdlib.h>

// 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 큐 구조체
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// 큐 초기화
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0; // 초기 크기 설정
}

// 큐가 비어 있는지 확인
int isEmpty(Queue* q) {
    return q->size == 0;
}

// 데이터 삽입 (Enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // 원형 연결
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// 데이터 제거 (Dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // 오류 코드
    }
    Node* temp = q->front;
    int value = temp->data;

    if (q->size == 1) { // 마지막 노드
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    q->size--;
    return value;
}

int main() {
    Queue q;
    initQueue(&q);

    int N, K;
    scanf("%d %d", &N, &K);

    // 큐 초기화
    for (int i = 1; i <= N; i++) {
        enqueue(&q, i);
    }

    // 청설모 제거 로직
    while (q.size > 1) {
        // 첫 번째 청설모는 항상 살아남음
        enqueue(&q, dequeue(&q)); // 첫 번째 청설모를 뒤로 보냄
  
        // \(2\)번째부터 \(K\)번째 청설모를 제거
        int removeCount = (q.size < K) ? q.size - 1 : K - 1;
        for (int i = 0; i < removeCount; i++) {
            dequeue(&q); // 청설모 제거
        }
    }


    // 마지막 남은 청설모 출력
    printf("%d\n", dequeue(&q));
    return 0;
}