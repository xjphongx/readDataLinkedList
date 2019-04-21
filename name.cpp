#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

struct node {
    string name;
    int age;
    node*next = nullptr;

};

class list
{
    private:
        node * head;
        node*tail;
    public:
        list()
        {
            head = nullptr;
            tail = nullptr;
        }
        void addEnd(string n, int a)
        {
            node*temp = new node;
            temp->name = n;
            temp->age=a;
           if(head == nullptr)
           {
               head = temp;
               tail = temp;
               temp = nullptr;
            }
            else
            {
                tail->next= temp; //i want temp to point to whatever tail is ptring to
                tail = temp; //set tail to be the temp node for next time
            }
        
         }
         void display()
         {
            node * cursor = new node;
            cursor = head; //starting point
            while (cursor != nullptr)
            {
                cout<< cursor->name << " " << cursor->age << endl;
                cursor = cursor->next;//goes to the next ptr
            }


         }




};


void readData(list & l);


int main()
{


    cout<< "hi"<<endl;
    list LinkedList;

    readData(LinkedList);
    LinkedList.display();


    return 0;
}

void readData(list & LinkedList)
{//reads from a txt file
    ifstream inputFile;
    inputFile.open("pro5.txt");
    //int counter = 0;
    //string nameArray[counter];
    //int ageArray[counter];//the purpose of this is to set both array index to match each other
    string name;
    int age;
    
    while(!inputFile.eof())
    {
        inputFile >> name;
        inputFile >> age;
        LinkedList.addEnd(name, age);

    }



    inputFile.close();
}