#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
    }
    if(is_sorted(a.begin(),a.end())){
        cout<<"YES"<<endl;
    }
    else if(k==1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    }
    return 0;
}