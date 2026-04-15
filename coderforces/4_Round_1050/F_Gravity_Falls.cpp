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

void solve(){
    ll n; cin>>n;
    //ll k; cin>>k;
    vector<vector<ll>> a(n);
    fore(i, 0, n){
        ll a0; cin>>a0;
        a[i].resize(a0);
        fore(j, 0, a0){
            ll aij; cin>>aij; 
            a[i][j] = aij;
        }
    }
    
    sort(all(a));
    reverse(all(a));

    // Relleno con -1 

    // busco el max
    ll maxs = 0;
    for(auto&fila : a){
        maxs = max(maxs, (ll)sz(fila));
    }

    // relleno con -1 a los edmas 
    for(auto&fila : a){
        if((ll)sz(fila) < maxs){
            fila.resize(maxs, -1);
        }
    }
    // fore(i, 0, n){
    //     fore(j, 0, sz(a[i])){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //RAYA;
    ll jult = -1;
    // imprimo  la ultima: 
    fore(i, 0, maxs){
        if(a[n-1][i]!=-1){
            cout<<a[n-1][i]<<" ";
            jult = i;
        }// }else{
        //     jult = i;
        //     break;
        // }
    }
    ll actj = jult;
    //cout<<"SE IMPRIMIO EL 2? "<<endl;
    vi res;
    //ll iult = n-1, jult = sz(a[iult])-1;
    for(ll i = n-2; i>=0; i--){
        for(ll j = jult+1; j<maxs; j++){
            if(a[i][j] != -1){
                //db(a[i][j]); db(i); db(j);
                res.pb(a[i][j]);
                actj = j;
            }
        }
        jult = actj;
    }
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
