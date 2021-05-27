#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
const int MAX = 1000001;
const int INF = 1234567890;
ll n, m, k;
vector<int>arr;
vector<ll>tree;
ll init(int node, ll start, ll end) {
	if (start == end)
		return tree[node] = arr[start];
	ll mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
ll query(ll start, ll end, int node, ll left, ll right) {
	if (start > right or end < left) return 0;
	if (left <= start and end <= right) return tree[node];
	ll mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update(ll start, ll end, int node, ll idx, ll newValue) {
	if (start > idx or idx > end)return;
	if (start == end) {
		tree[node] = newValue;
		return;
	}
	ll mid = (start + end) / 2;
	update(start, mid, node * 2, idx, newValue);
	update(mid + 1, end, node * 2 + 1, idx, newValue);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	tree.resize(n * 4);
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
}