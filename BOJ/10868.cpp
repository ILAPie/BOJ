#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
const int MAX = 100001;
const int INF = 1234567890;
vector<int>arr;
vector<int>tree;
int n, m;
int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}
int query(int start, int end, int node, int left, int right) {
	if (start > right or end < left) return INF;
	if (start >= left and end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	tree.resize(n * 4);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << query(1, n, 1, l, r) << '\n';
	}
}