#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 


int main(){
    FIN; 
    ll n; cin>>n; 
    vi sums; 
    ll a[n][7];
    fore(i, 0, n){
        string s; cin>>s;
        fore(j, 0, sz(s)){
            //ll num = 1;
            if(s[j] == '0'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }

    fore(j, 0, 7){
        ll sum = 0; 
        fore(i, 0, n){
            sum+= a[i][j];
        }
        sums.pb(sum);
    }
    sort(all(sums));
    reverse(all(sums)); 
    cout<<sums[0]<<"\n";
    return 0; 
}
