#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 100001;
const int INF = 1234567890;
int n, m;
int arr[MAX];
vector<ll>minTree(MAX * 4);
vector<ll>maxTree(MAX * 4);
ll initMin(int start, int end, int node) {
	if (start == end) {
		return minTree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return minTree[node] = min(initMin(start, mid, node * 2), initMin(mid + 1, end, node * 2 + 1));
}
ll initMax(int start, int end, int node) {
	if (start == end) {
		return maxTree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return maxTree[node] = max(initMax(start, mid, node * 2), initMax(mid + 1, end, node * 2 + 1));
}
ll queryMin(int left,int right,int node,int start,int end) {
	if (left>end or right<start) return INF;
	if (left >= start and right <= end) return minTree[node];
	int mid = (left + right) / 2;
	return min(queryMin(left, mid, node * 2, start, end), queryMin(mid + 1, right, node * 2 + 1, start, end));
}
ll queryMax(int left, int right, int node, int start, int end) {
	if (left>end or right<start) return -1;
	if (left >= start and right <= end) return maxTree[node];
	int mid = (left + right) / 2;
	return max(queryMax(left, mid, node * 2, start, end), queryMax(mid + 1, right, node * 2 + 1, start, end));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	initMin(0, n-1, 1);
	initMax(0, n-1, 1);
	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		cout << queryMin(1, n, 1, l, r) << ' ' << queryMax(1, n, 1, l, r) << '\n';
	}
}