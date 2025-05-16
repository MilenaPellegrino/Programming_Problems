#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fst first
#define snd second
#define str string
#define pri(x) cout << (x) << "\n"
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using ll = long long;
using pii = pair<int,int>;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

const  ll MOD = 998244353;

ll binpow(ll a, ll b){ 
	ll res=1;
	while(b>0){
		if(b%2==1){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD,b/=2;
	}
	return res;
}

void solve(){
	ll w, h; cin>>w>>h; 
	ll ans = binpow(2, (w+h));
	pri(ans);
}
 
int main(){
    FIN; 
    int t = 1;
    //int t; cin>>t; 
    while(t--){
		solve();
	}
    return 0;
}
