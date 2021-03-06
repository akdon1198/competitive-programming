#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(){
	file_i_o();
	string p, t; cin >> p >> t;
	string check = p + "#" + t;
	long long n = check.size();
	long long prefix[n] = {0};
	long long i = 1, len = 0;
	while(i < n){
		if(check[i] == check[len]){
			len++;
			prefix[i] = len;
			i++;
		}else{
			if(len > 0){
				len = prefix[len - 1];
			}else{
				prefix[i] = 0;
				i++;
			}
		}
	}
	long long cnt = 0;
	for(int i = 0; i < n; i++){
		if(prefix[i] == p.size()) cnt++;
	}
	cout << cnt << endl;
}