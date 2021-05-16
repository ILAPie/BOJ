#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 101;
const int INF = 987654321;
const int MOD = 1000000007;
int n, m;
int graph[MAX][MAX];
void floyd() {
	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			//from - via 없을 경우 패스
			if (!graph[from][via]) continue;
			for (int to = 1; to <= n; to++) {
				//출발지 도착지 같거나, via - to 경로 없을 경우 패스
				if (from == to or !graph[via][to]) continue;
				if (!graph[from][to] or graph[from][to] > graph[from][via] + graph[via][to])
					graph[from][to] = graph[from][via] + graph[via][to];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	floyd();
	int ret = INF;
	int person = 0;
	for (int i = 1; i <= n; i++) {
		int kevin = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			kevin += graph[i][j];
		}
		if (ret > kevin) {
			ret = kevin;
			person = i;
		}
	}
	cout << person;
}