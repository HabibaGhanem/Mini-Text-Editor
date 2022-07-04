// DS_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.cpp"
#include "Text_Editor.h"

using namespace std;

int main()
{
	Text_Editor text;


    int choice;
    bool ans = false;
    do {
        cout << "\n\t\t\t\t\tMini Text Editor" << endl;
        cout << "\t\t\t\t\t--------------------" << endl << endl;
        cout << "\t\t\t\t\t1- Add line" << endl;
        cout << "\t\t\t\t\t2- Insert line" << endl;
        cout << "\t\t\t\t\t3- Get line text" << endl;
        cout << "\t\t\t\t\t4- Delete line" << endl;
        cout << "\t\t\t\t\t5- Update line" << endl;
        cout << "\t\t\t\t\t6- Find all" << endl;
        cout << "\t\t\t\t\t7- Find and Replace all" << endl;
        cout << "\t\t\t\t\t8- Show" << endl;
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            text.add();
            break;
        }
        case 2:
        {
            text.insert();
            break;
        }
        case 3:
        {
            int position;
            cout << "Enter the line no. : ";
            cin >> position;
            text.get_line(position);
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter the line no. : ";
            cin >> position;
            text.delete_at(position);
            break;
        }
        case 5:
        {
            text.update();
            break;
        }
        case 6:
        {
            text.FindAll();
            break;
        }
        case 7:
        {
            text.FindAndReplaceAll();
            break;
        }
        case 8:
        {
            text.display();
            break;
        }
        default:
            cout << "Invalid choice..";
        }
        
        cout << "Do you want to do another process?(Y/N) ";
        string again;
        cin >> again;
        if (again=="N" || again=="n") {
            ans = false;
        }
        else if (again == "Y" || again == "y") {
            ans = true;
        }
        
    } while (ans == true);
        
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file