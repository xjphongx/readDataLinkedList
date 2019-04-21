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
    
    list()
    {
        head = nullptr;
        tail = nullptr;
    }




};


void readData();


int main()
{


cout<< "hi"<<endl;



    return 0;
}
void readData()
{//reads from a txt file
    ifstream inputFile;
    inputFile.open("pro5.txt");
    int counter = 0;
    while(!inputFile.eof())
    {
        counter++;
    }

    string array[counter];

    



}