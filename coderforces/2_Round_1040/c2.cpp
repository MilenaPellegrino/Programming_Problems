#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define RAYA cout<<"=============="<<"\n"
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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string YES = "YES\n"; 
string NO = "NO\n";

const ll MAXN = 6005;
ll parent[MAXN];
ll rango[MAXN];
vi adj[MAXN];
//set<ll> ciclo_curr;
bool in_cycle[MAXN];

ll ufind(ll x){
    if(parent[x] == x){
        return x;
    }
    parent[x] = ufind(parent[x]);
    return parent[x];
}

// union find con rango
bool unite(ll a, ll b) {
    ll root_a = ufind(a);
    ll root_b = ufind(b);
    if (root_a == root_b) return false;
    
    if (rango[root_a] < rango[root_b]) {
        parent[root_a] = root_b;
    } else if (rango[root_a] > rango[root_b]) {
        parent[root_b] = root_a;
    } else {
        parent[root_b] = root_a;
        rango[root_a]++;
    }
    return true;
}

// bool dfs(ll u, ll p, ll target, vector<bool> &vis, vi& path) {
//     vis[u] = true;
//     path.pb(u);
//     if (u == target) return true;
//     for (ll v : adj[u]) {
//         if (v == p) continue;
//         if (!vis[v] && dfs(v, u, target, vis, path)) return true;
//     }
//     path.pop_back();
//     return false;
// }

bool tiene_ciclo(ll u, ll p, vector<bool>& vis, vi& path) {
    vis[u] = true;
    path.pb(u);
    
    for (ll v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            // Encontramoooooooooooooooooooos un ciclo
            for (ll x : path) in_cycle[x] = true;
            return true;
        }
        if (tiene_ciclo(v, u, vis, path)) return true;
    }
    
    path.pop_back();
    return false;
}



void solve(){
    ll n; cin>>n;
    // {ai, bi, i}
    vector<array<ll, 3>> edges(n);
    fore(i, 0, n) {
        ll ai, bi; cin >> ai >> bi;
        edges[i] = {ai, bi, i + 1};
    }
    // fore(i, 0, sz(edges)){
    //     cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<"\n";
    // }
    sort(all(edges), [](auto &x, auto &y) {
        return (x[1] - x[0]) > (y[1] - y[0]);
    });
    
    fore(i, 0, MAXN) {
        parent[i] = i;
        rango[i] = 0;
        adj[i].clear();
        in_cycle[i] = false;
    }
    vi select;
    set<ll> covs; 
    ll f = 0, g = 0;
    
    for (auto& [a, b, idx] : edges) {
        if (ufind(a) != ufind(b)) {
            unite(a, b);
            adj[a].pb(b);
            adj[b].pb(a);
            ll new_cover = 0;
            for (ll x = a; x < b; x++) {
                if (!covs.count(x)) {
                    new_cover++;
                    covs.insert(x);
                }
            }
            f += new_cover;
            select.pb(idx);
        }
    }
    
       for (auto &[a, b, idx] : edges) {
        if (find(all(select), idx) != select.end()) continue;

        // Probamos añadir temporalmente
        adj[a].pb(b);
        adj[b].pb(a);

        vector<bool> vis(MAXN, false);
        vi path;
        bool has_cycle = false;

        if (!in_cycle[a] || !in_cycle[b]) {
            has_cycle = tiene_ciclo(a, -1, vis, path);
        }

        if (has_cycle) {
            ll new_cycle_nodes = 0;
            unordered_set<ll> unique_path(path.begin(), path.end());
            for (ll x : unique_path) {
                if (!in_cycle[x]) new_cycle_nodes++;
            }

            ll new_cover = 0;
            for (ll x = a; x < b; x++) {
                if (!covs.count(x)) new_cover++;
            }

            if (new_cover > new_cycle_nodes) {
                f += new_cover;
                for (ll x = a; x < b; x++) covs.insert(x);
                for (ll x : unique_path) in_cycle[x] = true;
                g += new_cycle_nodes;
                select.pb(idx);
            } else {
                adj[a].pop_back();
                adj[b].pop_back();
            }
        } else {
            adj[a].pop_back();
            adj[b].pop_back();
        }
    }

    cout<<sz(select)<<"\n";
    fore(i, 0, sz(select)){
        cout<<select[i]<<" ";
    }
    cout << "\n";
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
