#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define rep(a, b, c) for(long long a = b; a <= c; ++a)
#define repr(a, b, c) for(long long a = b; a >= c; --a)
#define Mod 1000000007
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int a, b ,c;
		bool ans = false;
		cin >> a >> b >> c;
		if(a == 7 or b == 7 or c == 7)
			ans = true;
		if(ans)
			cout << "YES" endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}