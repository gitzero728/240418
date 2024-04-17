#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

INT dp[NN], mx[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		
		INT ans = 0;
		for(int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			dp[i] = dp[i - 1] + x;
			if(i >= 2) ans = min(ans, dp[i] - mx[i - 2]);
			mx[i] = max(mx[i - 1], dp[i]);
		}
		printf("%lld\n", dp[n] - ans + abs(ans));
	}
	return 0;
}
