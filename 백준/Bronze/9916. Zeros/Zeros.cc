#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 큰 수 곱셈을 수행하여 n!을 구하는 함수
string factorial(int n) {
    vector<int> res;
    res.push_back(1); // 1부터 시작

    for (int x = 2; x <= n; x++) {
        int carry = 0;
        for (int i = 0; i < res.size(); i++) {
            int prod = res[i] * x + carry;
            res[i] = prod % 10; // 현재 자릿수 저장
            carry = prod / 10;  // 올림수 계산
        }
        // 남은 올림수를 자릿수로 추가
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }

    // 배열을 거꾸로 뒤집어 문자열로 변환
    string result = "";
    for (int i = res.size() - 1; i >= 0; i--) {
        result += to_string(res[i]);
    }
    return result;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // 팩토리얼 계산
    string factStr = factorial(n);

    // 문자열에서 '0'의 개수 세기
    int zeroCount = 0;
    for (char c : factStr) {
        if (c == '0') {
            zeroCount++;
        }
    }

    cout << zeroCount << endl;

    return 0;
}