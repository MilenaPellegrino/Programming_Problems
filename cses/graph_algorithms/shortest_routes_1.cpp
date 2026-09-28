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
const ll INF = 1e18+10;
typedef vector<ll> vi; 

const ll MAXN = 1e5+10;
vector<pair<ll, ll>> g[MAXN];
ll dist[MAXN];

void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    fill(dist, dist+MAXN, INF);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d>dist[u])continue;
        for(auto [v, w] : g[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
            
        }
    }
}
int main(){
    FIN; 
    ll n, m; cin>>n>>m; 
    fore(i,0,m){
        ll a, b, c; cin>>a>>b>>c;
        g[a].pb({b, c});
    }
    dijkstra(1);
    fore(i, 1, n+1)cout<<dist[i]<<" ";
    cout<<"\n";
    return 0;
}