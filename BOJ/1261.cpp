#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 101;
const int INF = 987654321;
const int MOD = 1000000007;
int n, m;
int maze[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void bfs() {
	queue<pii>q;
	q.push({ 0,0 });
	dist[0][0] = 0;
	while (q.size()) {
		auto x = q.front().first;
		auto y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			auto nx = x + dx[i];
			auto ny = y + dy[i];
			if (nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
			// 다음 좌표가 벽인데, 현재값+1이 더 작은 값일 경우
			if (maze[nx][ny] and dist[nx][ny] > dist[x][y]+1) {
				dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
				q.push({ nx,ny });
			}
			//다음 좌표가 벽이 아니고, 현재값이 더 작을경우
			else if (maze[nx][ny]==0 and dist[nx][ny] > dist[x][y]){
				dist[nx][ny] = dist[x][y];
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			maze[i][j] = s[j] - '0';
			dist[i][j] = INF;
		}
	}
	bfs();
	cout << dist[m - 1][n - 1];
}