#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=(a);i<(b);i++)
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
using vi = vector<ll>;
using vpi = vector<pii>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

const ll MAXN = 1e5 +10;
ll dp[MAXN]; 
ll n; 
vi a;

ll f(ll i){
    if(dp[i]!=-1)return  dp[i];
    if (i == n) return dp[i] = 0;
    if (i == n-1) return dp[i] = 0;
    if (i==n-2) return dp[i] = abs(a[n-1] - a[n-2]);
    dp[i] = min(f(i+1) + (abs(a[i] - a[i+1])), f(i+2) + (abs(a[i] - a[i+2]))); 
    return dp[i];
}

void solve(){
	mset(dp, -1);
    cin>>n; 
    fore(i, 0, n){
        ll ai; cin>>ai;
        a.pb(ai);
    }
    ll res = f(0);
    cout<<res<<"\n";

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
