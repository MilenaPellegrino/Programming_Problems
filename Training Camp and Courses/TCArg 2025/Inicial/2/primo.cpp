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

bool esPrimo(int n){
    if(n<=1)return false; 
    if(n == 2)return true; 
    if(n%2 == 0)return false; 
    for(int i = 3; i*i <= n; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    FIN;
    int n; cin>>n; 
    cout<<esPrimo(n)<<endl;

    return 0;
}