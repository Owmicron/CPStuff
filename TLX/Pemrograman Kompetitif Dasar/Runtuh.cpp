#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll r,c,limit;
char b[100][100];
bool combo(){
    bool value=false;
    for(ll i=1;i<=r;i++){
        bool cons=true;
        for(ll j=1;j<=c;j++){
            if(b[i][j]=='0'){cons=false;break;}
        }
        if(cons){
            value=true;
            limit=i;
            for(ll j=1;j<=c;j++){
                b[i][j]='0';
            }
        }
    }
    return value;
}
void collapse(){
    for(ll j=1;j<=c;j++){
        ll ones=0;
        for(ll i=limit; i>=1; i--){
            if(b[i][j]=='1'){ones++;b[i][j]='0';}
        }
        ll drop=limit;
        for(ll i=limit; i<=r; i++){
            if(b[i][j]=='1'){break;}
            else{drop=i;}
        }
        if(ones>0){
            for(ll i=drop ; i >= drop+1-ones; i--){b[i][j]='1';}
        }
    }

}
int main(){
    cin>>r>>c;
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cin>>b[i][j];
        }
    }

    while(combo()){
        collapse();
    }
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }

}
