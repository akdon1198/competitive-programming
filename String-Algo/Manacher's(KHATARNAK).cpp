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

string update(string s){
	string sb;
	sb.push_back('@');
	for(ll i = 0; i < s.length(); i++){
		sb.push_back('#');
		sb.push_back(s[i]);
	}
	sb.push_back('#');
	sb.push_back('$');

	return sb;
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
	string s, s1; cin >> s1;
	s = update(s1);
	ll n = s.length();
	ll lps[n] = {0};
	ll c = 0, r = 0;
	for(ll i = 1; i < s.length() - 1; i++){
		int mirr = c - (i - c);
		if(i < r){
			lps[i] = min(lps[mirr], r - i);
		}
		while(s[i + lps[i] + 1] == s[i - lps[i] - 1]){
			lps[i]++;
		}
		if(i + lps[i] > r){
			c = i;
			r = i + lps[i];
		}
	}
	int maxlen = 0, maxind = 0;
	for(ll i = 1; i < n - 1; i++){
		if(lps[i] > maxlen){
			maxlen = lps[i];
			maxind = i;
		}
	}

	cout << maxlen << endl;

	ll firstindex = maxind - maxlen + 1;
	ll actualindex = (firstindex - 2) / 2;
	for(ll i = actualindex; i < actualindex + maxlen; i++) cout << s1[i];
	cout << endl;
}