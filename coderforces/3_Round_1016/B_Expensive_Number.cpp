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
    string n; cin>>n; 
    ll cant0 = 0;
    fore(i, 0, sz(n)){
        if(n[i] == '0')cant0++;
    }
    //Caso especial no hay 0's 
    if(cant0 == 0){
        cout<<sz(n) - 1<<"\n";
        return;
    }
    // Caso especial 1 cifra
    if(sz(n) == 1){
        cout<<0<<"\n";
        return;
    }

    // Caso general
    reverse(all(n)); 
    ll cont = 0;
    ll lim = 0;
    fore(i, 0, sz(n)){
        if(n[i] != '0'){
            lim = sz(n) - i;
            break;
        }
        cont++;
    }
    reverse(all(n));
    fore(i, 0, lim-1){
        if(n[i]!='0'){
            cont++;
        }
    }
    cout<<cont<<"\n";
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