//
//  bj1213.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

// 팰린드롬
#include <iostream>
using namespace std;
int alphabet[26];
int main(){
    string name;
    string palindrome = "";
    string odd = "";
    int count = 0;

    cin >> name;

    for(int i = 0; i < name.size(); i++){
        alphabet[name[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(alphabet[i] % 2 == 1){
            for(int j = 0; j < name.size(); j++){
                odd[j] = i;
            }
            count++;
        }
    }
    if(count > 1){
        cout << "I'm Sorry Hansoo." << endl;
    }
    else{
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < alphabet[i]/2; j++){
                palindrome += i + 'A';
            }
        }
        if(name.size() % 2 == 0){
            string reverse = "";
            for(int k = 0; k < palindrome.size(); k++){
                reverse[k] = palindrome[palindrome.size()-k];
            }
            palindrome += reverse;
        }
        else{palindrome += odd;}
    }
    cout << palindrome;
}
