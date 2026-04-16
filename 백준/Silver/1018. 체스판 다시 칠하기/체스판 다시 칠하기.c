#include <stdio.h>
int chess_compare(int x, int y, char chess[50][50]) {
    char black[8][9] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };
    char white[8][9] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };


    int cnt_b = 0;
    int cnt_w = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            if (chess[x + i][y + k] != black[i][k]) {
                cnt_b++;
            }
            if (chess[x + i][y + k] != white[i][k]) {
                cnt_w++;
            }
        }
    }
    int min = (cnt_b > cnt_w) ? cnt_w : cnt_b;
    return min;
}
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    
    char chess[50][50] = { 0 };
    for (int i = 0; i < a; i++) {
        scanf("%s", chess[i]);
    }
    int real_min = 64;
    int c = 0;
    for (int i = 0; i < a - 7; i++) {
        for (int k = 0; k < b - 7; k++) {
            c = chess_compare(i, k, chess);
            if (real_min > c) {
                real_min = c;
            }
        }
    }
    printf("%d", real_min);
    return 0;
}