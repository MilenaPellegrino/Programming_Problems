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
    vi a(n); fore(i, 0, n)cin>>a[i];
    unordered_set<ll> st; 
    st.insert(a[0]);
    ll segmax = 1;
    fore(i, 1, n){
        // cout<<endl<<" segmento nueva iteracion"<<endl;
        // for(ll x : st)cout<<x << " ";
        // cout<< endl;
        ll ai = a[i];
        // db(ai);
        // db(segmax);
        if(st.count(ai)){
            // cout<<" estaba en el set "<<endl;
            st.erase(ai);  
            // cout<<"Lo borre, imprimo devuelta el set: "<<endl;
            // for(ll x : st)cout<<x << " ";
            // cout<< endl;   
            if(st.size() == 0){
                // cout<<"ENTRO AL IF DE VACIO"<<endl;
                segmax++;
                st.insert(ai);
            }
        }
        // cout<<"AL FINAL DE TODA LA IT EL SET QUEDO: "<<endl;
        // for(ll x : st)cout<<x << " ";
        // cout<< endl;     
    } 
    cout<<segmax<<"\n";
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