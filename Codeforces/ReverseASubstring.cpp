#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,ans1,ans2;
str s;
bool valid;
int main(){
    cin>>n;
    cin>>s;
    valid=false;
    for(int i=1;i<s.size();i++){
        if(s[i]<s[i-1]){
            ans1=i;
            ans2=i+1;
            valid=true;break;
        }
    }
    if(valid){cout<<"YES\n";cout<<ans1<<" "<<ans2<<endl;}
    else{cout<<"NO\n";}
}
