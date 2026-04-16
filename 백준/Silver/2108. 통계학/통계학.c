#include <stdio.h>
#include <stdlib.h>

// 비교 함수 정의
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 최빈값을 찾는 함수 정의
int findMode(int arr[], int n) {
    int maxCount = 1;  // 최빈값의 최대 빈도수
    int modeCount = 0; // 현재 최빈값의 빈도수
    int* modes = (int*)malloc(sizeof(int) * n); // 최빈값을 저장할 배열

    int currentCount = 1;
    int currentMode = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        }
        else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modeCount = 1;
                modes[0] = currentMode;
            }
            else if (currentCount == maxCount) {
                modes[modeCount++] = currentMode;
            }

            currentCount = 1;
            currentMode = arr[i];
        }
    }

    // 마지막 원소에 대한 처리
    if (currentCount > maxCount) {
        modeCount = 1;
        modes[0] = currentMode;
    }
    else if (currentCount == maxCount) {
        modes[modeCount++] = currentMode;
    }

    // 최빈값 중 두 번째로 작은 값 찾기
    int mode;
    if (modeCount > 1) {
        qsort(modes, modeCount, sizeof(int), compare);
        mode = modes[1];
    }
    else {
        mode = modes[0];
    }

    free(modes);
    return mode;
}


int main() {
    int N;
    scanf("%d", &N);

    int* arr = malloc(sizeof(int) * N);

    // 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 배열 정렬
    qsort(arr, N, sizeof(int), compare);

    // 산술평균 계산
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    int mean = (sum > 0) ? ((int)((double)sum / N + 0.5)) : (int)(((double)sum / N - 0.5)); // 소수점 이하 반올림

    // 중앙값 계산
    int median = arr[N / 2];

    // 최빈값 계산
    int mode = findMode(arr, N);

    // 범위 계산
    int range = arr[N - 1] - arr[0];

    // 결과 출력
    printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);

    return 0;
}
