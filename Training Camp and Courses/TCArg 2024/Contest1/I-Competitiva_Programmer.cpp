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

ll s(char c){
    ll a = c-'0';
    return  a;
}

bool f(string xi){
    bool two = false, fo = false, six = false, ei = false, ze=false;
    ll cz = 0;
    bool res = true;
    ll sum  = 0;
    fore(i, 0, sz(xi)){
        if(xi[i]== '2'){
            two = true;
        } else if (xi[i] == '4'){
            fo = true;
        } else if (xi[i] == '6'){
            six = true;
        } else if (xi[i] == '8'){
            ei = true;
        } else if (xi[i] == '0'){
            ze=true;
            cz++;
        }
        //db(xi[i]);
        sum+= s(xi[i]);
    }
    //db(sum);
    bool div3 = (sum %3 == 0);
    //db(sum%3);
    res = two || fo || six || ei;
    //db(res);
    //res = res && div3 && ze;
    //db(sum);
    bool ans  = res  && div3 && ze;

    return ans = ans || sum == 0 || (div3 && cz>1);
}




void solve(){
	ll n; cin>>n; 
    fore(i, 0, n){  // n =418 
        string y; cin>>y;
        //db(sum(y));
        if(f(y)){  // sz(y)  = 100
            pri("red");
        } else{
            pri("cyan");
        }
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
