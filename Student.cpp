#include "Student.h"
#include <vector>
#include <string>
#include <iostream>

Student::Student() {
    id_ = "";
    choices_ = {};
    allocated_ = false;
    project_ = "";
    points_ = 0;
}

Student::Student(string id, vector<string> choices, bool allocated){
    id_ = id;
    choices_ = choices;
    allocated_ = allocated;
}

void Student::setAllocation(bool allocated) {
    allocated_ = allocated;
}

bool Student::isAllocated(){
    return allocated_;
}

string Student::getId() {
    return id_;
}

void Student::addPoints(int points) {
    points_ += points;
}

int Student::getPoints(){
    return points_;
}

void Student::setProject(string project){
    project_ = project;
}

string Student::getProject(){
    return project_;
}

vector<string> Student::getChoices() {
    return choices_;
}






