#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n; 
	vector<int> a; a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m; cin >> m;
	vector<pair<int, int> > q; q.resize(m);
	for(int i = 0; i < m; i++){
		cin >> q[i].first >> q[i].second;
	}
	int Q = 0;
	for(int i = 0 ; i < m; i++){
		int begin = q[i].first;
		int end = q[i].second;
		int min = a[begin];
		for(int j = begin+1; j <= end; j++){
			if(a[j] < min) min = a[j];
		}
		Q += min;
	}
	cout << Q;
}


