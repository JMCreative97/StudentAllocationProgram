#include <iostream>
#include <vector>
using std::ostream;
using std::cout;
using namespace std;

class Project {
    public:

    Project();

    Project(string id, string staffId, string availability, string title);

    string getId();

    string getTitle();

    string getStaffId();

    int getAvailability();

    void dAvailability();

    private:
    string id_;
    string staffId_;
    string availability_;
    int availabilityInt_;
    string title_;

};