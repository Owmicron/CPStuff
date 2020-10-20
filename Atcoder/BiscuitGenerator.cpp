#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a,b,t,ans;
int main(){
    cin>>a>>b>>t;
    int sum = 0;
    for(int i=1;i<=1000;i++){
        sum+=a;
        if(sum<=t){ans+=b;}
        else break;
    }
    cout<<ans<<endl;
}
