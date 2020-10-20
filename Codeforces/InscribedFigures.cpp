#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[200],f;
bool inf;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i-1]==2 && a[i]==3){inf=true;break;}
        if(a[i-1]==3 && a[i]==2){inf=true;break;}
        if(a[i-1]==1 && a[i]==2){
            f+=3;
            if(i>2 && a[i-2]==3){f--;}
        }
        if(a[i-1]==1 && a[i]==3){f+=4;}
        if(a[i-1]==2 && a[i]==1){f+=3;}
        if(a[i-1]==3 && a[i]==1){f+=4;}
    }
    if(inf)cout<<"Infinite\n";
    else{
        cout<<"Finite\n";
        cout<<f<<endl;
    }
}
