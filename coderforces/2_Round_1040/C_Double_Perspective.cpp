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

const ll MAXN = 10005;
ll parent[MAXN];
ll rango[MAXN];
vi adj[MAXN];
set<ll> ciclo_curr;

ll ufind(ll x){
    if(parent[x] == x){
        return x;
    }
    parent[x] = ufind(parent[x]);
    return parent[x];
}

// union find con rango para arboles
bool unite(int a, int b) {
    int root_a = ufind(a);
    int root_b = ufind(b);
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

bool dfs(ll u, ll p, ll target, vector<bool> &vis, vi& path) {
    vis[u] = true;
    path.pb(u);
    if (u == target) return true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v] && dfs(v, u, target, vis, path)) return true;
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
    }
    ciclo_curr.clear();

    vi res;
    ll f = 0;

    for (auto &[a, b, idx] : edges) {
        ll len = b - a;
        // db(len);
        if (ufind(a) != ufind(b)) {
            unite(a, b);
            adj[a].pb(b);
            adj[b].pb(a);
            f += len;
            res.pb(idx);
        } else {
            // Conviene agregarle al xiclo?
            set<ll> nod_temp;
            vector<bool> visited(MAXN, false);
            vi path;
            
            if (dfs(a, -1, b, visited, path)) {
                for(ll x : path) nod_temp.insert(x);
                nod_temp.insert(a);
                nod_temp.insert(b);
            }

            ll new_f = f + len;
            ll new_g = sz(ciclo_curr);
            for (ll x : nod_temp) {
                if (!ciclo_curr.count(x)) new_g++;
            }
            //RAYA;
            // db(new_f); db(new_g);
            if (new_f - new_g >= f - (ll)sz(ciclo_curr)) {
                
                // aca nos conviene
                for (ll x : nod_temp) ciclo_curr.insert(x);
                adj[a].pb(b);
                adj[b].pb(a);
                f += len;
                res.pb(idx);
            }
        }
    }
    cout<<sz(res)<<"\n";
    fore(i, 0, sz(res)){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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
