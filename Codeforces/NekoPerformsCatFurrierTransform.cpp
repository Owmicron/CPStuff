#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int x,dua[40],steps;
vector<int> bit,ans;
bool perfect(){
    int one=0;
    for(int i=0;i<bit.size();i++){
        if(bit[i]==1){one++;}
    }
    if(one==bit.size())return true;
    return false;
}
void to_bit(int z){
    while(!bit.empty()){
        bit.pop_back();
    }
    while(z>0){
        if(z%2==0){
            bit.push_back(0);
        }
        else{
            bit.push_back(1);
        }
        z/=2;
    }
}
void plus_one(){
    int res=0;
    for(int i=0;i<bit.size();i++){
        if(bit[i]==1){
            res+=dua[i];
        }
    }
    res++;
    //cout<<res<<endl;
    to_bit(res);
}
int main(){
    cin>>x;
    dua[0]=1;
    for(int i=1;i<=30;i++){
        dua[i]=dua[i-1]*2;
    }
    //for(int i=0;i<bit.size();i++)cout<<bit[i];

    to_bit(x);
//    plus_one();
    //for(int i=0;i<bit.size();i++)cout<<bit[i];cout<<endl;


    if (perfect()){
    }
    else{
        for(int i=1;i<=40;i++){
            steps=i;
            if(steps%2==0){
                plus_one();
            }
            else{
                int temp;
                for(int i=0;i<bit.size();i++){
                    if(bit[i]==0){temp=i;}
                }
                ans.push_back(temp+1);
                for(int i=0;i<=temp;i++){
                    if(bit[i]==0){bit[i]=1;}
                    else{bit[i]=0;}
                }
            }

            if(perfect())break;
        }
    }

    cout<<steps<<endl;
    for(int i=0;i<ans.size();i++){
        if(i==0)cout<<ans[i];
        else{cout<<" "<<ans[i];}
    }


}
