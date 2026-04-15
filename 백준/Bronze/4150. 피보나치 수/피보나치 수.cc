#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 문자열 숫자를 더하는 함수
string addBigInt(string num1, string num2) {
    string result = "";
    int sum = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }

    // 메모리 절약을 위해 최근 두 항만 저장하는 방식
    string f1 = "1";
    string f2 = "1";
    string fn = "";

    for (int i = 3; i <= n; i++) {
        fn = addBigInt(f1, f2);
        f1 = f2;
        f2 = fn;
    }

    cout << f2 << endl;

    return 0;
}