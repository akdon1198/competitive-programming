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
const int maxn = 100005;
void solve();
ll arr[maxn];
pair<ll,ll> st[4 * maxn];
// for first even and second odd
void build(ll si, ll ss, ll se){
	if(ss == se){
		if(arr[ss] & 1) st[si].second = 1, st[si].first = 0;
		else st[si].first = 1, st[si].second = 0;
		return;
	}
	ll m = mid(ss, se);
	build(2 * si, ss, m);
	build(2 * si + 1, m + 1, se);
	st[si].first = st[2 * si].first + st[2 * si + 1].first;
	st[si].second = st[2 * si].second + st[2 * si + 1].second;
}

long long query(ll si, ll ss, ll se, ll qs, ll qe, ll type){
	if(ss > qe or se < qs) return 0;
	if(ss >= qs and se <= qe){
		if(type == 1) return st[si].first;
		else return st[si].second;
	}
	ll m = mid(ss, se);
	return query(2 * si, ss, m, qs, qe, type) + query(2 * si + 1, m + 1, se, qs, qe, type);
}

void modify(ll si, ll ss, ll se, ll qi, ll val){
	if(ss == se){
		if(arr[qi] % 2) st[si].first = 1, st[si].second = 0;
		else st[si].second = 1, st[si].first = 0;

		arr[qi] = val;
		return;
	}

	ll m = mid(ss, se);
	if(qi <= m) modify(2 * si, ss, m, qi, val);
	else modify(2 * si + 1, m + 1, se, qi, val);

	st[si].first = st[2 * si].first + st[2 * si + 1].first;
	st[si].second = st[2 * si].second + st[2 * si + 1].second;
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
	ll n, x, y, code, q; cin >> n;
	loop(i, 1, n) cin >> arr[i];
	cin >> q;
	build(1, 1, n);
	while(q--){
		cin >> code >> x >> y;
		if(code == 0){
			if(arr[x] % 2 == y % 2) continue;
			modify(1, 1, n, x, y);
		}else if(code == 1){
			cout << query(1, 1, n, x, y, code) << endl;
		}else{
			cout << query(1, 1, n, x, y, code) << endl;
		}
	}
}