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
ll col[MAXN];
vi g[MAXN];

bool bfs(ll s){
    queue<ll> q;
    col[s] = 0;
    q.push(s);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(col[v] == -1){
                col[v] = 1 - col[u];
                q.push(v);
            }else if(col[v] == col[u]){
                return false;
            }
        }
    }
    return true;
}

bool esBipar(ll n){
    fill(col, col+n+1, -1);
    fore(i, 1, n+1){
        if(col[i] == -1){
            if(!bfs(i)) return false;
        }
    }
    return true;
}

int main(){
    FIN; 
    ll n, m; cin>>n>>m; 
    fore(i,0,m){
        ll a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    bool ans = esBipar(n);
    if(!ans){
        cout<<"IMPOSSIBLE\n";
    }else{
        fore(i,1,n+1)cout<<col[i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}