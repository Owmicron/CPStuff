#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool power,t,space,soul,reality,mind;
int main(){
    ll n;
    cout<<pow(3,2);
    cin>>n;
    for(ll i=1;i<=n;i++){
        str temp;
        cin>>temp;
        if(temp=="red"){reality=true;}
        else if(temp=="purple"){power=true;}
        else if(temp=="green"){t=true;}
        else if(temp=="blue"){space=true;}
        else if(temp=="orange"){soul=true;}
        else if(temp=="yellow"){mind=true;}
    }
    cout<<6-n<<endl;
    if(!power){cout<<"Power"<<endl;}
    if(!reality){cout<<"Reality"<<endl;}
    if(!t){cout<<"Time"<<endl;}
    if(!space){cout<<"Space"<<endl;}
    if(!soul){cout<<"Soul"<<endl;}
    if(!mind){cout<<"Mind"<<endl;}
}
