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
    vi a(n); fore(i, 0, n)cin>>a[i];
    vi b(n); fore(i, 0, n)cin>>b[i];
    // bool flag = true;
    // bool se = false;
    // ll cont = 0;
    // bool dos1 = false;
    // bool dos2 = false;
    // while(flag){
    //     fore(i, 0, n){
    //         if(a[i] > b[i]){
    //             se = true;
    //             a[i] = a[i] - 1;
    //             dos1 = true;
    //         }
    //         if(a[i] < b[i]){
    //             a[i] = a[i] + 1;
    //             dos2 = true;
    //         }
    //         if(dos1 && dos2){break;}
    //     }
    //     if(!se){flag = false;}
    //     cont++;
    //     se = false;
    // }
    // pri(cont);
    ll res = 0;
    fore(i, 0, n){
        if(a[i]>b[i]){
            ll dif = a[i] - b[i]; 
            res+=dif;
        }
    }
    pri(res+1);
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
