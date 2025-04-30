#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}


vector<vector<int>> ady;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : ady[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void countOperations(int n, int m) {
    // Contar componentes conexos
    visited.assign(n, false);
    int components = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    
    // Conexiones a agregar: componentes - 1
    int add = components - 1;
    
    // Conexiones a eliminar: m - (n - 1) + add
    // Un árbol tiene n-1 aristas, y ya agregamos 'add' conexiones
    int remove = m - (n - 1 - add);
    
    // No puede ser negativo
    remove = max(remove, 0);
    
    cout << "Conexiones a agregar: " << add << endl;
    cout << "Conexiones a eliminar: " << remove << endl;
}

void solve() {
    ll n, m; cin>>n>>m;
    
    ady.clear();
    ady.resize(n);
    
    fore(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        ady[a].push_back(b);
        ady[b].push_back(a);
    }
    
    countOperations(n, m);
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