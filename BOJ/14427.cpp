#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
const int MAX = 1000001;
const int INF = 1234567890;
const int MOD = 1000000007;
int n,m;
vector<int>arr;
// first : 최솟값
// second : 인덱스
vector<pii>tree;
pii init(int start, int end, int node) {
	if (start == end) return tree[node] = { arr[start],start };
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
pii update(int start, int end, int node, int idx, int newValue) {
	if (idx < start or end < idx) return tree[node];
	// 노드를 업데이트할 경우, 값은 newValue로 바꾸어주고, 인덱스는 그대로 유지하게 하면된다.
	if (start == end) return tree[node] = { newValue,tree[node].second };
	int mid = (start + end) / 2;
	return tree[node] = min(update(start, mid, node * 2, idx, newValue), update(mid + 1, end, node * 2 + 1, idx, newValue));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	arr.resize(n + 1);
	tree.resize(n * 4);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	init(1, n, 1);
	while (m--) {
		int con;
		cin >> con;
		if (con == 1) {
			int b, c;
			cin >> b >> c;
			update(1, n, 1, b, c);
		}
		else {
			// 세그먼트 트리의 최상위 노드인 1번은 전 범위에 대한 값을 가지니까.
			// 1번 노드에 수열에서 가장 작은 값과, 그 인덱스를 저장하고 있다
			cout << tree[1].second << '\n';
		}
	}
}