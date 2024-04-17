#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		
		if(a[1] ^ a[n]) puts("NO");
		else {
			bool flag = 1;
			for(int i = 2; i < n; i++) if(a[i] < a[1]) {
				flag = 0; break;
			}
			if(flag) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
