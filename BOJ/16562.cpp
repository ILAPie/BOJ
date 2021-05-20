#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 10001;
const int INF = 987654321;
int n, m, k;
int parent[MAX], cost[MAX];
int FIND(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = FIND(parent[x]);
}
void UNION(int a, int b) {
	a = FIND(a);
	b = FIND(b);
	if (a != b) {
		if (cost[a] < cost[b])
			parent[b] = a;
		else
			parent[a] = b;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		parent[i] = i;
	}
	cost[0] = INF;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		UNION(a, b);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int p = FIND(i);
		if (p != FIND(0)) {
			ret += cost[p];
			UNION(0, p);
		}
	}
	if (ret <= k) cout << ret;
	else cout << "Oh no";
}