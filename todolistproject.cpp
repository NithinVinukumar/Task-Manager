#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>


using namespace std;
typedef struct todo {
    string description;
    bool completed;
    string catog;
    struct todo* next;
};

//Add
void add(todo*& head, string description,string cato) {
    todo* newitem = new todo;
    newitem->description = description;
    newitem->completed = false;
    newitem->catog=cato;
    newitem->next = head;
    head = newitem;
    cout << "Added \"" << description << "\" to the list." << endl;
}

//Mark as complete
void complete(todo* head, string description) {
    todo* currentitem = head;
    while (currentitem != NULL) {
        if (currentitem->description == description) {
            currentitem->completed = true;
            cout << "Marked \"" << description << "\" as completed." << endl;
            return;
        }
        currentitem = currentitem->next;
    }
    cout << "Could not find \"" << description << "\" in the list." << endl;
}

//Remove
void remove(todo*& head, string description) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    if (head->description == description) {
        todo* itemtorem = head;
        head = head->next;
        delete itemtorem;
        cout << "Removed \"" << description << "\" from the list." << endl;
        return;
    }
    todo* currentitem = head;
    while (currentitem->next != NULL) {
        if (currentitem->next->description == description) {
            todo* itemtorem = currentitem->next;
            currentitem->next = currentitem->next->next;
            delete itemtorem;
            cout << "Removed \"" << description << "\" from the list." << endl;
            return;
        }
        currentitem = currentitem->next;
    }
    cout << "Could not find \"" << description << "\" in the list." << endl;
}

//Print
void print(todo* head)
{
    if (head == NULL)
        {
        cout << "The list is empty." << endl;
    }
    else
        {
        cout << "Todo List:" << endl;
        todo* currentitem = head;
        int i=0;
        while (currentitem != NULL)
            {
            cout << i;
            if (currentitem->completed)
            {
                cout << "[x] ";
            } else
            {
                cout << "[ ] ";
            }
             i=i+1;
            cout << currentitem->description <<"     "<<currentitem->catog<< endl;
            currentitem = currentitem->next;
        }
    }
}

//Search
void dessearch(todo* head, string description) {
    todo* currentitem = head;
    while (currentitem != NULL) {
        if (currentitem->description == description) {
            cout << description << " is a todo task." << endl;
            return;
        }
        currentitem = currentitem->next;
    }
    cout << description << " is not found in the list." << endl;
}

//Clear
void clear(todo*& head) {
    todo* currentitem = head;
    while (currentitem != NULL) {
        todo* temp = currentitem;
        currentitem = currentitem->next;
        delete temp;
    }
    head = NULL;
    cout << "All items cleared from the list." << endl;
}

//categorizing
void categorize(todo *&head,string division[10])
{
    todo *temp=new todo;
    temp=head;
    int i=0;
    string tempca;
    cout<<"Enter the category to search: ";
    cin>>tempca;
    while(i<10)
    {
        if(division[i]==tempca)
        {
            cout<<temp->completed<<"  "<<temp->description<<"     "<<temp->catog<<endl;
        }
        else
            temp=temp->next;
        i=i+1;
    }

}

void deadline()
{
   int hrs;
   cout<<"Enter the hours for the deadline: ";
   cin>>hrs;
   time_t now = time(nullptr);
   struct tm* timein;
   timein = localtime(&now);
   cout << "The current time is: " << ctime(&now);
   cout<<endl<<"hrs: "<<timein->tm_hour;
   if(hrs==timein->tm_hour)
    cout<<"ALERT ALERT!! DEADLINE REACHED"<<endl;
}

int main()
   {
    todo* head = NULL;
    int choice;
    string description,catog;
    int i=0;
    string division[10];
    while (true)
        {
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << setfill(' ') << setw(50) << "TASK MANAGER" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << setfill(' ') << setw(46) << "MENU" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "      1. Add what you want to do (ADD)" << endl;
        cout << "      2. Exhausted to do work today? no problem remove by giving option 2!!(COMPLETED)" << endl;
        cout << "      3. Hurray!! You have completed? Kill the to do list by giving option 3(REMOVE)" << endl;
        cout << "      4. Starting to make the list small? I know what work you have to do!(PRINT)" << endl;
        cout << "      5. Want to check your task?(search)" << endl;
        cout << "      6. Completed all the tasks?? Phenomenal! select this option and have a tea!(clear all)" <<endl;
        cout << "      7. Deadline alert" <<endl;
        cout << "      8. Ease your task by categorizing" <<endl;
        cout << "      9. Sad to see you go(EXIT)" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout<<"Ready to rock and roll?"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        if (choice == 1)
        {
               cout << "Enter a description: ";
               cin.ignore();
               getline(cin, description);
               cout<<"Enter category: ";
               cin>>catog;
               division[i]=catog;
               add(head, description,catog);
        }
        else if (choice == 2)
        {
               cout << "Enter a description: ";
               cin.ignore();
               getline(cin, description);
               complete(head, description);
        }
        else if (choice == 3)
        {
               cout << "Enter a description: ";
               cin.ignore();
               getline(cin, description);
               remove(head, description);
        }
        else if (choice == 4)
        {
               print(head);
        }
        else if(choice==5)
        {
              string desc;
              cout<<"Enter the description: ";
              cin>>desc;
              dessearch(head,desc);
        }
        else if (choice == 6)
        {
               clear(head);
        }
        else if(choice==7)
        {
            deadline();
        }
        else if(choice==8)
        {
            categorize(head,division);
        }
        else if(choice==9)
        {
            break;
        }
        else
        {
            cout << "Enter a valid option!" << endl;
        }

    }
}
