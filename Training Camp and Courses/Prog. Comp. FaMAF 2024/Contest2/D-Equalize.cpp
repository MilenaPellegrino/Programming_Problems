#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define forr(i, a, b) for(int i=(b);i>(a);i--)
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
using pll = pair<ll,ll>;
using vii = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}
void solve(){
	ll n; cin>>n;
	set<ll> s; 
	fore(i, 0, n){
		ll si; cin>>si; 
		s.insert(si);
	}
	vll a; 
	forn(e, s){
		a.pb(e);
	}
	//cout<<a<<endl;
	sort(all(a));
	// 7 1 4 1 
	// 2 3 1 4 (1, 4)
	// 9 4 5 5 (1, 4)
	// 1 2 4 3 (4, 7)
	// 8 3 8 4 (4, 7)
	// 1 4 7 -> (1 4) (4, 7)
	ll inicio = 0, fin = 0, res = 0; 
	while(fin<sz(a)){
		if(a[fin] - a[inicio] >= n){
			inicio++;
		} else {
			ll longa = fin - inicio + 1; 
			res = max(res, longa);
			fin++;
		}
	}
	pri(res);
}
 
int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
		solve();
	}
    return 0;
}
