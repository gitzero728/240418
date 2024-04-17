#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int n, c, s, m;
int w[NN];
INT dp[NN];

int a[NN], b[NN];

INT calc(int x) {
	int na = 0, nb = 0;
	for(int i = 1; i <= x; i++) a[na++] = w[i];
	for(int i = x + 1; i <= n; i++) b[nb++] = w[i];
	
	sort(a, a + na);
	sort(b, b + nb), reverse(b, b + nb);
	
	INT ans = (INT)c * (x - 1), sum = dp[x];
	for(int i = 0, ed = min(na, nb); i < ed; i++) {
		sum -= a[i], sum += b[i], ans += s;
		if(sum > m) return ans;
	}
	return (INT)c * n;
}

INT solve() {
	scanf("%d %d %d %d", &n, &c, &s, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		dp[i] = dp[i - 1] + w[i];
	}
	if(dp[n] <= m) return (INT)c * n;
	
	int st = 1, ed = n;
	while(ed - st > 20) {
		int A = (st + st + ed) / 3;
		int B = (st + ed + ed) / 3;
		if(calc(A) < calc(B)) ed = B;
		else st = A;
	}
	
	INT mn = calc(ed);
	for(int i = st; i < ed; i++) mn = min(mn, calc(i));
	return mn;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%lld\n", solve());
	return 0;
}