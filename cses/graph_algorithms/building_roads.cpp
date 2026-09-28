#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for (ll i=(a);i<(b);i++)
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
using vvll = vector<vector<ll>>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

const ll MAXN = 1e5+10;
bool vis[MAXN];
vi g[MAXN];

vi lista; 
void dfs(ll u){
    vis[u] = true;
    for (ll v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

ll comp(ll n){
    ll ans = 0;
    fore(i,0,n){
        if(!vis[i]){
            dfs(i);
            ans++;
            lista.pb(i+1);
        }
    }
    return ans;
}

void solve(){
    ll n, m; cin>>n>>m; 
    fore(i,0, m){
        ll a, b; cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll compo = comp(n);
    // db(compo);
    // cout<<lista<<endl;
    cout<<compo-1<<"\n";
    if(compo-1>0){
        ll primer = lista[0];
        fore(i, 1, sz(lista)){
            cout<<primer<<" "<<lista[i]<<"\n";
        }
    }
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
