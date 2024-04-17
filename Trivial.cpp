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
//	freopen("test.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	INT ans = 0;
	for(int i = 2; i <= n; i++) ans += abs(a[i] - a[i - 1]);
	
	if(n == 1) return puts("0"), 0;
	
	INT mn = ans - abs(a[1] - a[2]);
	for(int i = 2; i < n; i++) {
		mn = min(mn, ans - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]));
	}
	mn = min(mn, ans - abs(a[n - 1] - a[n]));
	
	cout<<mn<<endl;
	return 0;
}