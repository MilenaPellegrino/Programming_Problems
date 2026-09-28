#include<bits/stdc++.h> 
using namespace std; 
#define fore(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define snd second 
#define sz(x) ((int)x.size())
#define db(x) cout<<#x<<" = "<<(x)<<"\n";
 
#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
using ll = long long; 
typedef vector<ll> vi; 

const ll MAXN = 1e5+10;
bool vis[MAXN];
vi g[MAXN];
ll cicloU = -1, cicloV = -1;
ll par[MAXN];
bool tieneCiclo(ll u, ll parent){
    vis[u] = true;
    for(ll v: g[u]){
        if(!vis[v]){
            if(tieneCiclo(v, u))return true;
        }else if(v!=parent)return true;
    }
    return false;
}

bool ciclo(ll n){
    memset(vis, 0, sizeof(vis));
    fore(i,0,n){
        if(!vis[i]){
            if(tieneCiclo(i, -1))return true;
        }
    }
    return false;
}

bool dfs(ll u, ll parent){
    vis[u] = true;
    par[u] = parent;
    for(ll v : g[u]){
        if(!vis[v]){
            if(dfs(v, u)) return true;
        }else if(v != parent){
            cicloU = u;
            cicloV = v;
            return true;
        }
    }
    return false;
}

int main(){
    FIN; 
    ll n, m; cin>>n>>m; 
    fore(i,0,m){
        ll a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    fore(i, 1, n+1){ 
        if(!vis[i]){
            if(dfs(i, -1)) break;
        }
    }
    if(cicloU == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        vi path;
        path.pb(cicloV); 
        for(ll x = cicloU; x != cicloV; x = par[x]) path.pb(x);
        path.pb(cicloV); 
        cout<<sz(path)<<"\n";
        fore(i, 0, sz(path))cout<<path[i]<<" ";
        cout << "\n";
    }
    return 0;
}