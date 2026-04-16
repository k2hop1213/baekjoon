#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 이진 트리의 노드 정의
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 새로운 노드를 생성하는 함수
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 레벨 순서대로 빌딩의 번호를 출력하는 함수
void printBuildingNumbers(struct TreeNode* root, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        printf("%d ", root->data);
    }
    else {
        printBuildingNumbers(root->left, level - 1);
        printBuildingNumbers(root->right, level - 1);
    }
}

// 레벨 순서대로 모든 빌딩의 번호를 출력하는 함수
void printAllBuildingNumbers(struct TreeNode* root, int height) {
    for (int i = 1; i <= height; i++) {
        printBuildingNumbers(root, i);
        printf("\n");
    }
}

// 주어진 빌딩 방문 순서로 완전 이진 트리를 구축하는 함수
struct TreeNode* buildBinaryTree(int* buildingOrder, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(buildingOrder[mid]);

    root->left = buildBinaryTree(buildingOrder, start, mid - 1);
    root->right = buildBinaryTree(buildingOrder, mid + 1, end);

    return root;
}

int main() {
    int K;
    scanf("%d", &K);

    int n = (int)pow(2, K) - 1;
    int* buildingOrder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &buildingOrder[i]);
    }

    // 주어진 빌딩 방문 순서로 완전 이진 트리 구축
    struct TreeNode* root = buildBinaryTree(buildingOrder, 0, n - 1);

    // 레벨 순서대로 빌딩의 번호 출력
    printAllBuildingNumbers(root, K);

    // 메모리 해제
    free(buildingOrder);

    return 0;
}
