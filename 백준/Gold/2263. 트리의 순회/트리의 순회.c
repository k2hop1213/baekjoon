#include <stdio.h>

int in[100001];
int post[100001];

void preorder(int in1, int in2, int post1, int post2) {
    if (in1 > in2 || post1 > post2)return;

    int root = post[post2];
    printf("%d ", root);

    int index;
    for (index = in1; index <= in2; index++) {
        if (in[index] == root)break;
    }
    int size = index - in1;

    preorder(in1, index - 1, post1, post1 + size - 1);
    preorder(index + 1, in2, post1 + size, post2 - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &post[i]);
    }

    preorder(1, n, 1, n);

    return 0;
}