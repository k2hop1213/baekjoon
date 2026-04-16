#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5000

typedef struct {
    int data[MAX];
    int front;
    int rear;
    long long int size;
} Queue;

// 큐 초기화
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// 큐가 비어 있는지 확인
int isEmpty(Queue* q) {
    return q->size == 0;
}

// 큐에 데이터 삽입
void enqueue(Queue* q, int value) {
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}

// 큐에서 데이터 제거
int dequeue(Queue* q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

// 큐의 맨 앞 데이터를 반환 (제거하지 않음)
int front(Queue* q) {
    return q->data[q->front];
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    for(int i=1;i<=n;i++){
      enqueue(&q,i);
    }

    while(q.size>0){
      printf("%d ",dequeue(&q));
      enqueue(&q,dequeue(&q));
    }

    return 0;
}