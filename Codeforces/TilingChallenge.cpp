#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
char tile[60][60];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tile[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tile[i][j]=='.' && tile[i-1][j]=='.' && tile[i+1][j]=='.' && tile[i][j-1]=='.' && tile[i][j+1]=='.'){
                tile[i][j]='#';
                tile[i+1][j]='#';
                tile[i-1][j]='#';
                tile[i][j+1]='#';
                tile[i][j-1]='#';
            }
        }
    }
    bool full=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tile[i][j]!='#'){full=false;break;}
        }
    }
    if(full)cout<<"YES";
    else cout<<"NO";
}
