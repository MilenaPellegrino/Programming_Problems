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
/*
    a = [a1, a2, a3, ..., a_n] -> tam n 
    b = [b1, b2, b3, .., b_m] -> tam m 

    each int i e [1, n]
    most once: 

    j e [1, m]
    ai = bj - ai (ai puede llegar a ser negativo)

    nondec = [1, 1, 1, 2, 3, 4, 4, 5]

*/

ll ops (ll ai, ll bj, vi& a, vi& b){
    //l aii = a[ai];
    //ll bjj = b[bj];
    ll bjj = bj;
    ll aii = ai; 
    return bjj - aii;
}

void solve(){
    ll n, m; cin>>n>>m;  // m = 1
    vi a(n); 
    fore(i, 0, n)cin>>a[i];
    vi b(m); 
    fore(i, 0, m)cin>>b[i];

    // Caso donde a = 1
    if(sz(a) == 1){
        cout<<"YES"<<"\n";
        return;
    }

    // Caso donde a ya esta ordenado 
    bool ord = true;
    fore(i, 0, n){
        if(a[i] > a[i+1])ord = false;
    }
    if(ord){
        cout<<"YES"<<"\n";
        return;
    }

    // Caso general 
    // fore(i, 0, n-1){
    //     if(a[i]>a[i+1]){
    //     //a[i] = ops(a[i], b[0], a, b);
    //         a[i] = b[0] - a[i];
    //     }
    // }
    vi c = a;
    bool flag = true;
    fore(i, 0, n){
        ll a2 = ops(a[i], b[0], a, b);
        ll a1 = a[i];
        if (i == 0) {
            c[i] = min(a1, a2);
        } else {
            bool v1 = (a1 >= c[i-1]);
            bool v2 = (a2 >= c[i-1]);
            if (!v1 && !v2) {
                flag = false;
                break;
            }
            if (v1 && v2) c[i] = min(a1, a2);
            else if (v1) c[i] = a1;
            else c[i] = a2;
        }
    }
    
    if(flag){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    //cout<<a<<endl;
    // verifico que quedo ordenado
    // ord = true;
    // fore(i, 0, n-1){
    //     if(a[i] > a[i+1]){
    //         ord = false;
    //     //cout<<"entree"<<endl;
    //     //db(a[i]); db(a[i+1]);
    //     //db(n);
    //     }
    // }
    // if(ord){
    //     cout<<"YES"<<"\n";
    //     return;
    // } else {
    //     cout<<"NO"<<"\n";
    //     return;
    // }
   
}

int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0; }