#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> a;
	deque<int> a1;
	deque<int> b;
	deque<int> b1;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp, temp1;
		cin >> temp >> temp1;
		a.push_front(temp);
		b.push_front(temp1);
	}

	int turn = 0; 
	while (m--) {
		if (turn == 0) {
			a1.push_front(a.front());
			a.pop_front();
		}
		else {
			b1.push_front(b.front());
			b.pop_front();
		}

		
		if (a.empty() || b.empty()) break;

		int winner = -1;
		
		if ((!a1.empty() && a1.front() == 5) || (!b1.empty() && b1.front() == 5)) {
			winner = 0;
		}
	
		else if (!a1.empty() && !b1.empty() && (a1.front() + b1.front() == 5)) {
			winner = 1;
		}

		if (winner == 0) { 
			
			while (!b1.empty()) {
				a.push_back(b1.back()); 
				b1.pop_back();
			}
			while (!a1.empty()) {
				a.push_back(a1.back());
				a1.pop_back();
			}
		}
		else if (winner == 1) { 
			
			while (!a1.empty()) {
				b.push_back(a1.back());
				a1.pop_back();
			}
			while (!b1.empty()) {
				b.push_back(b1.back());
				b1.pop_back();
			}
		}

		turn = 1 - turn; 
	}

	if (a.size() > b.size()) cout << "do";
	else if (a.size() < b.size()) cout << "su";
	else cout << "dosu";

	return 0;
}