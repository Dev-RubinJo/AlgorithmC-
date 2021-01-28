//
//  BaekJoon2941.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/19.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int ans = 0;
    string croatia;
    cin >> croatia;
    
    for(int i = 0; i < croatia.size(); i++) {
        if(croatia[i] == 'c') {
            if(croatia[i + 1] == '=' || croatia[i + 1] == '-') {
                i += 1;
            }
        } else if(croatia[i] == 'd') {
                if(croatia[i + 1] == 'z') {
                    if(croatia[i + 2] == '=') {
                        i += 2;
                    }
                } else if(croatia[i + 1] == '-') {
                    i += 1;
                }
        } else if(croatia[i] == 'l') {
            if(croatia[i + 1] == 'j') {
                i += 1;
            }
        } else if(croatia[i] == 'n') {
            if(croatia[i + 1] == 'j') {
                i += 1;
            }
        } else if(croatia[i] == 's') {
            if(croatia[i + 1] == '=') {
                i += 1;
            }
        } else if(croatia[i] == 'z') {
            if(croatia[i + 1] == '=') {
                i += 1;
            }
        }
        ans += 1;
    }
    cout << ans << endl;
    
    return 0;
}
