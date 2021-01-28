//
//  BaekJoon10825.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/24.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Student {
//private:
//    string name;
//    int korean;
//    int english;
//    int math;
//
//public:
//    Student(string name, int korean, int english, int math) {
//        this->name = name;
//        this->korean = korean;
//        this->english = english;
//        this->math = math;
//    }
//
//    bool operator < (const Student &student) const {
//
//        if(this->korean == student.korean) {
//            if(this->korean == student.korean) {
//                if(this->math == student.math)
//                    return this->name < student.name;
//                else
//                    return this->math > student.math;
//                }
//            else
//                return this->english < student.english;
//            }
//        else
//            return this->korean > student.korean;
//
// //        if(this->korean == student.korean && this->english == student.english && this->math && student.math) return this->name < student.name;
// //        else if(this->korean == student.korean && this->english == student.english) return this->math > student.math;
// //        else if(this->korean == student.korean) return this->english < student.english;
// //        return this->korean > student.korean;
//    }
//
//    string getName() {
//        return this->name;
//    }
//};
//
//int main(void) {
//
//    int n;
//    vector<Student> students;
//
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        string name;
//        int korean, english, math;
//        cin >> name >> korean >> english >> math;
//        students.push_back(Student(name, korean, english, math));
//    }
//
//    sort(students.begin(), students.end());
//
//    for(int i = 0; i < n; i++) {
//        cout << students[i].getName() << "\n";
//    }
//
//    return 0;
//}
struct Student{
    string name;
    int kor, eng, math;
};
bool cmp(Student a, Student b)
{
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
    if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
    if (a.kor == b.kor) return a.eng < b.eng;
    return a.kor > b.kor;
}
int main()
{
    int N;
    cin >> N;
    vector<Student> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) cout << v[i].name << '\n';
    return 0;
}
