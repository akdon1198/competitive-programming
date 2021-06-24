#include<bits/stdc++.h>
using namespace std;
#define ll 				     long long int
#define ld				     long double
#define mod                  1000000007
#define inf                  1e18
#define endl			    "\n"
#define pb 				     push_back
#define vi                   vector<ll>
#define vs				     vector<string>
#define pii                  pair<ll,ll>
#define ump				     unordered_map
#define mp 				     make_pair
#define pq_max               priority_queue<ll>
#define pq_min               priority_queue<ll,vi,greater<ll> >
#define all(n) 			     n.begin(),n.end()
#define ff 				     first
#define ss 				     second
#define mid(l,r)             (l+(r-l)/2)
#define bitc(n) 		     __builtin_popcount(n)
#define zrobits(x)           __builtin_ctzll(x)
#define looprev(i,a,b) 	     for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	     for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define loop(i,a,b) 	     for(int i=(a);i<=(b);i++)
template <typename T> T      gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T      lcm(T a, T b){return (a*(b/gcd(a,b)));}

void solve();

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

void merge(ll l, ll m, ll r, ll arr[]){
	ll n1 = m - l + 1;
	ll n2 = r - m;
	ll a[n1], b[n2];
	for(ll i = 0; i < n1; i++) a[i] = arr[l + i];
	for(ll i = 0; i < n2; i++) b[i] = arr[m + i + 1];
	ll i = 0, j = 0, k = l;
	while(i < n1 and j < n2){
		if(a[i] <= b[j]){
			arr[k] = a[i];
			i++; k++;
		}else{
			arr[k] = b[j];
			k++; j++;
		}
	}
	while(i < n1){
		arr[k] = a[i]; k++; i++;
	}
	while(j < n2){
		arr[k] = b[j]; k++; j++;
	}
}

void mergesort(ll i, ll j, ll arr[]){
	if(i >= j){
		return;
	}
	ll m = mid(i, j);
	mergesort(i, m, arr);
	mergesort(m + 1, j, arr);
	merge(i, m, j, arr);
}

int main() {
	file_i_o();	
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

void solve(){
	ll n; cin >> n;
	ll arr[n];
	loop(i, 0, n - 1) cin >> arr[i];
	mergesort(0, n - 1, arr);
	loop(i, 0, n - 1) cout << arr[i] << ' ';
	cout << endl;
}
