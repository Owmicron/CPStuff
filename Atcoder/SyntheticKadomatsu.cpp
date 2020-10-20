#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,A,B,C,l[10],mn,deep[10],val[10];
int mini (int one,int two, int three){
    int cost = 0;
    cost = (one-1)*10 + (two-1)*10 + (three-1)*10;
    int sum;

    sum = 0;
    for(int i=1;i<=one;i++){
        sum+=val[i];
    }
    cost += abs(sum-A);

    sum=0;
    for(int i=one+1;i<=one+two;i++){
        sum+=val[i];
    }
    cost += abs(sum-B);

    sum=0;
    for(int i=one+two+1;i<=one+two+three;i++){
        sum+=val[i];
    }
    cost += abs(sum-C);

    return cost;
}
void C3 (int lim){
    //cout<<"Combi\n";
    for(int i=1;i<lim;i++){
        for(int j=1;j<lim;j++){
            int c = (lim-i-j);
            if(c>0){
                //cout<<i<<" "<<j<<" "<<c<<endl;
                //cout<<mini(i,j,c)<<endl;
                mn = min(mn,mini(i,j,c));
            }
        }
    }
    //cout<<endl;
}
void permute (int lim){
    int arr[10];
    for(int i=1;i<=lim;i++)arr[i]=i;

    for(int i=1;i<=lim;i++){
        val[i] = l[deep[arr[i]]];
        //cout<<val[i]<<" ";
    }
    C3(lim);
    //cout<<endl;
    while(next_permutation(arr+1,arr+1+lim)){
        for(int i=1;i<=lim;i++){
            //cout<<deep[arr[i]]<<" ";
            val [i] = l[deep[arr[i]]];
            //cout<<val[i]<<" ";
        }//cout<<endl;
        C3(lim);
        //cout<<endl;
    }
}
void choose (int x, int lim){
    int start;
    if(x==1)start = 1;
    else{start = deep[x-1] + 1;}

    int fin = n - lim + x;
    for(int i=start;i<=fin;i++){
        deep[x] = i;
        if(x<lim){choose(x+1,lim);}
        else {
//            cout<<"Permutation\n";
//            for(int j=1;j<=lim;j++){
//                cout<<deep[j]<<" ";
//            }cout<<endl;
            permute(lim);
        }
    }
}
int main(){


    cin>>n>>A>>B>>C;
    for(int i=1;i<=n;i++)cin>>l[i];
    mn = 100000000;

    for(int i=3;i<=n;i++){
        choose(1,i);
    }
    cout<<mn<<endl;
}
