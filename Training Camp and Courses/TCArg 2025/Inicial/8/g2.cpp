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
    ll sum=a[0]=='0'?1:0;
    ll ans=0;
    fore(i,1,n){
        if(sum==1 && a[i]=='0'){
            if(b[i-1]=='0'){
                a[i]='X';a[i-1]='X';b[i-1]='X';
                ans++;sum=0;
                if(b[i]=='0' && i+1<n && b[i+1]=='0' && a[i+1]=='0'){
                    b[i]='X';a[i+1]='X';b[i+1]='X';
                    i++;ans++;
                }
            } else if(b[i]=='0'){
                a[i]='X';a[i-1]='X';b[i]='X';
                sum=0;ans++;
            }else{
                sum=1;
            }
        }else if(a[i]=='0'){sum++;}
        else{sum=0;}
    }
    sum = 0;
    fore(i, 0, sz(b)+1){
        if (sum == 2){
            if(a[i-1] == '0' || a[i-2] == '0'){
                b[i-1] = 'X';
                b[i-2] = 'X';
                if(a[i-1] == '0'){
                    a[i-1] = 'X';
                }else{
                    a[i-2] = 'X';
                }
                ans++;
                sum = 0;
            }
        } else if (i <n && b[i] == '0'){
            // cout<<"ac3a"<<endl;
            sum++;
        }else if(i < n && b[i]!= '0'){
            // cout<<"aca33"<<endl;
            sum = 0;
        }
    }
    //cout<<a<<endl<<b<<endl;
    cout<<ans<<"\n";
    return 0; 
}