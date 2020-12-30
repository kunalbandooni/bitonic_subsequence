#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l[100],r[100];
    l[0]=1,r[n-1]=1;
    for(int i=1;i<n;i++){
        int x=1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                x=max(x,l[j]+1);
        }
        l[i]=x;
    }
    for(int i=n-2;i>=0;i--){
        int x=1;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])
                x=max(x,r[j]+1);
        }
        r[i]=x;
    }
    int sol=0;
    for(int i=0;i<n;i++)
        sol=max(sol,l[i]+r[i]-1);
    cout<<"Maximum Solution is:"<<sol;
    return 0;
}