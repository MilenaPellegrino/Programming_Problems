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
using vi = vector<ll>;
using vpi = vector<pii>;
using vvll = vector<vector<ll>>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

const ll MAXN = 1e5 + 10;
ll dist[MAXN];
bool vis[MAXN];
vi g[MAXN];
ll par[MAXN];

void bfs(ll s, ll n){
	fill(vis, vis+n+1, false);
	fill(par, par+n+1, -1);
	queue<ll> q;
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	while(!q.empty()){
		ll u = q.front(); 
		q.pop();
		for(ll v: g[u]){
			if(!vis[v]){
				vis[v] = true;
				dist[v] = dist[u] + 1;
				par[v] = u;
				q.push(v);
			}
		}
	}
}

vi camino(ll s, ll t){
	if(!vis[t])return {};
	vi path; 
	for(ll v = t; v!= -1; v = par[v])path.pb(v);

	reverse(all(path));
	return path;
}
void solve(){
	ll n, m; cin>>n>>m;
	fore(i,0,m){
		ll a, b; cin>>a>>b; 
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(1, n);
	vi cam = camino(1, n);
	// fore(i,0, n+2){
	// 	cout<<vis[i]<<" ";
	// }
	// cout<<endl;
	if(!vis[n]){
		cout<<"IMPOSSIBLE\n";
	}else{
		cout<<sz(cam)<<"\n";
		fore(i,0, sz(cam))cout<<cam[i]<<" ";
		cout<<"\n";
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

