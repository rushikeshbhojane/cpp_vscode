#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <iterator>
#include <algorithm>
using namespace std;
struct professor {
    string title, firstName, lastName, department ,homeAddress, homePhone, workPhone, campusBox;

    professor(string _title,
                    string _firstName,
                    string _lastName,
                    string _department,
                    string _homeAddress,
                    string _homePhone,
                    string _workPhone,
                    string _campusBox) {

        title = _title;
        firstName = _firstName;
        lastName = _lastName;
        department = _department;
        homeAddress = _homeAddress;
        homePhone = _homePhone;
        workPhone = _workPhone;
        campusBox = _campusBox;    
    }
};

bool professorSort(professor* p1, professor* p2) {
    if (strcmp(p1 -> lastName.c_str(), p2 -> lastName.c_str()) < 0) {
        return true;
    }
    return false;
}

int main()
{
    string line;
    getline(cin, line);
    int departments;
    sscanf(line.c_str(), "%d", &departments);
    vector<professor*> profs;
    for (int i = 0; i < departments; i++)
    {
        string departmentName;
        getline(cin, departmentName);

        while (getline(cin, line))
        {
            if (line == "")
            {
                break;
            }
            
            char lineCstr[line.length() + 1];
            strcpy(lineCstr,line.c_str()); 
            vector<string> details;
            char *token = strtok(lineCstr, ",");
            while (token != NULL)
            {
                /* code */
                details.push_back(token);
                token = strtok(NULL, ",");
            }
            professor* p = new professor(details[0],
                                            details[1],
                                            details[2],
                                            departmentName,
                                            details[3],
                                            details[4],
                                            details[5],
                                            details[6]);
            
            profs.push_back(p);
        }
        

    }

    sort(profs.begin(),  profs.end(), professorSort);

    for (professor* p: profs)
    {
        printf("----------------------------------------\n");
        printf("%s %s %s\n", p -> title.c_str(), p -> firstName.c_str(), p -> lastName.c_str());
        printf("%s\n", p -> homeAddress.c_str());
        printf("Department: %s\n", p -> department.c_str());
        printf("Home Phone: %s\n", p -> homePhone.c_str());
        printf("Work Phone: %s\n", p -> workPhone.c_str());
        printf("Campus Box: %s\n", p -> campusBox.c_str());
    }
    

    return 0;
}