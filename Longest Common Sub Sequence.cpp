#include<bits/stdc++.h>
using namespace std;

int LCS(string _One, string _Second, int m, int n) {
	vector<vector<int>> Longest(m + 1,vector<int>(n + 1));
	int i, j;
	for (i = 0; i <= m; i++){
		for (j = 0; j <= n; j++){
			if (i == 0 || j == 0)
				Longest[i][j] = 0;

			else if (_One[i - 1] == _Second[j - 1])
				Longest[i][j] = Longest[i - 1][j - 1] + 1;

			else
				Longest[i][j] = max(Longest[i - 1][j], Longest[i][j - 1]);
		}
	}
	return Longest[m][n];
}
int main() {
	int m, n;
	string _One = "", _Second = "";
	cin >> m;
	int Tem;
	for (size_t i = 0; i < m; i++) {
		cin >> Tem;
		_One += Tem;
	}
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> Tem;
		_Second += Tem;
	}
	cout << LCS(_One, _Second, m, n) << endl;
}
