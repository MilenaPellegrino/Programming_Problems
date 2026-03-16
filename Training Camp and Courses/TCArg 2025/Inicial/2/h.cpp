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
int main(){
    FIN;
    ll t; cin>>t;
    fore(k, 0, t){
        ll n; cin>>n; 
       vi a(n);
       // ll a[n];
        fore(i, 0, n){cin>>a[i];}
        bool flag = true;
        fore(i, 0, n){
            if(a[i] != i+1){
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<0<<endl;
            continue;
        }
        if(a[0] == 1 || a[n-1] == n){
            cout<<1<<endl;
            continue;
        }
        if(a[0] == n && a[n-1] == 1){
            cout<<3<<endl;
            continue;
        }
        cout<<2<<endl;
    }

    return 0;
}