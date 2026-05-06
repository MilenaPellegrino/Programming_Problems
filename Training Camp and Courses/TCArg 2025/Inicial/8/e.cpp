#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (X).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

ll n;

bool solve (ll k){
    ll acum = n;
    ll sum = 0;
    while(acum>0){
        sum+=min(k,acum);
        acum-=min(k,acum);
        acum = acum - acum/10;
        // cout << acum << "\n";

    }
    // cout << sum << "\n";
    if(sum*2 <n) return false;
    else return true;
}

int main(){
    FIN; 

    cin>>n;

    ll low = 1 , high = n;
    ll res = -1;
    while ( low <= high ) {
        ll mid = ( low + high ) / 2;
        if ( !solve ( mid )) {
            low = mid + 1; // Buscamos el MAXIMO
            res = mid + 1 ;
        } else {
            high = mid - 1;
            res = mid ;
        }
        // cout << mid << "\n\n";

    }

    if(!solve(res)){
        cout << res+1<< "\n";
    } else if (res == 1 && solve(1)){
        cout << 1<< "\n";
    } else if (solve(res-1)){
        cout << res-1<< "\n";
    }else{
        cout << res<< "\n";
    }


    return 0; 
}