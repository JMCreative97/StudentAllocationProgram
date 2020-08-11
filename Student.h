#include <iostream>
#include <vector>
#include <string>
using std::ostream;
using std::cout;
using namespace std;

class Student {
    public:

    Student();

    Student(string studentNo, vector<string> choices, bool allocated);

    string getId();

    vector<string> getChoices();

    bool isAllocated();

    void setAllocation(bool allocated);

    void addPoints(int points);

    int getPoints();

    void setProject(string project);

    string getProject();
    

    private:
    string id_;
    vector<string> choices_;
    bool allocated_;
    int points_;
    string project_;
    
};

