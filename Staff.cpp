#include "Staff.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Staff::Staff(){
    id_ = "";
    load_ = "";
    loadInt_ = -1;
}

Staff::Staff(string id, string load){
    id_ = id;
    load_ = load;
    loadInt_ = std::stoi(load_);
}

string Staff::getId() {
    return id_;
}

int Staff::getStaffLoad(string id) {
    if(id_ == id){
        return loadInt_;
    }
}

int Staff::getLoad(){
    return loadInt_;
}

void Staff::dLoad() {
    loadInt_ = loadInt_ - 1;
}

Staff& findStaff(vector<Staff>& vec, string id){
    for (int i = 0; i < vec.size(); i++)
    {
        if(id == vec[i].getId()){
            return vec[i];
        }
    }
    
}

