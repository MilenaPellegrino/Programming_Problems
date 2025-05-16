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
typedef vector<bool> vb;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}



void dfs(ll u, vb& vis, vvi& ady){
    vis[u] = true;
    for (ll v:ady[u]) {
        if (!vis[v]) {
            dfs(v, vis, ady);
        }
    }
}



void solve(){
    ll n; cin>>n;
    ll m; cin>>m; 
    
    vvi ady(n);
    vb vis(n, false);

    // Graph (idea: quede una linea)
//     bool ady[n][m];
//     fore(i, 0, n){
//         fore(j, 0, m){
//             ady[i][j] = false;
//         }
//     }
//     fore(i, 0, m){
//         ll a, b; cin>>a>>b;
//         ady[a][b] = true;
//         ady[b][a] = true;
//     }
//    // fore(i, 0, n){
//    //     fore(j, 0, m){
//     //        cout<<ady[i][j]<<" ";
//      //   }
//   //      cout<<endl;
//    // }
//    for(ll n : ady[m]){
//         cout<<"arista "<<n<<" -> "<<m<<endl;
//    }

    //vvi adj(n);
    fore(i, 0, m){
        ll a, b; cin>>a>>b; 
        a--; b--;   /// NO ME ANDABA POR ESTO DIOSSS
        ady[a].pb(b);
        ady[b].pb(a);
    }
    
    
    // fore(i, 0, n){
    //     vis[i] = false;
    // }

    ll conx = 0;
    fore(i, 0, n){
        if (!vis[i]){
            conx++;
            dfs(i, vis, ady);
        }
    }

    ll constr = conx - 1;

    // destr = total - nodos--
    ll destr = m - (n-1-constr);

    //db(constr); db(destr);

    //cout<<endl<<endl<<endl;
    // fore(i, 0, sz(ady)){
    //     for(ll v : ady[i]){
    //         cout<<i<<" -> "<<v<<endl;
    //     }
    // }
    if(constr == destr && constr == 0){
        cout<<"BOM"<<"\n";
    } else{
        cout<<"RUIM"<<" "<<destr<<" "<<constr<<'\n';
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