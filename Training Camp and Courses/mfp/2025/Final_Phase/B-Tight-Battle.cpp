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

// dp[i] = "Maximo numero de anillos que ada puede conseguir desde la posicion i si ambos juegan de forma optima". 

/*
Desde una posicion i ada puede: 
    - Agarrar al enemigo i, entonces el otro empieza desde i + 1
    - Agarrar al enemigo i e i + 1, entonces el otro empieza desde i + 2
*/

const ll MAXN = 2e5 + 10;
vi sufsum(MAXN, 0);
ll dp[MAXN];
ll n;
ll f(ll i){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i]; 
    dp[i] = sufsum[i] - min(f(i+1),f(i+2));
    return dp[i];
}
void solve(){
	cin>>n;
    vi a(n); fore(i, 0, n)cin>>a[i];
    sufsum[n] = 0;
    for(ll i = n - 1; i >= 0; i--){
        sufsum[i] = a[i] + sufsum[i+1];
    }
    mset(dp, -1);
    ll res = f(0);
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
