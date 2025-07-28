#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define RAYA cout<<"=============="<<"\n"
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

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};



void solve(){
    ll n; cin >> n;
    vector<array<ll, 3>> a(n);
    fore(i, 0, n) {
        ll ai, bi; cin>>ai>>bi;
        a[i][0] = ai;
        a[i][1] = bi;
        a[i][2] = i + 1; 
    }

    // Ordeno  por (x asc, y asc)
    sort(all(a));
    // RAYA;
    // fore(i, 0, n){
    //     cout<<a[i][0]<<" "<<a[i][1]<<"\n";
    // }

    // Ordeno la primera mitad por y asc
    sort(a.begin(), a.begin() + n / 2, [](const array<ll, 3> &u, const array<ll, 3> &v) {
        return u[1] < v[1];
    });
    // RAYA;
    // fore(i, 0, n/2){
    //     cout<<a[i][0]<<" "<<a[i][1]<<"\n";
    // }

    // Ordeno la segunda mitad por y asc
    sort(a.begin() + n / 2, a.end(), [](const array<ll, 3> &u, const array<ll, 3> &v) {
        return u[1] < v[1];
    });
    // RAYA;
    // fore(i, n/2, n){
    //     cout<<a[i][0]<<" "<<a[i][1]<<"\n";
    // }

    // RAYA;
    // Emparejo
    fore(i, 0, n / 2) {
        cout<<a[i][2]<<" "<<a[n - i - 1][2]<<"\n";
    }
//     vector<array<ll, 3>> b(n);
//     fore(i, 0, n) fore(j, 0, 3) b[i][j] = a[i][j];

//     // Ordeno a: 
//     // 1 - Los de x menor a mayor (sin importar el empate)
//     // 2 - Los y de menor a mayor 
//     // 3 - EN caso de empate: 
//     // 3.1 - Los x de mayor a menor 
//     sort(all(a));
//     vector<array<ll, 3>> a2(n);
//     fore(i, 0, n/2){
//         a2[i][0] = a[i][0];
//         a2[i][1] = a[i][1];
//         a2[i][2] = a[i][2];
//     } 
//     // cout<<endl<<endl;
//     // fore(i, 0, n/2){
//     //     cout<<a2[i][0]<<" "<<a2[i][1]<<"\n";
//     // }
//     // cout<<endl;
//     sort(a2.begin(), a2.begin() + (n/2), [](const array<ll, 3> &a, const array<ll, 3> &b) {
//         return a[1] < b[1]; 
//     });


//     //     cout<<"PRINT A: "<<endl<<endl;
//     // fore(i, 0, n/2){
//     //     cout<<a2[i][0]<<" "<<a2[i][1]<<"\n";
//     // }

//     // Ordeno b: 
//     // 1 - Los x de mayor a menor (sin importar el empate)
//     // 2 - Los y de mayor a menor 
//     // 3 - En caso de empate: 
//     // 3.1 - Los x de mayor a menor 

//     // Emparejo los primeros n/2 de entre a y b 
//     sort(all(b));
//     //reverse(all(b));
//     vector<array<ll, 3>> b2(n);
//     fore(i, 0, n/2){
//         b2[i][0] = b[i][0];
//         b2[i][1] = b[i][1];
//         b2[i][2] = b[i][2];
//     } 
//     sort(b2.begin(), b2.begin() + (n/2), [](const array<ll, 3> &a, const array<ll, 3> &b) {
//     return a[1] > b[1];
// });
//     //reverse(all(b2));
//     // cout<<endl;
//     // cout<<"PRINT B"<<endl<<endl;
//     // fore(i, 0, n/2){
//     //     cout<<b2[i][0]<<" "<<b2[i][2]<<"\n";
//     // }

//     fore(i, 0, n/2){
//         cout<<a2[i][2]<<" "<<b2[i][2]<<"\n";
//     }
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
