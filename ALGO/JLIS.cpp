#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 101;
const int INF = 987654321;
const ll LLMIN = numeric_limits<ll>::min();
int a[100];
int b[100];
int cache[101][101];
int n, m;
//aidx : a배열의 현재 인덱스
//bidx : b배열의 현재 인덱스
int jlis(int aidx, int bidx) {
	int& ret = cache[aidx+1][bidx+1];
	if (ret != -1) return ret;
	ret = 2;
	//초기에 -1,-1에서 시작하므로, 값을 LLMIN으로 지정
	ll av = (aidx == -1 ? LLMIN : a[aidx]);
	ll bv = (bidx == -1 ? LLMIN : b[bidx]);
	//두 포인터가 가르키는 값중 최댓값
	ll maxE = max(av, bv);
	//bidx가 가리키는 값을 기준으로 aidx를 옮겼을때 가질수 있는 최대 길이를 캐쉬에 저장
	for (int nexta = aidx + 1; nexta < n; nexta++) {
		if (maxE < a[nexta])
			ret = max(ret, jlis(nexta, bidx) + 1);
	}
	//aidx가 가리키는 값을 기준으로 bidx를 옮겼을때 가질 수 있는 최대 길이를 캐쉬에 저장
	for (int nextb = bidx + 1; nextb < m; nextb++) {
		if (maxE < b[nextb])
			ret = max(ret, jlis(aidx, nextb) + 1);
	}
	//모든게 끝나면 결국 cache[0][0]에는 모든 과정을 거친 후 최대 길이를 가지고 잇다.
	return ret;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		//메모이제이션 초기화
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		//a의 시작 인덱스, b의 시작 인덱스를 -1로 지정
		//각 배열에 LLMIN을 두고 시작하였기에 마지막에 길이 -2
		cout << jlis(-1, -1) - 2 << '\n';
	}
}