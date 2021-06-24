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
const int maxn = 1004;
void solve();

ll arr[maxn];
vector<ll> st[4 * maxn];

void build(ll si, ll ss, ll se){
	if(ss == se){
		st[si].push_back(arr[ss]);
		return;
	}

	ll m = mid(ss, se);
	build(2 * si, ss, m);
	build(2 * si + 1, m + 1, se);
	ll i = 0, j = 0;
	while(i < st[2 * si].size() and j < st[2 * si + 1].size()){
		if(st[2 * si][i] <= st[2 * si + 1][j]){
			st[si].push_back(st[2 * si][i]);
			i++;
		}
		else{
			st[si].push_back(st[2 * si + 1][j]); j++;
		}
	}
	while(i < st[2 * si].size()){
		st[si].push_back(st[2 * si][i]); i++;
	}
	while(j < st[2 * si + 1].size()){
		st[si].push_back(st[2 * si + 1][j]); j++;
	}
}

ll query(ll si, ll ss, ll se, ll qs, ll qe, ll k){
	if(ss > qe or se < qs) return 0;
	if(ss >= qs and se <= qe){
		int res = upper_bound(st[si].begin(), st[si].end(), k - 1) - st[si].begin();
		return res;
	}
	ll m = mid(ss, se);
	return query(2 * si, ss, m, qs, qe, k) + query(2 * si + 1, m + 1, se, qs, qe, k);
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
	ll n, q, l, r, k; cin >> n >> q;
	loop(i, 1, n) cin >> arr[i];
	build(1, 1, n);
	while(q--){
		cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << endl;
	}
}
