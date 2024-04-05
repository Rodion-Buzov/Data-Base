#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void addPerson()
{
    string name, gender, line;
    int age;
    int check  = 0;
    char choiceTwo;

    cout << "Enter the person's name: ";
    cin >> name;

    while (true) {
        cout << "Enter the person's age: ";
        if (cin >> age) {
            break;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
        }
    }

    cout << "Enter the person's gender: ";
    cin >> gender;

    cout << "Create a bank account? [y/n]" << endl;
    cin >> choiceTwo;

    if (choiceTwo == 'y')
    {
        cout << "Enter the balance: " << endl;
        cin >> check;
    }
    else if (choiceTwo == 'n')
    {
        cout << "No account created. You balance = 0" << endl;
        check = 0;
    }
    else 
    {
        cout  << "Please only type y or n" << endl;
    }

    ofstream person("data_base.txt", ios_base::app);
    if (person.is_open()) {
        line = "Person's name: " + name + " age: " + to_string(age) + " gender: " + gender + " Your balance: " + to_string(check) + ".\n";
        person << line;
        person.close();
    } else {
        cout << "Unable to open the file for writing." << endl;
    }
}

void viewPerson()
{
    string line;
    ifstream readFile("data_base.txt");

    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open the file for reading." << endl;
    }
}

int main()
{
    char choice;

    while(true)
    {
        cout << "This program is connected to a database-people of BANK." << endl;
        cout << "Functions: " << endl;
        cout << "(A) Add new person" << endl;
        cout << "(V) View persons" << endl;
        cout << "(Q) Quit" << endl;
        cin >>  choice;

        switch (choice) {
            case 'A':
                addPerson();
                break;
            case 'V':
                viewPerson();
                break;
            default:
                cout << "Invalid input or stop program! " << endl;
                break;
        }

        if  (choice == 'Q') 
        {
            cout << "Goodbye!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}