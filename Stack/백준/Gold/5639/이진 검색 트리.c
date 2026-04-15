#include <stdio.h>
#include <stdlib.h>

// 이진 검색 트리의 노드 구조체 정의
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// 이진 검색 트리에 노드를 추가하는 함수
struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// 후위 순회 함수
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\n", root->key);
    }
}

int main() {
    struct Node* root = NULL;
    int key;

    // 전위 순회 결과를 입력받아 이진 검색 트리를 생성
    while (scanf("%d", &key) != EOF) {
        root = insertNode(root, key);
    }

    // 후위 순회 결과를 출력
    postorderTraversal(root);

    return 0;
}
