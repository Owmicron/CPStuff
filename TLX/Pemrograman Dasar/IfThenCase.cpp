#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll n;
    cin>>n;
    if(n>9999){cout<<"puluhribuan";}
    else if(n>999){cout<<"ribuan";}
    else if(n>99){cout<<"ratusan";}
    else if(n>9){cout<<"puluhan";}
    else{cout<<"satuan";}
    cout<<endl;
}
