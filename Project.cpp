#include "Project.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Project::Project() {
    id_ = "";
    staffId_ = "";
    availability_ = "";
    availabilityInt_ = 0;
}

Project::Project(string id, string staffId, string availability, string title){
    id_ = id;
    staffId_ = staffId;
    availability_ = availability;
    availabilityInt_ = std::stoi(availability_);
    title_ = title;
}

string Project::getId() {
    return id_;
}

string Project::getTitle() {
    return title_;
}

string Project::getStaffId() {
    return staffId_;
}

int Project::getAvailability() {
    return availabilityInt_;
}

void Project::dAvailability(){
    availabilityInt_--;
}