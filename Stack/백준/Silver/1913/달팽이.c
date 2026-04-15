#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, target;
    scanf("%d", &n);
    scanf("%d", &target);
    int** arr = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)arr[i] = calloc(n,sizeof(int));
    int value = n * n;
    int row = 0, col = 0;
    int targetRow = -1, targetCol = -1;

    while (value > 0) {
    
        for (int i = row; i < n && arr[i][col] == 0; i++) {
            arr[i][col] = value--;
            
            row = i;
        }
        col++;


        for (int i = col; i < n && arr[row][i] == 0; i++) {
            arr[row][i] = value--;
            
            col = i;
        }
        row--;


        for (int i = row; i >= 0 && arr[i][col] == 0; i--) {
            arr[i][col] = value--;
            
            row = i;
        }
        col--;

 
        for (int i = col; i >= 0 && arr[row][i] == 0; i--) {
            arr[row][i] = value--;
            
            col = i;
        }
        row++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
            if (arr[i][j] == target) {
                targetRow = i + 1;
                targetCol = j + 1;
            }
        }
        printf("\n");
    }
    printf("%d %d\n", targetRow , targetCol);
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}