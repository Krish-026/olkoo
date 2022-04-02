//Reverse an Array
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

void input(vi &arr){
	int size;
	cin >> size;
	arr.resize(size);
	rep(i, 0, size-1)
		cin >> arr[i];
}

void output(vi &arr){
	cout << "Output : ";
	rep(i, 0, arr.size()-1)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi arr;
	input(arr);

	return 0;
}