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

ll get_max(ll cant1, ll cant0){
    ll res = 0;
    if(cant1 >= cant0){
        res = 1; 
    }
    return res;
}
void solve(){
    ll n; cin>>n;
    ll k; cin>>k; 
    string s; cin>>s; 
    ll cant1 = 0, cant0 = 0;
    fore(i, 0, sz(s)){
        if(s[i] == '0'){
            cant0++;
        } else{
            cant1++;
        }
    }
   
    ll maxs = (cant0/2) + (cant1 / 2);
    ll mins = (n/2) - min(cant0, cant1);  // todos los ceros de un lado y los unos de otro

    if (mins < 0) mins = 0;

    bool res = true; 
    if ((k<mins) || (k>maxs)) res = false;
    if(k%2 != maxs % 2) res = false;
    if(res){
        cout<<"YES"<<"\n";
    }else {
        cout<<"NO"<<"\n";
    }
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