#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int caseNum) {
    int n;
    cin >> n;
    cin.ignore(); // 숫자 입력 후 남은 줄바꿈 문자 제거

    vector<pair<string, int>> keywords(n);
    for (int i = 0; i < n; ++i) {
        string phrase;
        int score;
        getline(cin, phrase); // 구문 입력 (공백 포함)
        cin >> score;
        cin.ignore(); // 점수 입력 후 줄바꿈 문자 제거
        keywords[i] = {phrase, score};
    }

    string speech;
    getline(cin, speech); // 전체 연설문 입력

    long long totalScore = 0;

    // 각 키워드별로 연설문 내에서 발생하는 횟수를 찾음
    for (int i = 0; i < n; ++i) {
        string pattern = keywords[i].first;
        int score = keywords[i].second;

        size_t pos = speech.find(pattern, 0);
        while (pos != string::npos) {
            totalScore += score;
            // 다음 발생 위치를 찾기 위해 현재 위치 바로 다음부터 다시 검색
            pos = speech.find(pattern, pos + 1);
        }
    }

    cout << "Data Set " << caseNum << ":" << endl;
    cout << totalScore << endl;
}

int main() {
    int k;
    if (!(cin >> k)) return 0;

    for (int i = 1; i <= k; ++i) {
        solve(i);
    }

    return 0;
}