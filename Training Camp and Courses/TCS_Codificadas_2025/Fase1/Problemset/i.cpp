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
    // Caso especial para cuando el hongo esta en una esquian 
    if(a[0][0] == 'H' || a[0][m-1] == 'H' || a[n-1][0] == 'H' || a[n-1][m-1] == 'H'){
        ll res = max(n, m)-1;
        pri(res);
        return;
    }
    ll cantq = 0;
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
            }else if(a[i][j] == 'Q'){
                cantq++;
            }
        }
    }

    // verificacion de que no se puede 
    bool der2 = false, izq2 = false, arr2 = false, abj2 = false;
    ll cantvec = 0;
    fore(i, 0, n){
        fore(j, 0, m){
            if(a[i][j] == 'H'){
                if(i>0){
                    if(a[i-1][j] == 'Q'){
                        izq2 = true;
                        cantvec++;
                    }
                } 
                if(i<n-1){
                    if(a[i+1][j] == 'Q'){
                        der2 = true;
                        cantvec++;
                    }
                }

                if(j>0){
                    if(a[i][j-1] == 'Q'){
                        arr2 = true;
                        cantvec++;
                    }
                }

                // no puede para abajo
                if(j<m-1){
                    if(a[i][j+1] == 'Q'){
                        abj2 = true;
                        cantvec++;
                    }
                }
                break;
            }
        }
    }
    bool enmedio = false; 
    char medio = a[n/2][m/2]; 
    if(medio=='H'){
        enmedio = true;

    }
    if(cantvec == 1){
        pri(1);
        return;
    }

    if(enmedio && cantq == (n * m )- 1){
        pri(-1);
    }
    if(!der && !izq && !arr && !abj){
        pri(0);
        return;
    }else if(der2 && izq2 && arr2 && abj2){
        if(cantq>0){
            pri(-1);
            return;
        }
    } else{
        if(cantq <= 0){
            pri(0);
            return;
        }
        ll maxs = max(n, m);
        //ll mins = min(n, m);
        ll res = cantq / (maxs-1);
        if(cantvec == 2 && res<=1){
            pri(res+1);
            return;
        }else{
            pri(res);
            return;
        }
        pri(res);
        
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