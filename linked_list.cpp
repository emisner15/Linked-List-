#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Here is a working linked list example

// the struct is made to hold data
struct node
{
    int data;
    node *nexts;
};

// class of node is made to manipulate data

class nodes
{

private:

    node *head,*tail;

public:

    nodes()
    {
        head=NULL;
        tail=NULL;
    }

    // makes a node in the list
    void make_node(int value)
    {
        // make temp node to hold the data
        node *temp = new node;
        temp -> data = value;
        temp -> nexts = NULL;
        if(head == NULL){
            // if we have no values existing in the linked list we set this node to head and tail.
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else{
            //if there are existing nodes we attach the new node to the end of the existing list as the tail.
            tail -> nexts = temp;
            tail = temp;

        }
    }

    //check values of each node
    void display(){
        node *temp = new node;
        temp = head;
        // exits while loop when temp next pointer is NULL; Indicating end of list
        while(temp != NULL){
            cout << temp -> data << " ";
            temp=temp->nexts;

        }
    }

    //adds node to the front of the list.
    void insert_front(int value){
        node *temp = new node;
        temp -> data = value;
        temp -> nexts = head;
        head =temp;
    }


    // adds node at position specified
    void insert_at_position(int position,int value){
        node *current = new node;
        node *previous = new node;
        node *temp = new node;
        current = head;

        // iterate through the list until the position is found
        for(int i=0;i<position;i++){
            previous = current;
            current = current -> nexts;
        }
        // once found we set our temp to the value inserted
        temp -> data = value;
        //set previous pointer to temps address location
        previous -> nexts = temp;
        //sets temps pointer to currents address location
        temp -> nexts = current;
    }

    // here is where node deletion starts

    // deletes head
    void remove_first(){
        // creates a temp node sets it equal to current head
        node *temp = new node;
        temp = head;
        //sets head to new head using address value
        head = head -> nexts;
        delete temp;
    }

    // delete tail
    void remove_last(){
        node *current = new node;
        node *previous = new node;

        current = head;
        // iterates though the list till it finds a NULL pointer
        while(current -> nexts != NULL){
            previous = current;
            current = current -> nexts;
        }

        //sets tail to previous node in the list
        tail = previous;
        previous -> nexts = NULL;

        delete current;
    }

    // deletes node specified
    void remove_at_position(int position){
        node *current = new node;
        node *previous = new node;
        node *temp = new node;
        current = head;
        //iterates through the list searching for position specified
        for(int i = 0; i< position;i++){
            previous =  current;
            current = current -> nexts;
        }
        // once found sets that current location to temp node
        temp = current;
        //sets current to new current's address location
        current = current -> nexts;
        // previous is now set to new current address location
        previous -> nexts = current;
        delete temp;


    }




};

int main ()
{
    // create an instance of the class
    nodes obj1;
    // add nodes to list
    obj1.make_node(0);
    obj1.make_node(1);
    obj1.make_node(2);
    obj1.make_node(3);
    obj1.make_node(4);
    obj1.insert_front(2);
    obj1.insert_at_position(2,9);

    //deletes here but using new object
    obj1.remove_first();
    obj1.remove_last();
    obj1.remove_at_position(2);

    obj1.display();

}
