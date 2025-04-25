#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void print_perm(vector<int> arr, int n){
	if(n == arr.size()){
		for(auto i: arr) cout << i << ' ';
		cout << '\n';
		return;
	}
	for(int i = n; i < arr.size(); i++){
		swap(arr[i], arr[n]);
		print_perm(arr, n + 1);
		swap(arr[i], arr[n]);
	}

}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &i: arr) cin >> i;
	print_perm(arr, 0);

	return 0;
}