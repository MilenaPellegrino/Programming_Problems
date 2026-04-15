#include<bits/stdc++.h> 

using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst fitst
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long; 

typedef vector<ll> vi; 

ll res=0;


void dfs(int v, ll m, vector<vector<ll>> & adj, vector<bool> & visited, vi &consec, vi &gatos, vi &padres) {
    visited[v] = true;
    if(v!=0){
        if(gatos[v]==1) consec[v] = consec[padres[v]] + 1;
        else consec[v] = 0;
    }
    if(consec[v]!=m){
        bool aux=false;
        for (int u : adj[v]) {
            if (!visited[u]){
                aux=true;
                padres[u]=v;
                dfs(u, m, adj,  visited, consec, gatos, padres);
            }
        }
        if(!aux){
            res++;
        }
    }
}

int main(){

    ll n,m,a,b;cin>>n>>m;
    vi gatos(n);
    vi consec(n,-1);
    vector<vector<ll>> adj(n);

    fore(i,0,n){
        cin>>gatos[i];
    }
    fore(i,0,n-1){
        cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    vector<bool> visited(n,false);
    vi padres(n,-1);
    
    consec[0] = gatos[0];
    dfs(0, m+1, adj,  visited, consec, gatos, padres);

    cout << res << "\n";


    return 0;
}