#include<bits/stdc++.h>
using namespace std;
string decryption(string cipherText,string keyword){
    string temp = keyword;
    while(cipherText.size() > keyword.size()){
        keyword+=temp;
    }
    

   string plainText;
    for(int i=0;i<cipherText.size();i++){
        int step = islower(keyword[i]) ? keyword[i] - 'a' : keyword[i] - 'A';
        step = 26 - step;
        if(cipherText[i]!=' '){
            if(islower(cipherText[i])){
                int index = cipherText[i]-'a';
                char a = (index+step)%26 + 97;
                plainText+=a;
            }
            else{
                int index = cipherText[i]-'A';
                char a = (index+step)%26 + 65;
                plainText+=a;
            }
        }
        else{
            plainText+=cipherText[i];
        }
    }

    return plainText;
}
string encryption(string plainText,string keyword){
    string temp = keyword;
    while(plainText.size() > keyword.size()){
        keyword+=temp;
    }

    string cipherText;
    for(int i=0;i<plainText.size();i++){
        int step = islower(keyword[i]) ? keyword[i] - 'a' : keyword[i] - 'A';
        if(plainText[i]!=' '){
            if(islower(plainText[i])){
                int index = plainText[i]-'a';
                char a = (index+step)%26 + 97;
                cipherText+=a;
            }
            else{
                int index = plainText[i]-'A';
                char a = (index+step)%26 + 65;
                cipherText+=a;
            }
        }
        else{
            cipherText+=plainText[i];
        }
    }

    return cipherText;
}
int main(){
    string message;
    cout<<"Enter a message: ";
    cin>>message;
    string keyword;
    cout<<"Enter keyword in form of string: ";
    cin>>keyword;
    string cipherText = encryption(message,keyword);
    cout<<cipherText<<endl;
    cout<<decryption(cipherText,keyword)<<endl;
    return 0;
}