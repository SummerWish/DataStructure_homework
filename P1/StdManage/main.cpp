//
//  main.cpp
//  P1
//
//  Created by Breezewish on 9/19/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

const int GENDER_MALE = 0;
const int GENDER_FEMALE = 1;
const int GENDER_OTHER = 2;

const int ACTION_QUIT = 0;
const int ACTION_INSERT = 1;
const int ACTION_DELETE = 2;
const int ACTION_QUERY = 3;
const int ACTION_UPDATE = 4;
const int ACTION_PRINT = 5;

class Student
{
public:
    int id;
    string name;
    int gender;
    int age;
    string type;
};

list<Student> records;

void printRecord(Student std)
{
    cout << setw(10) << std.id;
    cout << setw(10) << std.name;
    cout << setw(10);
    if (std.gender == GENDER_MALE) {
        cout << "male";
    } else if (std.gender == GENDER_FEMALE) {
        cout << "female";
    } else {
        cout << "other";
    }
    cout << setw(10) << std.age;
    cout << setw(10) << std.type;
    cout << endl;
}

void printRecords()
{
    cout << left;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Gender" << setw(10) << "Age" << setw(10) << "Type" << endl;
    for (list<Student>::iterator it = records.begin(); it != records.end(); ++it) {
        printRecord(*it);
    }
}

int main(int argc, const char * argv[])
{
    cout << "Welcome to Student Management System!" << endl;
    cout << "Please enter the number of students" << endl;
    cout << ">> ";
    int studentCount;
    cin >> studentCount;
    
    // input initial data
    cout << "Please enter [ID Name Gender Age Type]" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << ">> ";
        int id; string name; string gender; int age; string type;
        cin >> id >> name >> gender >> age >> type;
        Student std;
        std.id = id;
        std.age = age;
        std.name = name;
        if (gender.size() == 0) {
            std.gender = GENDER_OTHER;
        } else if (gender == "男" || gender[0] == 'm' || gender[0] == 'M') {
            std.gender = GENDER_MALE;
        } else if (gender == "女" || gender[0] == 'f' || gender[0] == 'F') {
            std.gender = GENDER_FEMALE;
        } else {
            std.gender = GENDER_OTHER;
        }
        std.age = age;
        std.type = type;
        records.push_back(std);
    }
    
    printRecords();
    
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "Please select an action: 1 for insert, 2 for delete, 3 for query, 4 for update, 5 for stat, 0 for cancel" << endl;
        cout << ">> ";
        int action; cin >> action;
        switch (action) {
            case ACTION_QUIT:
                cout << "bye!" << endl;
                exitLoop = true;
                break;
            case ACTION_PRINT:
                printRecords();
                break;
            case ACTION_INSERT:
            {
                cout << "Please input the place to insert" << endl;
                cout << "0: insert at head, -1: insert at tail, N: insert after the Nth record" << endl;
                cout << ">> ";
                int n; cin >> n;
                if (n < -1 || n > (int)records.size()) {
                    cout << "Invalid position!" << endl;
                    break;
                }
                
                // get content
                cout << "Please enter ID Name Gender Age Type" << endl;
                cout << ">> ";
                int id; string name; string gender; int age; string type;
                cin >> id >> name >> gender >> age >> type;
                Student std;
                std.id = id;
                std.age = age;
                std.name = name;
                if (gender.size() == 0) {
                    std.gender = GENDER_OTHER;
                } else if (gender == "男" || gender[0] == 'm' || gender[0] == 'M') {
                    std.gender = GENDER_MALE;
                } else if (gender == "女" || gender[0] == 'f' || gender[0] == 'F') {
                    std.gender = GENDER_FEMALE;
                } else {
                    std.gender = GENDER_OTHER;
                }
                std.age = age;
                std.type = type;
                
                // calculate insert position
                if (n == -1) {
                    n = (int)records.size();
                }
                list<Student>::iterator it = records.begin();
                for (int i = 0; i < n; ++i, ++it);
                
                records.insert(it, std);
                
                // print again
                cout << endl;
                printRecords();
                
                break;
            }
            case ACTION_DELETE:
            {
                cout << "Delete: Please input ID" << endl;
                cout << ">> "; int id; cin >> id;
                
                bool ok = false;
                for (list<Student>::iterator it = records.begin(); it != records.end(); ++it) {
                    if (it->id == id) {
                        ok = true;
                        cout << "Deleted: ";
                        printRecord(*it);
                        records.erase(it);
                    }
                }
                
                if (ok) {
                    cout << endl;
                    printRecords();
                } else {
                    cout << "Warning: ID not found!" << endl;
                }
                
                break;
            }
            case ACTION_QUERY:
            {
                cout << "Query: Please input ID" << endl;
                cout << ">> "; int id; cin >> id;
                
                bool ok = false;
                for (list<Student>::iterator it = records.begin(); it != records.end(); ++it) {
                    if (it->id == id) {
                        ok = true;
                        cout << "Found: ";
                        printRecord(*it);
                    }
                }
                
                if (!ok) {
                    cout << "Warning: ID not found!" << endl;
                }
                
                break;
            }
            case ACTION_UPDATE:
            {
                cout << "Update: Please input ID" << endl;
                cout << ">> "; int id; cin >> id;
                
                bool ok = false;
                for (list<Student>::iterator it = records.begin(); it != records.end(); ++it) {
                    if (it->id == id) {
                        ok = true;
                        cout << "Found: ";
                        printRecord(*it);
                        
                        // ask the user to input new data
                        cout << "Please enter ID Name Gender Age Type" << endl;
                        cout << ">> ";

                        int id; string name; string gender; int age; string type;
                        cin >> id >> name >> gender >> age >> type;
                        it->id = id;
                        it->age = age;
                        it->name = name;
                        if (gender == "男" || gender == "male") {
                            it->gender = GENDER_MALE;
                        } else if (gender == "女" || gender == "female") {
                            it->gender = GENDER_FEMALE;
                        } else {
                            it->gender = GENDER_OTHER;
                        }
                        it->age = age;
                        it->type = type;
                        
                        // done!
                        cout << "Update successfully.";
                    }
                }
                
                if (ok) {
                    cout << endl;
                    printRecords();
                } else {
                    cout << "Warning: ID not found!" << endl;
                }
                
                break;
            }
        }
    }
    
    return 0;
}

