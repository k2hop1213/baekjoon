#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SZ 4000005
char board[2005][2005];
int check[2005][2005];
int vis[2005][2005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };

typedef struct {
	int x;
	int y;
}pii;
int front, rear;
pii queue[SZ];
pii chase[2005][2005];
int isEmpty() {
	return front == rear;
}

void enqueue(pii a) {
	rear = (rear + 1) % SZ;
	queue[rear] = a;
}

pii dequeue() {
	if (isEmpty()) {
		pii t;
		t.x = 0;
		t.y = 0;
		return t;
	}
	else {
		front = (front + 1) % SZ;
		return queue[front];
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	pii start = { -1,-1 };
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (board[i][j] == '.') {
					start.x = i; start.y = j;
					enqueue(start);
					vis[start.x][start.y] = 1;
					chase[i][j] = (pii){ -1,-1 };
					flag = 1;
					break;
				}
			}
		}
		if (flag) break;
	}
	pii end;
	while (!isEmpty()) {
		pii cur = dequeue();
	
		
		if ((cur.x == 0 || cur.x == n - 1 || cur.y == 0 || cur.y == m - 1) && 
			!(start.x == cur.x && start.y == cur.y)) {
			end = cur;
			break;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.x;
			int ny = dy[dir] + cur.y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (vis[nx][ny] || board[nx][ny] == '+')continue;
			vis[nx][ny] = 1;
			pii a = { nx,ny };
			chase[nx][ny] = cur;
			enqueue(a);

		}

	}

	pii temp = end;
	while (temp.x != -1) {
		check[temp.x][temp.y] = 1;
		temp = chase[temp.x][temp.y];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.' && !check[i][j]) {
				board[i][j] = '@';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", board[i]);
	}



	return 0;
}