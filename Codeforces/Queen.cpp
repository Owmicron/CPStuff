#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int respect[200000],n,c[200000],root;
vector <int> ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d %d",&p,&c[i]);
        if(p>-1 && c[i]==0){respect[p]++;}
        if(p==-1){root=i;}
    }
    for(int i=1;i<=n;i++){
        if(i!=root && c[i]==1 && respect[i]==0){
            ans.push_back(i);
        }
    }
    if(ans.empty()){printf("-1\n");}
    else{
        for(int i=0;i<ans.size();i++){
            printf("%d",ans[i]);
            if(i<ans.size()-1){printf(" ");}
            else{printf("\n");}
        }
    }
}
