#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> generateKeyMatrix(string message, string key) {
    unordered_map<char, bool> m;
    vector<vector<char>> matrix(5, vector<char>(5));
    int i = 0, j = 0;

    for (auto x : key) {
        if (j >= 5) {
            j = 0;
            i++;
        }
        if (m[x] != true) {
            matrix[i][j] = x;
            m[x] = true;
        } else {
            continue;
        }
        j++;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j') {
            continue; // Skip 'J' for Playfair cipher
        }
        if (j >= 5) {
            j = 0;
            i++;
        }
        if (m[ch] != true) {
            matrix[i][j] = ch;
            m[ch] = true;
        } else {
            continue;
        }
        j++;
    }

    cout << i << " " << j << endl;
    return matrix;
}

string encryption(string message,vector<vector<char>> matrix){
    if(message.size()%2!=0){
        message+='z';
    }

    vector<pair<char,char>> pairs;
    for(int i=0;i<message.size()-1;i+=2){
        if(message[i] != message[i+1]){
            pairs.push_back({message[i],message[i+1]});
        }
        else{
            pairs.push_back({message[i],'x'});
            i-=1;
        }
    }
    unordered_map<char, pair<int, int>> m;
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            m[matrix[i][j]] = { i, j };
        }
    }

    for (int i = 0; i < pairs.size(); i++) {
        auto point1 = m[pairs[i].first];
        auto point2 = m[pairs[i].second];
        if(point1.first != point2.first && point2.second != point1.second){
            pairs[i].first = matrix[point1.first][point2.second];
            pairs[i].second = matrix[point2.first][point1.second];
            continue;
        }

        point1.first = (point1.first + 1) % matrixSize;
        point2.first = (point2.first + 1) % matrixSize;
        point1.second = (point1.second + 1) % matrixSize;
        point2.second = (point2.second + 1) % matrixSize;

        pairs[i].first = matrix[point1.first][point1.second];
        pairs[i].second = matrix[point2.first][point2.second];

    }

    string cipherText = "";
    for (auto i : pairs) {
        cipherText += i.first;
        cipherText += i.second;
    }
    return cipherText;
}

string decryption(string message,vector<vector<char>> matrix){
    
    vector<pair<char,char>> pairs;
    for(int i=0;i<message.size()-1;i+=2){
        if(message[i] != message[i+1]){
            pairs.push_back({message[i],message[i+1]});
        }
        else{
            pairs.push_back({message[i],'x'});
            i-=1;
        }
    }
    unordered_map<char, pair<int, int>> m;
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            m[matrix[i][j]] = { i, j };
        }
    }

    for (int i = 0; i < pairs.size(); i++) {
        auto point1 = m[pairs[i].first];
        auto point2 = m[pairs[i].second];

        if(point1.first != point2.first && point2.second != point1.second){
            pairs[i].first = matrix[point1.first][point2.second];
            pairs[i].second = matrix[point2.first][point1.second];
            continue;
        }

        point1.first = (point1.first - 1);
        point2.first = (point2.first - 1);
        point1.second = (point1.second - 1);
        point2.second = (point2.second - 1);

        if(point1.first < 0){
            point1.first = 4;
        }
        if(point2.first < 0){
            point2.first = 4;
        }
        if(point1.second < 0){
            point1.second = 4;
        }
        if(point2.second < 0){
            point2.second = 4;
        }

        pairs[i].first = matrix[point1.first][point1.second];
        pairs[i].second = matrix[point2.first][point2.second];

    }
}

int main(){
    string key;
    cout<<"Enter a key in form of string: ";
    cin>>key;
    string message;
    cout<<"Enter message to be encrypt: ";
    cin>>message;
    vector<vector<char>> matrix = generateKeyMatrix(message,key);
    for(auto i:matrix){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    string encryptedMessage = encryption(message,matrix)
    cout<<encryption(message,matrix)<<endl;
    cout<<decryption()
    return 0;
}