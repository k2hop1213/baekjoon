#include <stdio.h>
#include <stdlib.h>

// 이진 트리의 노드 구조체 정의
struct Node {
    char key;
    struct Node* left;
    struct Node* right;
};

// 이진 트리에 노드를 추가하는 함수
struct Node* createNode(char key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 전위 순회 함수
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 중위 순회 함수
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->key);
        inorderTraversal(root->right);
    }
}

// 후위 순회 함수
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c", root->key);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* nodes[26]; // 노드들을 저장할 배열
    for (int i = 0; i < N; ++i) {
        char parent, leftChild, rightChild;
        scanf(" %c %c %c", &parent, &leftChild, &rightChild);

        struct Node* parentNode;
        if (nodes[parent - 'A'] == NULL) {
            parentNode = createNode(parent);
            nodes[parent - 'A'] = parentNode;
        } else {
            parentNode = nodes[parent - 'A'];
        }

        if (leftChild != '.') {
            struct Node* leftNode = createNode(leftChild);
            parentNode->left = leftNode;
            nodes[leftChild - 'A'] = leftNode;
        }

        if (rightChild != '.') {
            struct Node* rightNode = createNode(rightChild);
            parentNode->right = rightNode;
            nodes[rightChild - 'A'] = rightNode;
        }
    }

    // 전위 순회 출력
    preorderTraversal(nodes[0]);
    printf("\n");

    // 중위 순회 출력
    inorderTraversal(nodes[0]);
    printf("\n");

    // 후위 순회 출력
    postorderTraversal(nodes[0]);
    printf("\n");

    return 0;
}
