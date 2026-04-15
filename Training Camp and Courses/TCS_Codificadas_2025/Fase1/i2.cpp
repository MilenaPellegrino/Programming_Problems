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

// me trate de guiar de este coidgo que hice: https://cses.fi/problemset/result/9267058/
// aunque no me sirvio, pero me ayudo a recordar como modelar una grilla como grafo 
vector<pair<ll, ll>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // derecha - izquierda - arriba - abajo

void solve(){
    ll n; cin>>n;
    ll m; cin>>m; 
    vector<vector<char>> a(n, vector<char>(m)); 
    fore(i, 0, n){
        fore(j, 0, m){
            char c; cin>>c;
            a[i][j] = c;
        }
    }

    // Voy a empezawar a correr bfs desde el hongo: 
    pair<ll, ll> hongo; 
    fore(i, 0, n){
        fore(j, 0, m){
            if(a[i][j] == 'H'){
                hongo = {i, j};
                break;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<ll, ll>> q; 
    q.push(hongo);
    vis[hongo.fst][hongo.snd] = true;


    // medio pelo el algoritmo pero mepa que es de sink y sumideros => discreta 2 

    while(!q.empty()){
        pair<ll, ll> act ={q.front().fst, q.front().snd};
        q.pop();
        fore(i, 0, sz(moves)){
            ll x = moves[i].fst + act.fst;
            ll y = moves[i].snd + act.snd;

            // verificamos los limites para no pasarnos 
            if(x>=0 && x<n && y>=0 &&y<m){
                if(!vis[x][y] && a[x][y] == 'Q'){
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

    ll posibles = 0; 
    fore(i, 0, n){
        fore(j, 0, m){
            if(a[i][j] == 'Q' && vis[i][j])posibles++;
        }
    }

    // Caso especial para cuando el hongo esta en una esquian 
    if(a[0][0] == 'H' || a[0][m-1] == 'H' || a[n-1][0] == 'H' || a[n-1][m-1] == 'H'){
        ll res = max(n, m)-1;
        pri(res);
        return;
    }
    
    // Caso donde H no se puede mover: 
    bool der  = true, izq = true, arr  = true, abj = true;
    fore(i, 0, n){
        fore(j, 0, m){
            if(a[i][j] == 'H'){
                // no puede a la izquierda
                if(i>0){
                    if(a[i-1][j] == '.'){
                        izq = false;
                    }
                } 

                // no puede a la derecha 
                if(i<n-1){
                    if(a[i+1][j] == '.'){
                        der = false;
                    }
                }

                // no puede para arriba 
                if(j>0){
                    if(a[i][j-1] == '.'){
                        arr = false;
                    }
                }

                // no puede para abajo
                if(j<m-1){
                    if(a[i][j+1] == '.'){
                        abj = false;
                    }
                }
                break;
            }
        }
    }
    if(!der && !izq && !arr && !abj){
        pri(0);
        return;
    }else{
        pri(2);
        return;
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