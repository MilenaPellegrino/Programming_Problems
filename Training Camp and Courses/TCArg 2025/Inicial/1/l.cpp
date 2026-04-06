#include<bits/stdc++.h> 
using namespace std;

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second
#define sz(x) ((int)x.size())

//#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using ll = long long; 
typedef vector<ll> vi;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    //dwdw

    ll t; cin >> t;
    while(t--){

        ll n; cin>>n;

        uniform_int_distribution<int> dist(1, n);

        if(n==-1){
            return 0;
        }

        if(n==3){
            cout << "! 1 2 3"<<endl;
            continue;
        }

        vi a = {1,2,3};
        ll in;

        a[0]=dist(gen);
        while(true){
            a[1]=dist(gen);
            if(a[0]!=a[1]) {
                break;
            }
        }
        while(true){
            a[2]=dist(gen);
            if(a[0]!=a[2] && a[1]!=a[2]) break;
        }

        a[0] = 1, a[1] = 2, a[2] =3;
        fore(q,0,75){
            cout << "? " <<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
            cin >> in;
            if (in==-1){
                return 0;
            } else if (in==0) {
                cout << "! " <<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
                break;
            } else {
                a[(q+1)%2]=in;

                if (q==74){
                    cout << "! " <<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
                }
            }
        }

    }

    return 0;
}