#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((ll)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 


int main(){
    FIN; 
    string s; cin>>s;

    ll n = sz(s);

    vi cant_a (n+1);
    vi cant_b (n+1);
    cant_a[0]=0;
    cant_b[0]=0;

    fore(i,1,n+1){
        if(s[i-1]=='a'){
            cant_a[i] = cant_a[i-1] + 1;
            cant_b[i] = cant_b[i-1];
        } else {
            cant_b[i] = cant_b[i-1] + 1;
            cant_a[i] = cant_a[i-1];
        }
    }

    ll min = n;
    fore(i,0,n+1){
        fore(j,i,n+1){
            ll sacar = cant_b[i];
            sacar += cant_a[j] - cant_a[i];
            sacar += cant_b[n] - cant_b[j];
            if (sacar <= min){
                min = sacar;
            }
        }
    }

    cout << n - min << "\n";


    return 0; 
}
