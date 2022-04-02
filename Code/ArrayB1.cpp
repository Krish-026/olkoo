//Move all zero at the end
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
void naive(int arr[], int size){
	rep(i, 0, size-1){
		if(arr[i] == 0)
			rep(j, i+1, size-1)
				if(arr[j] != 0){
					swap(arr[i], arr[j]);
					break;
				}
		
	}
}

void efficient(int arr[], int size){
	int count = 0;
	rep(i, 0, size-1){
		if(arr[i] != 0){
			swap(arr[i], arr[count]);
			++count;
		}
	}
}

void input(int arr[], int size){
	rep(i, 0, size-1)
		cin >> arr[i];
}

void output(int arr[], int size){
	cout << "Output : ";
	rep(i, 0, size-1)
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
	int size;
	cin >> size;
	int arr[size];
	input(arr, size);
	naive(arr, size);
	output(arr, size);
	input(arr, size);
	efficient(arr, size);
	output(arr, size);
	return 0;
}