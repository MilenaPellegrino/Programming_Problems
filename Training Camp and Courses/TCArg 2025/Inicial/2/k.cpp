#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){FIN; 

    int t; cin >> t;
    fore(i,0,t){

        int n; cin >> n;
        vi v(n);
        fore(j,0,n){
            cin>>v[j];
        }
        sort(all(v));
        bool b = false;
        int ceros = v[n-1]==0;
        fore(k,0,n-1){
            if (v[k]==v[k+1]){
                b=true;
            }
            if (v[k]==0){
                ceros++;
            }
        }

        int res = 0;

        if(ceros>0){
            res = n-ceros;
        } else if(b){
            res=n;
        } else {
            res=n+1;
        }

        cout << res << "\n";



    }

    return 0;
}