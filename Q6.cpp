#include<bits/stdc++.h>
using namespace std;
string encryption(vector<vector<int>> key,string plainText){
    vector<int> arr; 
    for(int i=0;i<plainText.size();i++){
        int a = islower(plainText[i]) ? plainText[i] - 'a' : plainText[i] - 'A';
        arr.push_back(a);
    }
    int x = 0;
    vector<int> Newarr;
    while(x < arr.size()){
        int a = 0;
        for(int i=0;i<key.size();i++){
            a = key[i][0]*arr[x]%26 + key[i][1]*arr[x+1]%26;
            Newarr.push_back(a);
        }
        x+=2;
    }
    string cipherText = "";
    for(auto i:Newarr){
        char a = i + 97;
        cipherText+=a;
    }
    return cipherText;
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