#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all (x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())
using ll = long long; 
typedef vector<ll> vi; 
typedef pair<int,int> pii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 


int main(){
    FIN;
    ll n, m; cin>>n>>m;

    vector<vi> G (n+1);
    vi dist (n+1, 1000000);

    vector<vi> vaux (n+1, vi(n+1,0));
    ll in1, in2;
    fore(i,0,m){
        cin>>in1>>in2;
        vaux[in1][in2]=1;
        vaux[in2][in1]=1;
    }
    bool b = false;
    if(vaux[1][n]==1){
        b = true;
    }
    fore(i,1,n+1){
        fore(j,1,n+1){
            if ((b && vaux[i][j]==0) || (!b && vaux[i][j]==1)){
                G[i].pb(j);
                G[j].pb(i);
            }
        }
    }

    priority_queue < pii , vector < pii > , greater < pii > > pq ;
    dist[1] = 0;
    pq.push({0, 1});
    
    while (! pq . empty ()) {
        auto [d , u] = pq.top(); pq.pop();
        if ( d > dist [ u ]) continue ;
        for (auto v : G[u]) {
            if ( dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1 ;
                pq.push({ dist[v] , v });
                
            }
        }
    }
    if(dist[n]==1000000){
        cout << -1 << "\n";
        return 0;
    }
    cout << dist[n] << "\n";



    return 0;
}
