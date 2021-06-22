//
//  2580-a.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
int Map[10][10];
vector<pair<int, int>> vc;
bool backtracking(int idx) {
    if (idx >= vc.size()) return true;
    bool check[10] = { false };
    int y = vc[idx].first, x = vc[idx].second;
    for (int i = 0; i < 9; i++) {
        check[Map[y][i]] = true;
        check[Map[i][x]] = true;
    }
    for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++)
    for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++)
    check[Map[i][j]] = true;
    
    bool ret = false;
    for (int i = 1; i <= 9; i++) {
        if (check[i])continue;
        Map[y][x] = i;
        ret = backtracking(idx + 1);
        if (ret)return ret;
        Map[y][x] = 0;
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        string s; cin >> s;
        for (int j = 0; j < 9; j++) {
            //           char c; cin >> c;
            //           int x = c - 48;
            int x = s[j] - 48;
            Map[i][j] = x;
            if (Map[i][j] == 0)
                vc.push_back(make_pair(i, j));
        }
    }
    cout << endl;
    
    backtracking(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
//            cout << Map[i][j] << " ";
            cout << Map[i][j];
        }
        cout << '\n';
    }
}
/*

 #include<bits/stdc++.h>

 using namespace std;

 //col, row, square Check
 bool usedy[10][10], usedx[10][10], square[10][10];
 int Map[10][10], totalUsed;

 //Use for 3x3 square
 inline int ptod(int y, int x) {
     return y / 3 * 3 + x / 3;
 }
 bool backtracking() {
     if(totalUsed == 81)return true;
     //x + y + square
     for(int i = 0; i < 9; i++) {
         for(int j = 0; j < 9; j++) {
             if(Map[i][j]) continue;
             int targetNumber = -1, possibleCount = 0;
             for(int number = 1; number <= 9; number++) {
                 if(!usedy[i][number] && !usedx[j][number] && !square[ptod(i, j)][number]) {
                     targetNumber = number;
                     if(++possibleCount >= 2) break;
                 }
             }
             if(possibleCount == 0) return false;
             if(possibleCount  > 1) continue;
             Map[i][j] = targetNumber;
             usedy[i][targetNumber] = usedx[j][targetNumber] = square[ptod(i, j)][targetNumber] = true;
             totalUsed++;
             if(backtracking()) return true;
             Map[i][j] = 0;
             usedy[i][targetNumber] = usedx[j][targetNumber] = square[ptod(i, j)][targetNumber] = false;
             totalUsed--;
             return false;
         }
     }
     
     //square
     for(int k = 0; k < 9; k++) { //3x3 => 9 squares
         for(int number = 1; number <= 9; number++) {
             if(square[k][number]) continue;
             int nxtposy = -1, nxtposx = -1, possibleCount = 0;
             //auto [squarey, squarex] = convert(k); //position of 3x3
             for(int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
                 for(int j = k % 3 * 3; j < k % 3 * 3 + 3; j++) {
                     if(Map[i][j] == 0 && !usedy[i][number] && !usedx[j][number]) {
                         nxtposy = i;
                         nxtposx = j;
                         if(++possibleCount >= 2) break;
                     }
                 }
             }
             if(possibleCount == 0) return false;
             if(possibleCount >  1) continue; //we only see about possibleCount == 1
             Map[nxtposy][nxtposx] = number;
             totalUsed++;
             usedy[nxtposy][number] = usedx[nxtposx][number] = square[k][number] = true;
             if(backtracking()) return true;
             Map[nxtposy][nxtposx] = 0;
             totalUsed--;
             usedy[nxtposy][number] = usedx[nxtposx][number] = square[k][number] = false;
             return false;
         }
     }
     
     //y
     for(int i = 0; i < 9; i++) {
         for(int number = 1;number <= 9; number++) {
             if(usedy[i][number]) continue;
             int nxtpos = -1, possibleCount = 0;
             for(int j = 0; j < 9; j++) {
                 if(Map[i][j] == 0 && !usedx[j][number] && !square[ptod(i, j)][number]) {
                     nxtpos = j;
                     if(++possibleCount >= 2) break;
                 }
             }
             if(possibleCount == 0) return false;
             if(possibleCount >  1) continue; //we only see about possibleCount == 1
             Map[i][nxtpos] = number;
             totalUsed++;
             usedy[i][number] = usedx[nxtpos][number] = square[ptod(i, nxtpos)][number] = true;
             if(backtracking()) return true;
             Map[i][nxtpos] = 0;
             totalUsed--;
             usedy[i][number] = usedx[nxtpos][number] = square[ptod(i, nxtpos)][number] = false;
             return false;
         }
     }

     //x
     for(int i = 0; i < 9; i++) {
         for(int number = 1; number <= 9; number++) {
             if(usedx[i][number]) continue;
             int nxtpos = -1, possibleCount = 0;
             for(int j = 0; j < 9; j++) {
                 if(Map[j][i] == 0 && !usedy[j][number] && !square[ptod(j, i)][number]) {
                     nxtpos = j;
                     if(++possibleCount >= 2) break;
                 }
             }
             if(possibleCount == 0) return false;
             if(possibleCount >  1) continue;
             Map[nxtpos][i] = number;
             totalUsed++;
             usedy[nxtpos][number] = usedx[i][number] = square[ptod(nxtpos, i)][number] = true;
             if(backtracking()) return true;
             Map[nxtpos][i] = 0;
             totalUsed--;
             usedy[nxtpos][number] = usedx[i][number] = square[ptod(nxtpos, i)][number] = false;
             return false;
         }
     }

     //other
     for(int i = 0; i < 9; i++) {
         for(int j = 0; j < 9; j++) {
             if(Map[i][j]) continue;
             for(int number = 1; number <= 9; number++) {
                 if(!usedy[i][number] && !usedx[j][number] && !square[ptod(i, j)][number]) {
                     Map[i][j] = number;
                     usedy[i][number] = usedx[j][number] = square[ptod(i, j)][number] = true;
                     totalUsed++;
                     if(backtracking()) return true;
                     Map[i][j] = 0;
                     usedy[i][number] = usedx[j][number] = square[ptod(i, j)][number] = false;
                     totalUsed--;
                 }
             }
             return false;
         }
     }
     return false;
 }

 int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
             char c; cin >> c;
             int x = c - '0';
             Map[i][j] = x;
             if(x){
                 totalUsed++;
                 usedy[i][Map[i][j]] = usedx[j][Map[i][j]] = square[ptod(i, j)][Map[i][j]] = true;
             }
         }
     }

     backtracking();
     for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
             cout << Map[i][j] << " ";
         }
         cout << '\n';
     }
 }
 */
