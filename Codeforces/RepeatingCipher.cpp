#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s,ans;
int idx,sz,n;
int main(){
    cin>>n;
    cin>>s;
    idx=0;sz=1;
    while(idx<s.size()){
        ans += s[idx];
        idx+=sz;
        sz++;
    }
    cout<<ans<<endl;
}
