#include<bits/stdc++.h>
using namespace std;
string encryption(vector<vector<int>> key,string plainText){
    vector<int> arr; 
    for(int i=0;i<plainText.size();i++){
        int a = islower(plainText[i]) ? plainText[i] - 'a' : plainText[i] - 'A';
        arr.push_back(a);
    }
    int x = 0;
    int y = 0;
    while(x < arr.size()){
        for(int i=0;i<key.size();i++){
            int a = 0;
            for(int j=0;j<key[0].size();j++){
                a+=(key[i][j]*arr[x])%26;
                x++;
            }
            arr[y] = a;
            y++;
        }
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
    return "";
}
int main(){
    // Implement 2*2 matrix key
    // let key matrix 2*2
    vector<vector<int>> key;
    key.push_back({6,24});
    key.push_back({13,16});
    
    string message;
    cout<<"Enter message: ";
    cin>>message;
      
    int cnt = message.size()%key.size();

    for(int i=0;i<cnt;i++){
        message+='a';
    }
    cout<<encryption(key,message);
    return 0;
}