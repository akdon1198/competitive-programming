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

ll lazy[4 * maxn];
ll segment[4 * maxn];
ll arr[maxn];

void build(ll si, ll ss, ll se){
	if(ss == se){
		segment[si] = arr[ss];
		return;
	}

	ll m = mid(ss, se);
	build(2 * si, ss, m);
	build(2 * si + 1, m + 1, se);
	segment[si] = segment[2 * si] + segment[2 * si + 1];
}

long long query(ll si, ll ss, ll se, ll qs, ll qe){
	if(lazy[si]){
		ll add = lazy[si];
		lazy[si] = 0;
		segment[si] += add * (se - ss + 1);
		if(ss != se){
			lazy[2 * si] += add;
			lazy[2 * si + 1] += add;
		}
	}	
	if(ss > qe or se < qs) return 0;
	if(ss >= qs and se <= qe){
		return segment[si];
	}
	ll m = mid(ss, se);
	return query(2 * si, ss, m, qs, qe) + query(2 * si + 1, m + 1, se, qs, qe);
}

void update(ll si, ll ss, ll se, ll qs, ll qe, ll val){
	if(lazy[si]){
		ll add = lazy[si];
		lazy[si] = 0;
		segment[si] += add * (se - ss) + 1;
		if(ss != se){
			lazy[2 * si] += add;
			lazy[2 * si + 1] += add;
		}
	}
	if(ss > qe or se < qs) return;
	if(ss >= qs and se <= qe){
		ll add = (se - ss + 1) * val;
		segment[si] += add;
		if(ss != se){
			lazy[2 * si] += val; lazy[2 * si + 1] += val;
		}
		return;
	}
	ll m = mid(ss, se);
	update(2 * si, ss, m, qs, qe, val);
	update(2 * si + 1, m + 1, se, qs, qe, val);
	segment[si] = segment[2 * si] + segment[2 * si + 1];
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
	ll n, q, code, l, r, val; cin >> n >> q;
	loop(i, 1, n) cin >> arr[i];
	build(1, 1, n);
	while(q--){
		cin >> code;
		if(code == 1){
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}else{
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
		}
	}
}
