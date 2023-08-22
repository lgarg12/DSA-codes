#include <bits/stdc++.h>
using namespace std;
string decryption(int key,vector<vector<char>> map){
    string plainText = "";
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(map[i][j]=='-'){break;}
            plainText+=map[i][j];
        }
    }
    
    return plainText;
}
string encryption(int key,string plainText){
    int row = plainText.size()/key;
    if(plainText.size()%key!=0){
        row+=1;
    }
    int col = key;
    vector<vector<char>> map(row,vector<char>(col,'-'));
    int x = 0;
    int y = 0;
    string chipherText="";
    for(int i=0;i<plainText.size();i++){
        map[y][x] = plainText[i];
        x++;
        if(x >= col){
            y++;
            x=0;
        }
    }
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<map[0].size();i++){
        for(int j=0;j<map.size();j++){
            if(map[j][i]!='-')
            chipherText+=map[j][i];
        }
    }
    cout<<decryption(key,map)<<" ";
    return chipherText; 
}
int main(){
    string plainText = "";
    cout<<"Enter plain text: ";
    cin>>plainText;
    int key;
    cout<<"Enter Key value: ";
    cin>>key;

    cout<<encryption(key,plainText)<<" ";
    return 0;
}