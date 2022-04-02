//Second largest element
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
#define Mod 1000000009
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	cin >> size;
	int arr[size];
	rep(i, 0, size-1)
		cin >> arr[i];
	int pos = -1, largest = 0;
	rep(i, 1, size-1){
		if(arr[i] > arr[largest]){
			pos = largest;
			largest = i;
		}
		else if(arr[i] != largest){
			if(pos != -1 or arr[i] > arr[pos])
				pos = i;
		}
	}
	rep(i, 0, size-1)
		cout << arr[i] << " ";
	cout << endl << "Second Largest : "<< arr[pos];
	return 0;
}