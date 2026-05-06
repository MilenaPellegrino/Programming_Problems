#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;

int main(){FIN;
    ll n;cin>>n;
    ll b[n];
    fore(i,0,n){
      cin>>b[i];
    }
    ll c=b[0]/9;
    ll re=b[0]-9*c;
    string num;
    fore(i,0,c){
      num.pb('9');
    }
    string ss=to_string(re);
    fore(i,0,size(ss)){num.pb(ss[i]);}
    cout<<num<<endl;
    ll last= stol(num);
    fore(i,1,n){
      if(a[i-1]>=a[i]){
         c++;
         ll b=pow(10,c);
         b+=(a[i]-1);
         cout<<b<<"\n";
         last=b;
      } else if(last<pow(10,c+1)){
         cout<<a[i]*pow(10,c)<<"\n";
         last=a[i]*pow(10,c);
      }else{
         c++;
         ll b=pow(10,c);
         b+=(a[i]-1);
         cout<<b<<"\n";
         last=b;
      }
    }

   return 0;
}