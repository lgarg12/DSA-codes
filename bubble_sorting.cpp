#include <iostream>
using namespace std;
int* sorting(int* arr,int n){
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(*(arr+j)>*(arr+j+1)){
                int temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
                flag=false;
            }
        }
        if(flag==true) break;
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter number of element to be inserted: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter data: ";
        cin>>arr[i];
    }
    int* arr1= sorting(arr,n);
    for(int i=0;i<n;i++){
        cout<<*(arr1+i)<<" ";
    }
    return 0;
}