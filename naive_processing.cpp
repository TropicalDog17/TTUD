#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > M;
void naive_preprocessing(vector<int> a, int n){
	M.resize(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		M[i].resize(n);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int min = a[i];
			for(int k = i; k <= j; k++){
				if(a[k] < min) min = a[k];
			}
			M[i][j] = min;
		}
	}
}
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
	naive_preprocessing(a, n);
	int Q = 0;
	for(int i = 0 ;i < m; i++){
		Q += M[q[i].first][q[i].second];
	}
	cout << Q;
}


