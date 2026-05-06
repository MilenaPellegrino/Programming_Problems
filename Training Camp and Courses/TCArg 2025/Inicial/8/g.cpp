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
    string a;
    string b; 
    string RAYA = "===========";
    char CERO = '0';
    char X = 'X';
    cin>>a>>b; 
    // a = "X" + a;
    // a+= "X"; 
    // b = "X" + b;
    // b+= "X"; 
    // cout<<a<<endl;
    // cout<<b<<endl;
    ll sum = 0; 
    ll ans = 0;
    ll n = sz(a);
    fore(i, 0, sz(a)+1){
        if(i%2 == 0){
            if (sum == 2){
                if(b[i-1] == CERO || b[i-2] == CERO){
                    a[i-2] =X;
                    a[i-1] = X;
                    if(b[i-2] == CERO){
                        b[i-2] = 'X';
                    }else{
                        b[i-1] = 'X';
                    }
                    ans++;
                    sum = 0;
                }
            } else if (i < n && a[i] == CERO){
                // cout<<"aca"<<endl;
                sum++;
            }else if(i < n && a[i]!= CERO){
                sum = 0;
            }
        }else{
            if (sum == 2){
                if(a[i-1] == CERO || a[i-2] == CERO){
                    b[i-1] = X;
                    b[i-2] = X;
                    if(a[i-1] == CERO){
                        a[i-1] = 'X';
                    }else{
                        a[i-2] = 'X';
                    }
                    ans++;
                    sum = 0;
                }
            } else if (i <n && b[i] == CERO){
                // cout<<"ac3a"<<endl;
                sum++;
            }else if(i < n && b[i]!= CERO){
                // cout<<"aca33"<<endl;
                sum = 0;
            }
        }

    }
    sum = 0;
    fore(i, 0, sz(b)+1){
        if (sum == 2){
            if(a[i-1] == CERO || a[i-2] == CERO){
                b[i-1] = X;
                b[i-2] = X;
                if(a[i-1] == CERO){
                    a[i-1] = 'X';
                }else{
                    a[i-2] = 'X';
                }
                ans++;
                sum = 0;
            }
        } else if (i <n && b[i] == CERO){
            // cout<<"ac3a"<<endl;
            sum++;
        }else if(i < n && b[i]!= CERO){
            // cout<<"aca33"<<endl;
            sum = 0;
        }
    }
    // cout<<a<<endl<<b<<endl;
    cout<<ans<<"\n";
    return 0; 
}