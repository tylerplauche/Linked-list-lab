#include <iostream>
#include <string>
#include <cctype>

#include "Linked_List.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif



/*
class Interface
{
public:
    Interface(){}
    virtual ~Interface(){}
    virtual void myMethod() = 0;  // pure virtual method
};

class MyClass : public Interface
{
private:
    int myMember;
public:
    MyClass(){}
    ~MyClass(){}
    virtual void myMethod()
    {
        // myMethod implementation
    };
};*/



int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    LinkedList<string> linked_list;
    LinkedList<string> copyList;
    //bool isEqual = linked_list = copyList;

    //Interface* myClass = new MyClass();
   // myClass->myMethod();

    for (string line; getline(in, line);)
    {
        string item1, item2;
        if (line.size() == 0) continue;
        if(isspace(line.back()))
        {
            line.pop_back();
        }
        out << line;
        istringstream iss(line);
        iss >> item1;
        try {
            if (item1 == "Insert") {
                while (iss >> item2) {
                    linked_list.push_front(item2);
                }
                out << endl;
            }
            if (item1 == "PrintList") {
                if (linked_list.size() == 0) {
                    out << " Empty!" << endl;
                } else {
                    out << " " << linked_list << endl;
                }
            }
            if (item1 == "Clear") {
                linked_list.clear();
                out << " OK" << endl;
            }
            if (item1 == "First") {
                out << " " << linked_list.front() << endl;
            }
            if (item1 == "Size") {
                out << " " << linked_list.size() << endl;
            }
            if (item1 == "Delete")
            {
                linked_list.pop_front();
                out << " OK" << endl;
            }
            if (item1 == "Remove")
            {
                iss >> item2;
                linked_list.remove(item2);
                out << endl;

            }
            if (item1 == "Empty")
            {
                if (linked_list.empty() == true)
                {
                    out << " true" << endl;
                }
                else if(linked_list.empty() == false)
                {
                    out << " false" << endl;
                }
            }
            if (item1 == "Reverse")
            {
                linked_list.reverse();
                out << " OK" << endl;
            }
            if (item1 == "Copy")
            {
                LinkedList<string> copyList1(linked_list);
                copyList.clear();
                copyList = copyList1;
                out << " OK" << endl;
                copyList1.clear();
            }
            if (item1 == "PrintCopy")
            {
                if(copyList.size() == 0)
                {
                    out << " Empty!" << endl;
                }
                else{
                    out << " " << copyList << endl;
                }
            }


        }

        catch (const string &s) { out << s << endl; }

    }

    return 0;
}
