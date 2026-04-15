#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 큰 수의 거듭제곱 (2^n - 1)을 계산하는 함수
string powerOfTwoMinusOne(int n) {
    string res = "1";
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = res.size() - 1; j >= 0; j--) {
            int num = (res[j] - '0') * 2 + carry;
            res[j] = (num % 10) + '0';
            carry = num / 10;
        }
        if (carry) res = to_string(carry) + res;
    }
    
    // 마지막 자리에서 1을 뺌 (2^n은 항상 0으로 끝나지 않으므로 간단히 처리 가능)
    res[res.size() - 1] = (res.back() - '0' - 1) + '0';
    return res;
}

// 하노이의 탑 재귀 함수
void hanoi(int n, int from, int tmp, int to) {
    if (n == 0) return;
    
    // 1. n-1개를 보조 기둥으로 이동
    hanoi(n - 1, from, to, tmp);
    // 2. 가장 큰 원판을 목적지로 이동
    printf("%d %d\n", from, to);
    // 3. n-1개를 보조 기둥에서 목적지로 이동
    hanoi(n - 1, tmp, from, to);
}

int main() {
    int n;
    scanf("%d", &n);

    // 1. 이동 횟수 출력 (큰 수 처리)
    if (n <= 62) {
        // 2^64-1까지는 unsigned long long으로 처리 가능하지만 통일성을 위해 string 권장
        cout << powerOfTwoMinusOne(n) << endl;
    } else {
        cout << powerOfTwoMinusOne(n) << endl;
    }

    // 2. N이 20 이하인 경우에만 경로 출력
    if (n <= 20) {
        hanoi(n, 1, 2, 3);
    }

    return 0;
}