#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
const int MAX = 1000001;
const int INF = 1234567890;
const int MOD = 1000000007;
ll n, m, k;
vector<ll>arr, tree;
ll init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MOD;
}
ll query(int start, int end, int node, int left, int right) {
	//범위를 벗어날 시 구간의 곱을 구하기위해 곱하는 과정에서 그대로 유지되도록 1을 리턴합니다.
	if (start > right or end < left) return 1;
	if (left <= start and end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}
void update(int start, int end, int node, int idx, int newV) {
	if (start > idx or end < idx) return;
	if (start == end) {
		tree[node] = newV;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, newV);
	update(mid + 1, end, node * 2 + 1, idx, newV);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	arr.resize(n + 1);
	tree.resize(n * 4);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
}