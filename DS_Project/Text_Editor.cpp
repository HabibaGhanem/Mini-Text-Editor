#include "Text_Editor.h"
#include <iostream>
#include<string>
#include <regex>
#include "Text_Editor.h"
#include "LinkedList.cpp"

using namespace std;

LinkedList<string> line;


void Text_Editor::add()
{
    string input;
    cout << "Enter text line :\n";
    cin.ignore();
    getline(cin, input);
    line.Append(input);
    
}

void Text_Editor::display() {
    line.Display();
}
 
void Text_Editor::FindAll()
{
   cout << "Enter the string you want to search for :" << endl;
    string str1,str2;
    cin >> str1;
    Node<string>* node = line.head;
    bool isfound = false;
    
    for (int i = 0; i < line.Length(); i++)
    {
        str2 = node->value;
        int found = str2.find(str1);
        if (found != -1)
        {
            isfound = true;
            cout << str1 << " is found in line no. " << i + 1 <<endl;
        }
        
        node = node->next;
    }
    if (isfound == false)
    {
        cout << str1 << " not found";
    }
   
   }
void Text_Editor::FindAndReplaceAll()
{
    string str1, str2,str3;
    int index = -1;
    cout << "Enter the string you want to replace: ";
    cin >> str1;
    cout << "Replace it with: ";
    cin >> str3;
    Node<string>* node = line.head;
    bool isfound = false;
    

    for (int i = 0; i < line.Length(); i++)
    {
       str2 = node->value;
        while (true)
        {
            index = str2.find(str1);
            if (index != -1)
            {
                isfound = true;
                line.UpdateAt(i,str2.replace(index, str1.length(), str3));
            }
            else {
                break;
            }
        }

        node = node->next;
    }
    if (isfound == false)
    {
        cout << str1 << " not found";
    }

}
void Text_Editor::get_line(int position)
{
    int pos = 0;
    if (line.head == NULL)
    {
        cout << "No Data added yet in this file \n";
    }
    Node<string>* tmp = line.head;
    while (tmp != NULL)
    {
        if (position == pos + 1)
        {
            cout << "line no." << pos + 1 << ':' << endl;
            cout << tmp->value <<endl;
        }
        tmp = tmp->next;
        pos++;
    }
}
   void Text_Editor::update()
   {
       if (line.head == NULL) {
           cout << " No Data added yet in this file \n";
       }
       else{
       int line_pos;
       string input_text;
       cout << "Enter the line no. you want to modify: \n";
       cin >> line_pos;
       
           cout << "Enter text line: \n";
           cin.ignore();
           getline(cin, input_text);
           line.UpdateAt(line_pos - 1, input_text);
       }
       
   }
   
   void Text_Editor::insert()
   {
       string input_text;
       int line_pos;
       cout << "Enter line no.: ";
       cin >> line_pos;
       cin.ignore(); //make me can enter input_text
       getline(cin, input_text);
       line.InsertAt(line_pos - 1,input_text);
       

   };
    
 
void Text_Editor::delete_at(int pos) {
    line.DeleteAt(pos - 1);
}
