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
        void addFront(string n, int a)
        {
            node * temp = new node;
            temp->age = a;
            temp->name = n;
            temp -> next = head;
            temp = head;
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
        void deleteFront()
        {
            node * temp = new node;
            temp = head; // head will not point to the next node but 
                        //will point to temp instead
            head= head->next; // makes next node the head
            delete temp;
        }
        void deleteEnd()
        {//need two node ptrs
            node* current = new node;
            node* prev = new node;
            current = head;
            while(current->next != nullptr)
            {
                prev = current;
                current = current->next;
            }
            //make the tail point to what prev points to
            tail = prev;//this becomes the new tail
            prev->next = nullptr; //does not point to tail
            delete current;
            
        }




         void display()
         {
            node * cursor = new node;
            cursor = head; //starting point
            cout<<"\tName\tAge"<<endl;
            cout <<"--------------------"<<endl;
            while (cursor != nullptr)
            {
                cout<< cursor->name << "\t" << cursor->age << endl;
                cursor = cursor->next;//goes to the next ptr
            }
         }
        void findOldest()
        {//traverse the list with a cursor
            node * cursor = new node;
            cursor = head;
            int oldestAge=0;
            string nameOfOldest;
            while (cursor != nullptr)
            {

                if(cursor->age > oldestAge)
                {
                    oldestAge = cursor->age;
                    nameOfOldest = cursor->name;
                
                }
                cursor = cursor->next;//moves to the next ptr

            }
            cout << "The oldest person is "<< nameOfOldest <<endl;

        }
         




};

//***********************
void readData(list & l);
int main()
{

    list LinkedList;

    readData(LinkedList);
    LinkedList.display();
    LinkedList.findOldest();

    LinkedList.deleteFront();
    LinkedList.deleteFront();
    LinkedList.display();
    LinkedList.findOldest();

    LinkedList.deleteEnd();
    LinkedList.display();
    LinkedList.findOldest();

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