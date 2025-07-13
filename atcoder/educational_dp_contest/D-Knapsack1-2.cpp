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
using vll = vector<ll>;
using vpi = vector<pii>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

ll const MAXW = 1e5 + 10; 
ll const INF = 1e18 + 10;
ll const MAXN = 110;
ll n, we; 
ll w[MAXN], v[MAXN];
ll dp[MAXN][MAXW];

ll f(ll x, ll y){
    if(dp[x][y]!= -1)return dp[x][y];
    if(x == n)return 0;
    if(y < 0) return -INF; 
    if(y==0)return 0;
    if(w[x] <= y){
        dp[x][y] = max(f(x+1, y-w[x]) + v[x], f(x+1, y));
    } else {
        dp[x][y] = f(x+1, y);
    }
    return dp[x][y];
}

void solve(){
	cin>>n>>we; 
    // mset(dp, -1);
    fore(i, 0, MAXN){
        fore(j, 0, MAXW){
            dp[i][j] = -1;
        }
    }
    fore(i, 0, n){
        ll vi, wi; cin>>wi>>vi; 
        v[i] = vi;
        w[i] = wi; 
    }
    ll res = f(0, we);
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
