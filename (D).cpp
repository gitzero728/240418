#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int n, c, s, m;
int w[NN];

multiset<int> se;
multiset<int> :: iterator it;
INT dp[NN];
INT Ldp[NN], Rdp[NN];

bool can(INT cost) {
	se.clear();
	INT sum = 0;
	for(int i = 1; i <= n; i++) {
		INT remain = cost - (INT)c * (i - 1);
		se.insert(w[i]), sum += w[i];
		
		if(remain >= 0) {
			INT num = min({remain / s, (INT)i, (INT)n - i});
			while(se.size() > num) {
				it = --se.end();
				sum -= *it, se.erase(it);
			}
			Ldp[i] = sum;
		}
	}
	
	se.clear(), sum = 0;
	for(int i = n; i >= 1; i--) {
		INT remain = cost - (INT)c * (i - 1);
		
		if(remain >= 0) {
			INT num = min({remain / s, (INT)i, (INT)n - i});
			while(se.size() > num) {
				it = se.begin();
				sum -= *it, se.erase(it);
			}
			Rdp[i] = sum;
		}
		se.insert(w[i]), sum += w[i];
	}
	
	for(int i = 1; i <= n; i++) {
		INT remain = cost - (INT)c * (i - 1);
		if(remain >= 0 && dp[i] - Ldp[i] + Rdp[i] > m) return true;
	}
	return false;
}

INT solve() {
	scanf("%d %d %d %d", &n, &c, &s, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		dp[i] = dp[i - 1] + w[i];
	}
	
	INT st = -1, ed = (INT)c * n;
	if(dp[n] <= m) return ed;
	
	while(ed - st > 1) {
		INT md = st + ed >> 1;
		if(can(md)) ed = md;
		else st = md;
	}
	return ed;
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
