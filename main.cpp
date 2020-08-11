#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Student.cpp"
#include "Project.cpp"
#include "Staff.cpp"

using namespace std;

vector<Student> vStudents;
vector<Project> vProjects;
vector<Staff> vStaff;

int main(int argc, char* argv[]) {

    /********READ INPUT FILES********/
    
    //Temp val to store strings
    string s;

    //Load Staff input
    ifstream inputStaff(argv[1]);

    //Temp staff
    Staff tempStaff;

    string test;

    try {
    
        
        while(getline(inputStaff, s)){

            //Temp vals
            stringstream ss(s);
            int counter = 0;

                string temp; 
                string id;
                string load;

            while(ss >> temp){

                if(counter == 0){
                    id = temp;
                }else {
                    load = temp;
                }

                counter++;
            }
            
            //Initialise student with input data
            Staff staff (id, load);             

            vStaff.push_back(staff);
        }
    }
    catch (std::ifstream::failure e) {
    std::cerr << "Exception opening file: " << "\n";
    }

    /*Load Project vector*/
    ifstream inputProject(argv[2]);

    //Temp project
    Project tempProject;
    
    try {
        
        while(getline(inputProject, s)){
             int counter = 0;

            //Temp vals
            stringstream ss(s);
            string temp; 
            string id;
            string staffId;
            string availability;
            string title;
           

            while(ss >> temp){
                switch (counter)
                {
                case 0:
                    id = temp;
                    counter++;
                    break;
                case 1:
                    staffId = temp;
                    counter++;
                    break;
                case 2:
                    availability = temp;
                    counter++;
                    break;
                case 3:
                    title = temp;
                    break;
                default:
                    break;
                }
            }

            //Initialise project with input data
            Project project (id, staffId, availability, title);             

            vProjects.push_back(project);
        }
    }
    catch (std::ifstream::failure e) {
    std::cerr << "Exception opening file: " << "\n";
    }

    //Load Student vector
    ifstream inputStudent(argv[3]);

    //Temp student
    Student tempStudent;

    try {
        
        while(getline(inputStudent, s)){

            //Temp vals
            stringstream ss(s);
            string temp; 
            string id;
            vector<string> choices;
            int counter = 0;

            while(ss >> temp){
               if(counter == 0){
                    id = temp;
                }else {
                    choices.push_back(temp);
                }
                counter++;
            }
            
            //Initialise student with input data
            Student student (id, choices, false);             

            vStudents.push_back(student);
        }
    }
    catch (std::ifstream::failure e) {
    std::cerr << "Exception opening file: " << "\n";
    }

    //close input files
    inputStudent.close();
    inputProject.close();
    inputStaff.close();

    /********ASSESS & ALLOCATE INPUT********/

    //filther through 4 choices
    for(int u=0; u<4; u++){
        //filter through students, evaluating one at a time
        for(int i=0; i<vStudents.size(); i++){
            //match projects to student choices
            for(int o=0; o<vProjects.size(); o++){

                if(vStudents[i].getChoices()[u] == vProjects[o].getId()){

                    if((!vStudents[i].isAllocated()) && vProjects[o].getAvailability() != 0 && findStaff(vStaff, vProjects[o].getStaffId()).getLoad() != 0){
                    
                    vStudents[i].setProject(vProjects[o].getId());

                    vStudents[i].setAllocation(true);

                    vStudents[i].addPoints(4 - u);
                
                    findStaff(vStaff, vProjects[o].getStaffId()).dLoad();

                    vProjects[o].dAvailability();

                    } 
                }
            }
        }
    }

    ofstream outFile;
    outFile.open("alloc.txt");
    
    /********OUTPUT RESULTS********/
    string outWrite;
    int points = 0;
    for (int i = 0; i < vStudents.size(); i++){
       if(!vStudents[i].isAllocated()){
           outWrite="";
           outWrite += vStudents[i].getId() + " " + "0" + "\n";
           outFile << outWrite;
       } else{
           outWrite="";
           outWrite += vStudents[i].getId() + " " + vStudents[i].getProject() + "\n";
           outFile << outWrite;
           points += vStudents[i].getPoints();
        }
    }
    outFile << points;
    outFile.close();
}

