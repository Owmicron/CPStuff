#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,c,cc,ans;
int main(){
    cin>>n;
    c=1;
    while(n>0){
        cc+=c;
        n-=cc;
        c++;
        if(n>=0){ans++;}
    }
    cout<<ans<<endl;
}
