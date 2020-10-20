#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a , m , n;
int main(){
    cin>>n>>m;
    a = min(n,m);
    if(a%2 == 0){
        cout<<"Malvika";
    }
    else{cout<<"Akshat";}
}
