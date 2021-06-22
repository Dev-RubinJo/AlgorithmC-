#include <string>
#include <vector>

using namespace std;

vector<int> solution(int endingTime, vector<vector<int>> jobs) {
    vector<int> answer;
    if(jobs.empty()) {
        return answer;
    }
    int start = jobs[0][1];
    for(vector<int> job: jobs) {
        if(start < job[1]) {
            start = job[1];
        }
        if((start + job[3]) <= job[2] && (start + job[3]) < endingTime) {
            start = start + job[3];
            answer.push_back(job[0]);
        } else if(job[2] >= start) {
            start = start + job[3];
        }
    }
    return answer;
}