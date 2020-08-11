#include <iostream>
#include <vector>
using std::ostream;
using std::cout;
using namespace std;

class Staff {
    
    public:

    Staff();

    Staff(string id, string load);

    string getId();

    int getLoad();

    void dLoad();

    int getStaffLoad(string id);

    Staff& findStudent(vector<Staff>& vec, string id);

    private:
    string id_;
    string load_;
    int loadInt_;

};