class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> q;
        for(int i=0;i<students.size();i++){
            q.push_back(students[i]);
        }
        int i=0;
        int k=0;
        while(q.size() && k!=q.size()){
            if(q.front()!=sandwiches[i]){
                q.push_back(q.front());
                k++;
            }
            else{
                k=0;
                i++;
            }
            q.pop_front();
        }
        return q.size();
    }
};