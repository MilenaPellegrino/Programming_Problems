# include <bits/stdc++.h>
using namespace std;

#define fore(i, a, b) for (ll i =(a); i <(b); i++)
#define all (x) (x).begin(), (x).end()
#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())



#define FIN ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);


using ll = long long;
typedef vector <ll> vi;

int main () {
    FIN;
    ll n,x,y; cin>>n;
    vi b(n);
    vector<vector<ll>> g(n+1); 
    fore(i,0, n-1){
        cin>>x>>y; 
        g[x].pb(y); 
        g[y].pb(x);
    }
    fore(i, 0, n)cin>>b[i];
    if(b[0]!=1){
        cout<<"NO\n";
        return 0;
    }

    vector<bool> vis(n + 1, false);
    vector<ll> dist(n + 1, 0);

    queue<ll> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 0;

    vi recor;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        recor.pb(u);
        // cout << "u: " << u << endl;
        for (ll v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
                // cout << "vecino: " << v << endl;
            }
        }
        // cout << endl;
    }

    if(recor == b){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}