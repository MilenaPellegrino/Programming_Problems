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

ll const MAXN = 1e5+10; 
ll const INF = 1e9 + 10;
ll dp[MAXN][3]; 
ll n;
ll days[MAXN][3];

ll f(ll x, ll y){
    if(dp[x][y] != -1) return dp[x][y];
    ll v1 = (y+1) % 3; 
    ll v2 = (y+2) %3;
    if (x == n-1) return dp[x][y] = max(days[n-1][v1], days[n-1][v2]); 
    if(x==n) return 0;
    dp[x][y] = max(f(x+1, v1) + days[x][v1], f(x+1, v2) + days[x][v2]); 
    return dp[x][y];
}   

void solve(){
    cin>>n;
	mset(dp, -1);
    fore(i, 0, n){
        ll ai, bi, ci; cin>>ai>>bi>>ci; 
        days[i][0] = ai;
        days[i][1] = bi;
        days[i][2] = ci;
    }
    ll v1 = f(0, 0); 
    ll v2 = f(0, 1); 
    ll v3 = f(0, 2);
    ll res = max(v1, v2);
    res  = max(res, v3);
    pri(res);
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
