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
const int maxn = 100004;
void solve();

ll arr[100004];
ll st[4 * 100004];

void build(ll si, ll ss, ll se){
	if(ss == se){
		st[si] = arr[ss];
		return;
	}

	ll m = mid(ss, se);
	build(2 * si, ss, m);
	build(2 * si + 1, m + 1, se);
	st[si] = min(st[2 * si], st[2 * si + 1]);
}

ll query(ll si, ll ss, ll se, ll qs, ll qe){
	if(ss > qe or se < qs) return inf;
	if(ss >= qs and se <= qe) return st[si];
	ll m = mid(ss, se);
	return min(query(2 * si, ss, m, qs, qe), query(2 * si + 1, m + 1, se, qs, qe));
}

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
	ll n, q; cin >> n;
	loop(i, 1, n) cin >> arr[i];
	cin >> q;
	build(1, 1, n);
	ll l, r;
	while(q--){
		cin >> l >> r;
		cout << query(1, 1, n, l + 1, r + 1) << endl;
	}
}