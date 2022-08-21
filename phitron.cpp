 #include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;///var
    ///Node constructor creation
    Node(int val)
    {
        value=val; /// |1|NULL|
        Next=NULL;
    }
} ;

struct Test
{
    int position[1000];
};

///Initialize
void insertAtTail(Node *&head,int val);

void insertAtHead(Node *&head,int val);

void display(Node *n);

int countLength(Node *&head);

void insertionAtSpecificPosition(Node* &head,int pos,int val);

void searchByValueDuplicate(Node* &head,int key);

void insertionByValueUnique(Node* &head,int searchValue,int value);

Test searchByValueDuplicateReturn(Node* &head,int key);

void deletionAtHead(Node* &head);

void deletionAtTail(Node* &head);

void deletionAtSpecificPosition(Node* &head,int position);

void deletionByValueUnique(Node* &head,int value);

Node* reverseNonRecursive(Node *&head);

Node* reverseRecursive(Node *&head);


void insertAtTail(Node *&head,int val)
{
    Node *newNode=new Node(val); ///object ///var
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node* temp=head; ///starting
    while(temp->Next!=NULL)
    {
        temp=temp->Next; ///moving right of temp->Next
    }
    temp->Next=newNode; ///linking last node to newNode=Null
}

void insertAtHead(Node *&head,int val)
{
    ///s1: newNode creation
    Node *newNode=new Node(val); ///object ///var
    ///s2: update of newNode->Next
    newNode->Next = head; ///keeping head value
    ///s3: Update of head
    head=newNode;
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL)
            cout<<" -> ";
        n=n->Next;
    }
    cout<<endl<<endl;
}
int countLength(Node *&head)
{
    int count=0;
    Node *temp=head; ///temporary temp
    while(temp!=NULL)
    {
        temp=temp->Next; ///going ahead and increasing count
        count++;
    }
    return count; ///when temp becomes null after next
}

void insertionAtSpecificPosition(Node* &head,int pos,int val)
{
    int i=0;
    Node*temp=head; ///capturing head in temp variable

    while(i<pos-2) /// 0< 4-2
    {
        temp=temp->Next; ///first 1 ///2 3
        i++;  ///1 2
    }
    Node *newNode=new Node(val); /// 4|NULL|  NEW NODE
    newNode->Next=temp->Next; ///3||xxx 4(ddd)||xxx  //5(xxx)||yyy
    temp->Next=newNode;       ///3(temp Next)||ddd 4(ddd)||xxx  //5(xxx)||yyy
}

int searchByValueUnique(Node* &head,int key)
{
    Node* temp=head; /// 1 2 3 4 5 6
    int count=1;
    if(temp==NULL)
    {
        return -1;
    }
    while(temp->value !=key)
    {
        if(temp->Next==NULL) ///after 6 next not found in the value
        {
            return -1;
        }
        temp=temp->Next; /// 2 3 4 5 6
        count++; /// 2 3 4
    }
    return count;
}
void searchByValueDuplicate(Node *&head,int key)
{
    Node* temp=head;
    int size;
    size=countLength(head);
    int position[size+1],k=1;
    int count=1;
    int flag=0;

    while(temp!=NULL)
    {
        if(temp->value==key)
        {
            position[k]=count;
            k++;
            flag=1;
        }
        temp=temp->Next;
        count++;
    }
    if(flag==0) cout<<"The Searched Value is not yet in the List"<<endl;
    else
    {
        position[0]=k;
        cout<<"The value is not found at Position: ";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1) cout<<",";
        }
        cout<<endl;
    }
}

Test searchByValueDuplicateReturn(Node* &head,int key)
{
    Node* temp=head;
    Test T;
    int k=1;
    int count=1;

    while(temp!=NULL)
    {
        if(temp->value==key)
        {
            T.position[k]=count;
            k++;
        }
        temp=temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void insertionByValueUnique(Node* &head,int searchValue,int value)
{
    int position;
    position=searchByValueUnique(head,searchValue);
    insertionAtSpecificPosition(head,position+1,value);
}

void deletionAtHead(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else
    {
        cout<<"There is No Value in the Linked List"<<endl;
    }

}
void deletionAtTail(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
    }
    else
    {
        ///Head is Null
        if(temp==NULL)
            cout<<"There is No Value in the Linked List"<<endl;

        ///Head is Tail
        else
        {
            deletionAtHead(head);
        }
    }
}
void deletionAtSpecificPosition(Node* &head,int position)
{
    Node* temp=head;
    if(position<=countLength(head))
    {

        if(position==1)
        {
            deletionAtHead(head);
        }
        else if(position==countLength(head)) ///tail
        {
            deletionAtTail(head);
        }
        else
        {
            int i=1;

            while(i<position-1)
            {
                temp=temp->Next;
                i++;
            }

            Node* delNode=temp->Next;
            temp->Next=delNode->Next;
            delete delNode;
        }
    }
    else
    {
        ///Position is Out of Range
//        if(position>countLength(head))
//        {
//            cout<<"Position is Out of Bound";
//        }

        cout<<"Position is Out of Bound";

        ///LL is NULL
//        else
//        {
//            cout<<"There is No Value in the Linked List"<<endl;
//        }
    }

}

void deletionByValueUnique(Node* &head,int value)
{
    ///Find the position of the value
    int position;
    position=searchByValueUnique(head,value);
    ///Delete the Node at that Position
    if(position==-1)
    {
        cout<<"Value not found in the Linked List"<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head,position);
    }

}

Node* reverseNonRecursive(Node *&head)
{
    Node* prev=NULL;
    Node* current=head;
    if(head==NULL)
    {
        cout<<"The Linked List is Empty"<<endl;
        return head;
    }
    Node* next=head->Next;

    while(true)
    {
        current->Next=prev;
        prev=current;
        current=next;
        if(current==NULL) break;
        next=next->Next;
    }
    return prev;
}

Node* reverseRecursive(Node *&head)
{
    //Base call
    if(head==NULL|| head->Next==NULL)
    {
       if(head==NULL) cout<<"The Linked List is Empty"<<endl;
        return head;///z
    }

    //Recursive call
    Node* newHead=reverseRecursive(head->Next);///z
    head->Next->Next=head; /// y(head)|z(next)-> z| null (next) head=z ///null //head=y
    head->Next=NULL;   ///  3|NULL

    return newHead; /// z
}

int midPoint(Node* & head){
    if(head == NULL){
        return -1;
    }
    Node * fast = head;
    Node * slow = head;

    while(fast != NULL && fast->Next != NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
}
void createCycle(Node*&head, int posi){
    Node * temp = head;
    Node * startNode;
    int coute = 1;

    while(temp->Next != NULL){
        if(coute == posi) startNode = temp;
        temp= temp->Next;
        coute++;
    }
    temp->Next = startNode;
}

bool detectCycle(Node* &head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->Next != NULL){

        fast = fast->Next->Next;
        slow = slow->Next;
         if(fast->Next == slow->Next){
           return true;
         }
    }
    return false;

}

void removeCycle(Node* &head){
    Node* fast = head;
    Node* slow = head;
    // step 1: slow = fast
    do{
       slow = slow->Next;
       fast = fast->Next->Next;
    }while(slow != fast);
    // step 2: reinitialization of fast
    fast = head;

    // step 3: fast->Next == slow->Next
    while(fast->Next != slow->Next){
        fast = fast->Next;
        slow = slow->Next;
    }
    // step 4: slow->Next = NULL
    slow->Next = NULL;



}

int main()
{
    Node *head=NULL;
    int value,position;
    cout<<"Choice 1: Insertion at Head"<<endl
        <<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 3: Insertion at specific Position"<<endl
        <<"Choice 4: Search a value(Unique List)"<<endl
        <<"Choice 5: Search a value(Duplication enabled List)"<<endl
        <<"Choice 6: Insertion after a specific value(Unique List)"<<endl
        <<"Choice 7: Deletion at Head"<<endl
        <<"Choice 8: Deletion at tail"<<endl
        <<"Choice 9: Deletion at specific Position"<<endl
        <<"Choice 10: Deletion by Value(Unique List)"<<endl
        <<"Choice 11: Reversal of List Non-Recursive"<<endl
        <<"Choice 12: Find mid"<<endl
        <<"Choice 13: Create a Cycle"<<endl
        <<"Choice 14: Detect a Cycle"<<endl
        <<"Choice 15: Delete The Cycle"<<endl
        <<"Choice 0:Exit"<<endl<<endl;

    int choice;
    cout<<"Next choice: ";
    cin>>choice;

    while(choice !=0 )
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the Value: ";
            cin>>value;
            insertAtHead(head,value);
            break;

        case 2:
            cout<<"Enter the Value: ";
            cin>>value;
            insertAtTail(head,value);
            break;

        case 3:
            cout<<"Enter the Desired position:  ";
            cin>>position;
            cout<<"Enter the Value: ";
            cin>>value;
            insertionAtSpecificPosition(head,position,value);
            break;

        case 4:
            cout<<"Enter the Value to search: ";
            cin>>value;
            position=searchByValueUnique(head,value);
            if(position !=-1)
            {
                cout<<"The number is at  "<<position<<endl;
            }
            else
            {
                cout<<"The number is not yet in the List "<<endl;
            }
            break;


        case 5:
            cout<<"Enter the Value to search: ";
            cin>>value;
//            searchByValueDuplicate(head,value);
            Test T;
            T=searchByValueDuplicateReturn(head,value);
            if(T.position[0]==1)
            {
                cout<<"The Searched Value is not yet in the List"<<endl;
            }
            else
            {
                int size=T.position[0];
                cout<<"The value is found at position: ";
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1) cout<<", ";
                }
                cout<<endl;
            }
            break;

        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            insertionByValueUnique(head,searchValue,value);
            break;

        case 7:
            deletionAtHead(head);
            break;

        case 8:
            deletionAtTail(head);
            break;

        case 9:
            if(head==NULL)
            {
                cout<<"There is No Value in the Linked List"<<endl;
                break;
            }
            cout<<"Enter the Desired position:  ";
            cin>>position;
            deletionAtSpecificPosition(head,position);
            display(head);
//            cout<<endl;
//            display(head);
            break;

        case 10:
            cout<<"Enter the value to delete: ";
            int delValue;
            cin>>delValue;
            deletionByValueUnique(head,delValue);
            break;

        case 11:
//            head=reverseNonRecursive(head);
            head=reverseRecursive(head);
            break;
        case 12:
            int mid;
            mid= midPoint(head);
            if(mid == -1){
                cout<<"The LL is Empty"<<endl;

            }
            else{
               cout<<mid<<endl;
            }
            break;
        case 13:
            cout<<"Enter the position you want add Cycle  : ";
            cin>>position;
            createCycle(head, position);
            break;
        case 14:
            bool ans;
            ans = detectCycle(head);
            if(ans == true){
                cout<<"Thar is a Cycle in the list"<<endl;
            }
            else{
                cout<<"Thar is no Cycle in the list"<<endl;
            }
            break;

        case 15:

            ans = detectCycle(head);
            if(ans == true){
                removeCycle(head);
            }
            else{
                cout<<"Thar is no Cycle in the list"<<endl;
            }
            break;


        default:
            break;
        }

        cout<<"Next choice: ";
        cin>>choice;
    }

    cout<<endl<<"Linked List: ";
    display(head);
    cout<<"Length of the List: "<<countLength(head)<<endl;

}

