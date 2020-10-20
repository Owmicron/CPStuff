#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,f;
str s,temp;
int y,x;
int one;
int main(){
    cin>>n>>x>>y;
    cin>>s;
    for(int i=s.size()-1;i>=s.size()-x;i--){
        temp = s[i]+temp;
    }
    one = temp.size()-1-y;
    for(int i=0;i<temp.size();i++){
        if(i==one){if(temp[i]=='0')f++;}
        else{if(temp[i]=='1')f++;}
    }
    cout<<f<<endl;

}
