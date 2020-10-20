#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,mn,sum;
str s;
int main(){
    cin>>n;
    cin>>s;
    mn=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'){sum++;}
        else{sum--;}
        mn = min(mn,sum);
    }
    cout<<sum-mn;
}
