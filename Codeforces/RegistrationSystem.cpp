#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
str s;
map < str,int > m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if( m[s] == 0 ){printf("OK\n");}
        else{cout<<s<<m[s]<<endl;}
        m[s]++;
    }
}
