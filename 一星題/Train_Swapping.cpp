#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    cin>>n;
    while (n--)
    {
        cin>>n1;
        int num[n1];
        for(int i=0;i<n1;i++){
            cin>>num[i];
        }
        int count=0;
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<n1;j++){
                if(num[i]>num[j]){
                    int temp=num[i];
                    num[i]=num[j];
                    num[j]=temp;
                    count++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }
    
    return 0;
}