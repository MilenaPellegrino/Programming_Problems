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

const ll INF = 1e18 + 10;
const ll MAXN = 2e5 + 10;

ll n;
ll a[MAXN], dp[MAXN];

ll f(ll x){ // Cantidad m inima de operaciones para hacer "a" beautiful desde x hasta n
	if (x>n) return INF; // Para que nunca elija esta opcion al hacer min
	if(x==n) return 0; //Ya es btf
	ll &res = dp[x];
	if(res!=-1) return res; // memo
	res = min(f(x+1) + 1, f(x + a[x]+1)); // F(x+1) + 1 sacar el elemento de la posicion x
	return res;							 // f(x+a[x]+1) hacer el segmento desde x + a[x] + 1 (la def del ejs)
}
void solve(){
	cin>>n; 
	fore(i, 0, n)cin>>a[i];
	mset(dp, -1);
	ll ans = f(0);
	pri(ans);
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

