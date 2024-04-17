#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 303030;

char s[NN];
vector<int> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d %s", &n, s + 1);
		ans.clear();
		char pre = 0;
		for(int i = 2; i <= n; i += 2) if(s[i - 1] ^ s[i]) {
			if(s[i] == pre) ans.push_back(i - 1), pre = s[i - 1];
			else ans.push_back(i), pre = s[i];
		}
		printf("%d\n", ans.size());
		for(int x : ans) printf("%d ", x);
		puts("");
	}
}
