#include<bits/stdc++.h>
using namespace std;
string decryption(int key,string cipherText){
    string plainText = "";
    key = 26 - key;
    for(int i=0;i<cipherText.size();i++){
        if(cipherText[i]!=' '){
            if(islower(cipherText[i])){
                int index = cipherText[i]-'a';
                char a = (index+key)%26 + 97;
                plainText+=a;
            }
            else{
                int index = cipherText[i]-'A';
                char a = (index+key)%26 + 65;
                plainText+=a;
            }
        }
    }
    return plainText;
}
string encryption(int key,string plainText){
    string cipherText = "";
    for(int i=0;i<plainText.size();i++){
        if(plainText[i]!=' '){
            if(islower(plainText[i])){
                int index = plainText[i]-'a';
                char a = (index+key)%26 + 97;
                cipherText+=a;
            }
            else{
                int index = plainText[i]-'A';
                char a = (index+key)%26 + 65;
                cipherText+=a;
            }
        }
    }
    return cipherText;
}
int main(){
    int key;
    cout<<"Enter key: ";
    cin>>key;
    string message;
    cout<<"Enter message to encrypt: ";
    cin>>message;
    string cipherText = encryption(key,message);
    string plainText = decryption(key,cipherText);
    cout<<cipherText<<endl;
    cout<<plainText<<endl;
    return 0;
}