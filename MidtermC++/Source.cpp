
#include <iostream>
using namespace std;

const int NC = 31;

struct Student {
    int id;
    float grade;
    char name[NC];
};

int main()
{
    const int NOS = 3; // Number of students
    Student william = { 2019, 77.6, "William" };
    Student harper = { 2020, 78.5, "Harper" };
    Student jackson = { 2021, 79.5, "Jackson" };

    // Define an array of pointers to Student objects
    Student* students[NOS] = { &william, &harper, &jackson };
    for (int i = 0; i < NOS; i++) {
        cout << "======\n";
        cout << "id: " << students[i]->id << endl;
        cout << "grade: " << students[i]->grade << endl;
        cout << "name: " << students[i]->name << endl;
    }

    return 0;
}

