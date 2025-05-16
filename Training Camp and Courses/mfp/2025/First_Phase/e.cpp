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

void solve(){
    ll n; cin>>n;
    ll m; cin>>m;
    
    vvi a(n+2, vi(m+2, -1));

    fore(i, 1, n+1){
        fore(j, 1, m+1){
            ll ai; cin>>ai; 
            a[i][j] = ai;
        }
    }

    bool cambiar = true;
    //HAY PROBLEMA? 
    fore(i, 1, n+1){
        fore(j, 1, m+1){
            ll up = a[i-1][j];
            ll down = a[i+1][j];
            ll right = a[i][j+1];
            ll left = a[i][j-1];
            ll act = a[i][j];
            //db(up); db(down); db(right); db(left); db(act);
            // Hay problema
            if(act == up || act == down || act == right || act == left){
                //cout<<"CAPAZ PODAMOS CAMBIAR"<<endl;
                // Podemos cambiar? 
                ll newact = act + 1;

                // Hay algun problema con cambiar? 
                if(newact == up || newact == down || newact == right || newact == left){
                    // NO PODEMOS CAMBIAR
                    cambiar = false;
                    //cout<<"AL FINAL NO PODEMOS CAMBIAR"<<endl;
                    //db(up); db(down); db(right); db(left); db(act); db(newact)
                } else {
                    // PODEMOS CAMBIAR 
                    a[i][j] = newact;
                    //cout<<"CAMBIAMOS"<<endl;
                }
                
            }
        }
    }

    fore(i,1, n+1){
        fore(j, 1, m+1){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
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