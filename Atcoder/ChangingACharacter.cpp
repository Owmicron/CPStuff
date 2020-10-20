#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k;
str s,ans;
int main(){
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i==(k-1)){
            char c;
            c = s[i];
            int x;
            x = int(c);
            if(x>=65 && x<=90){x+=32;}

            ans += char(x);
        }
        else{
            ans += s[i];
        }
    }
    cout<<ans<<endl;
}
