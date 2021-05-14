#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 10001;
const int INF = 987654321;
int cache[MAX];
string s;
int classify(int a,int b) {
	//s의 부분 문자열을 가져온다.
	string M = s.substr(a, b - a + 1);
	//case 1: 1111 == 1111
	//부분 문자열 M이 M[0]으로 이루어진 문자열과 같을경우 난이도 1
	if (M == string(M.size(), M[0])) return 1;
	//case 2,4: 등차 수열
	bool progression = true;
	for (int i = 0; i < M.size()-1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0])
			progression = false;
	}
	if (progression and abs(M[1] - M[0]) == 1) return 2;
	if (progression) return 5;
	//case 3: 2개의 숫자가 번갈아가면서.	
	bool alternatvie = true;
	for (int i = 0; i < M.size(); i++) {
		//짝수 인덱스는 짝수 인덱스의 기준인 0하고 계속 비교
		//홀수 인덱스는 홀수 인덱스의 기준인 1하고 계속 비교
		if (M[i] != M[i % 2])
			alternatvie = false;
	}
	if (alternatvie) return 4;
	return 10;
}
int memoization(int start) {
	if (start == s.size()) return 0;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (i + start <= s.size())
			ret = min(ret, memoization(start + i)+classify(start, start + i - 1));
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> s;
		cout << memoization(0) << '\n';
	}
}