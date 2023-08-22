#include<bits/stdc++.h>
using namespace std;
unordered_map<char, char> generateMappingTable1() {
    unordered_map<char, char> mappingTable;
    string sourceChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string targetChars = "xM8kABGwT6pqSZJcd9frDVL0NEm2zOHYRQa5jbKFuU3o74iegnh1WtXlvsICP";

    for (int i = 0; i < sourceChars.size(); ++i) {
        mappingTable[sourceChars[i]] = targetChars[i];
    }

    return mappingTable;
}
unordered_map<char, char> generateMappingTable2() {
    unordered_map<char, char> mappingTable;
    string sourceChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string targetChars = "xM8kABGwT6pqSZJcd9frDVL0NEm2zOHYRQa5jbKFuU3o74iegnh1WtXlvsICP";

    for (int i = 0; i < sourceChars.size(); ++i) {
        mappingTable[targetChars[i]] = sourceChars[i];
    }

    return mappingTable;
}
string encryption(string Text){
    string changeText;
    unordered_map<char,char> map = generateMappingTable1();
    for(int i=0;i<Text.size();i++){
        changeText+=map[Text[i]];
    }
    return changeText;
}
string decryption(string Text){
    string changeText;
    unordered_map<char,char> map = generateMappingTable2();
    for(int i=0;i<Text.size();i++){
        changeText+=map[Text[i]];
    }
    return changeText;
}
int main(){
    string message;
    cout<<"Enter message: ";
    cin>>message;
    string cipherText = encryption(message);
    string plainText = decryption(cipherText);
    cout<<cipherText<<endl;
    cout<<plainText<<endl;
    return 0;
}