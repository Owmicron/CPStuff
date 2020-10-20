#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int a,b;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='0'){a++;}
            else{b++;}
        }
        else{
            if(s[i]=='1'){a++;}
            else{b++;}
        }
    }
    cout<<min(a,b)<<endl;
}
