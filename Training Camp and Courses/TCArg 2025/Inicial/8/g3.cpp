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

int main(){
    FIN; 
    string a,b;cin>>a>>b;
    ll n=sz(a);
    ll sum = 0;

    fore(i,0,n-1){

        if(a[i]==b[i] && a[i]=='X'){
            continue;
        }if(a[i]==b[i]){
            if(a[i+1]==a[i]){
                a[i+1]='X';
                sum++;
            } else if (b[i+1]==a[i]){
                b[i+1]='X';
                sum++;
            }
        } else if (a[i+1]==b[i+1] && a[i+1]=='0'){
            sum++; i++;
        }

    }


    cout<<sum<<"\n";
    return 0; 
}