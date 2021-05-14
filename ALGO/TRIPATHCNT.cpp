#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 101;
const int INF = 987654321;
const int MOD = 1000000007;
//경로 횟수체크
int cache[MAX][MAX];
//경로 최댓값저장
int cache2[MAX][MAX];
//삼각형 저장
int tri[MAX][MAX];
int n;
//x,y좌표일 때 가질 수 있는 최대값을 저장.
int path(int x, int y) {
	if (x == n - 1) return tri[x][y];
	int& ret = cache2[x][y];
	if (ret != -1) return ret;
	//x,y좌표가 가질 수 있는 최대 값은 (바로 밑이 가지는 최대값 or 대각선이 가지는 최대값)+ x,y좌표의 값
	return ret = max(path(x + 1, y + 1), path(x + 1, y)) + tri[x][y];
}
//x,y좌표일 때 가질 수 있는 최대 경로의 수
int count(int x, int y) {
	if (x == n - 1) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	//대각선으로 가는게 유리할 경우 대각선으로 진행
	if (path(x + 1, y + 1) >= path(x + 1, y)) ret += count(x + 1, y + 1);
	//밑으로 진행하는게 유리할 경우 밑으로 진행
	if (path(x + 1, y + 1) <= path(x + 1, y)) ret += count(x + 1, y);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		cout << count(0, 0) << '\n';
	}
}