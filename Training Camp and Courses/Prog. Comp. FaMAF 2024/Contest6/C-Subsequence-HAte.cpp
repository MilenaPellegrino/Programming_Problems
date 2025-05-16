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
const ll INF = 1e18;

// max -> sz(s) = 1000 
// O(n^2)? 1e8? 
void solve(){
	string s; cin>>s;
    //cout<<s<<endl;
    ll c = 0, u = 0; 
    fore(i, 0, sz(s)){
        if(s[i] == '0'){
            c++;
        }else{
            u++;
        }
    }

    //db(c); db(u);
    ll res = INF;
    ll cact =0, uact = 0;
    //bool isc = false, isu = false;
    fore(i, 0, sz(s)){
        if(s[i] == '0'){
            cact++;
          //  isc = true;
          //  isu = false;
        } else {
            uact++;
          //  isu = true;
          //  isc = false;
        }
    //if(isc){
    //    res = min(res, uact + cact  - c);
    //} else{
   //     res = min(res, cact + uact - u);
   // }
     ll res1= min(res, (c - cact) + uact); // db(res1);
     ll res2 = min(res, (u - uact) + cact); // db(res2);
     res = min(res, res1);
     res = min(res, res2);
    //db(cact); db(uact);
    //db(res);
    }
    pri(res);
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
