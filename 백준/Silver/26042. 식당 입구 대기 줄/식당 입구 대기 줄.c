#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* front;
node* rear;
node* alloc_node(int n) {
	node* new_node = malloc(sizeof(node));
	new_node->data = n;
	new_node->next = NULL;
	return new_node;
}
int isEmpty() {
	return (front == NULL) && (rear == NULL);

}

void enqueue(node* a) {
	if (rear == NULL) {
		rear = a;
		front = a;
		return;
	}
	rear->next = a;
	rear = a;
}

int dequeue() {
	if (isEmpty()) {
		return -1;
	}
	else {
		int res = front->data;
		node* temp = front;
		front = front->next;
		if (front == NULL) {
			rear = NULL;     
		}
		free(temp);
		return res;
	}
}

int get_rear() { return rear->data; }

int main() {
	int n;
	scanf("%d", &n);
	int size = 0;
	int max = 0;
	int res = 100001;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			scanf("%d", &b);
			node* p = alloc_node(b);
			enqueue(p);
			size++;
			if (max < size) { 
				max = size; 
			
				res = get_rear();
				
			}
			else if (max == size) {
				if (res > get_rear()) {
					res = get_rear();
				}
			}
		}
		else {
			dequeue();
			size--;
		}
	}
	printf("%d %d", max,res);


	return 0;
}