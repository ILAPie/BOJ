#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100001;
const int INF = 987654321;
int n, k;
bool visited[MAX];
int trace[MAX];
int bfs() {
	queue<pii>q;
	q.push({ 0,n });
	visited[n] = true;
	while (q.size()) {
		auto cur = q.front().second;
		auto sec = q.front().first;
		q.pop();
		if (cur == k) {
			return sec;
		}
		for (auto& e : { cur * 2,cur + 1,cur - 1 }) {
			if (e >= MAX or e < 0) continue;
			if (visited[e]) continue;
			q.push({ sec + 1,e });
			visited[e] = true;
			trace[e] = cur;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	cout << bfs() << '\n';
	auto node = k;
	vector<int>ret;
	while (node!=n) {
		ret.push_back(node);
		node = trace[node];
	}
	ret.push_back(n);
	for (int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i] << ' ';
	}
}