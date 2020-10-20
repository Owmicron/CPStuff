#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;ll e;
bool ans;
void pal(){
    for(ll i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){e++;}
    }
}
int main(){
    cin>>s;pal();
    if(e>1){cout<<"NO";}
    else if(e==1){cout<<"YES";}
    else if(e<=0){
        if(s.size()%2==1){cout<<"YES";}
        else{cout<<"NO";}
    }

}


