#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
void draw(ll x){
    if(x>0){
        draw(x-1);
        for(ll i=1;i<=x;i++){
            cout<<"*";
        }
        cout<<"\n";
        draw(x-1);
    }
}
int main(){
    ll n;
    cin>>n;
    draw(n);

}
