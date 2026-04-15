#include<bits/stdc++.h> 

using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst fitst
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long; 

typedef vector<ll> vi; 

int main(){
    FIN;
    ll n,q;cin>>n;
    ll arr[n];
    fore(i,0,n){
        cin>>arr[i];
    }
    cin>>q;ll m[q];
    fore(i,0,q){
        cin>>m[i];
    }
    sort(arr,arr+n);
    fore(i,0,q){
        auto k =lower_bound(arr,arr+n,m[i])-arr;
        if(k<n && arr[k]==m[i]){
            auto x= upper_bound(arr,arr+n,m[i])-arr;
            cout<<k+(x-k)<<"\n";
        } else if(k<n){
            cout<<k<<"\n";
        } else {
            cout<<n<<"\n";
        }
    }
    
    return 0;
}