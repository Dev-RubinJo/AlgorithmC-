//
//  BaekJoon10808.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/16.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int ans[26] = {0, };
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        ans[s[i] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//
//    int ans[26] = {0, };
//    string s;
//    cin >> s;
//
//    for(int i = 0; i < s.size(); i++) {
//        if(s[i] - 'a' == 0)
//            ans[0]++;
//        else if(s[i] - 'a' == 1)
//            ans[1]++;
//        else if(s[i] - 'a' == 2)
//            ans[2]++;
//        else if(s[i] - 'a' == 3)
//            ans[3]++;
//        else if(s[i] - 'a' == 4)
//            ans[4]++;
//        else if(s[i] - 'a' == 5)
//            ans[5]++;
//        else if(s[i] - 'a' == 6)
//            ans[6]++;
//        else if(s[i] - 'a' == 7)
//            ans[7]++;
//        else if(s[i] - 'a' == 8)
//            ans[8]++;
//        else if(s[i] - 'a' == 9)
//            ans[9]++;
//        else if(s[i] - 'a' == 10)
//            ans[10]++;
//        else if(s[i] - 'a' == 11)
//            ans[11]++;
//        else if(s[i] - 'a' == 12)
//            ans[12]++;
//        else if(s[i] - 'a' == 13)
//            ans[13]++;
//        else if(s[i] - 'a' == 14)
//            ans[14]++;
//        else if(s[i] - 'a' == 15)
//            ans[15]++;
//        else if(s[i] - 'a' == 16)
//            ans[16]++;
//        else if(s[i] - 'a' == 17)
//            ans[17]++;
//        else if(s[i] - 'a' == 18)
//            ans[18]++;
//        else if(s[i] - 'a' == 19)
//            ans[19]++;
//        else if(s[i] - 'a' == 20)
//            ans[20]++;
//        else if(s[i] - 'a' == 21)
//            ans[21]++;
//        else if(s[i] - 'a' == 22)
//            ans[22]++;
//        else if(s[i] - 'a' == 23)
//            ans[23]++;
//        else if(s[i] - 'a' == 24)
//            ans[24]++;
//        else if(s[i] - 'a' == 25)
//            ans[25]++;
//    }
//
//    for(int i = 0; i < 26; i++) {
//        cout << ans[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
