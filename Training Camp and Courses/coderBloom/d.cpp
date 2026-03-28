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

struct DSU {
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    // Find con Path Compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
};

ll conver(ll r, ll c, ll m){
    return r * m + c;
} 

void solve(){
    ll n; cin>>n;
    ll m, q; cin>>m>>q; 
    ll OUT = n*m;
    DSU dsu(n * m + 1);
    vector<vector<bool>> active(n, vector<bool>(m, false));
    // Derecha, Izquierda, Abajo, Arriba
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    while(q--){
        char op; cin>>op;
        if(op == 'U'){ // unir
            ll r, c; cin>>r>>c;
            r--; c--;

            active[r][c] = true;
            ll u = conver(r, c, m);

            // bordee? 
            if(r == 0 || r == n-1 || c == 0 || c == m-1){
                dsu.unite(u, OUT);
            }

            // no borde
            fore(i, 0, 4){
                ll vear = r + dr[i]; 
                ll veec = c + dc[i];
                if(vear >= 0 && vear < n && veec >= 0 && veec < m){
                    if(active[vear][veec]){
                        ll rr = conver(vear, veec, m);
                        dsu.unite(u, rr);
                    }
                }
            }


        }else{ // consultar
            ll r, c; cin>>r>>c; 
            r--; c--;
            if(!active[r][c]){
                cout<<"NO\n";
            }else{
                if(dsu.find(conver(r,c, m)) == dsu.find(OUT)){
                    cout<<"SI\n";
                }else{
                    cout<<"NO\n";
                }
            }
        }
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