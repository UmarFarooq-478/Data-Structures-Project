#include<bits/stdc++.h> 
#include<string>
#include<cstring>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std; 
struct File{
  string name;
  int total_data;
  File(string filename){
      name=filename;
      total_data=1;
  }
  bool isFull(){
      return total_data>=100;
  }
  void writeData(string data){
      fstream obj;
      obj.open(name,ios::app);
      obj<<data+"\n";
      total_data++;
  }
};

template <class T>
class double_llist
{
    private:
        struct node
        {
            T double_list_data;
            struct node *next=nullptr;
            struct node *prev=nullptr;
            node(T data){
            double_list_data= data;
            }
            node(){}

        }*head,*tail;
    
    public:
        double_llist(){
            head=nullptr;
            tail=nullptr;
        }
        void add_Node(T data){
            if (!head){
                head = new node(data);
                head->next=nullptr;
                head->prev=nullptr;
                return;
            }
            node* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
                
            }
            temp->next=new node(data);
            temp->next->prev=temp;
            tail=temp->next;
            return;
        }   
        void Display(){
            if(!head){
                cout<<"List is Empty\n";
                return;
            }
            node* temp=head;
            while(temp){
                cout<<temp->double_list_data<<endl;
                temp=temp->next;
            }
        }
         T operator[](int i){
            if(!head){
                return nullptr; 
            }
            node* temp=head;
            int j=0;
            while(j<i && temp){
                temp=temp->next;
                j++;
            }
            if(temp) return temp->double_list_data;
            else return nullptr;
         } 
};
struct MachineNode
{
    string prev_ID;
    vector <File> Files;
    int MachineNumber;
//    int total_files;
	string ID;
	AVL_TREE Tree;
    MachineNode *next;
    double_llist<MachineNode*> routing_table;
    MachineNode(int MachineNumber){
        this->MachineNumber=MachineNumber;
        string filename="machine_"+to_string(this->MachineNumber)+"_file_no_1.txt";
        Files.push_back(filename);      
    }
    
void insert_data(){
	cout<<"Entering Data From machine with id \" "<<ID<<" \" is as follows:\n";
	string key;
	string data;
    char ch;
	do{
		cout<<"Enter Key:";
		str_input();
		key=str_input();
		cout<<"Enter Data:";
		data=str_input();
		MachineNode* Machine=this;
		int i=0;
		while( Machine)
		{
            if(key>Machine->ID)
            {
                Machine=routing_table[i];
		     //   cout<<Machine->ID;
		        i++;
            }
            else
                break;
		}
		if(!Machine){
		    Machine=this;
		}
		if(Machine->Files[Machine->Files.size()-1].isFull()){
		    Machine->Files.push_back("machine_"+to_string(Machine->MachineNumber)+"file_no"+to_string(Machine->Files.size()+1)+".txt");
            cout<<"Here";
		}
		Machine->Files[Machine->Files.size()-1].writeData(data);
		Machine->Tree.insert(key,Machine->Files[Machine->Files.size()-1].name);
		cout<<"Do you want to Enter Again? :";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
void Display_Tree(){
	cout<<"The Data Stored on machine with id \" "<<ID<<" \" is as follows:\n";
	Tree.Display();
}
};
ostream & operator << (ostream &out, MachineNode* machine_node) 
{ 
	cout<<machine_node->ID<<" ";
//    machine_node->Tree.Display(); 
    
    return out; 
}

class MachineList{
	MachineNode* head;
	int size;
	public:
MachineList(){
	head=NULL;
	size=0;
}
bool insert(string ID,string prev_ID="Empty"){
		if(size==0){
			head=addToEmpty(ID,1);
			size++;
			return 1;
		}
		MachineNode *p = head -> next;

	// Traversing the list.
	do
	{

	    if(p->ID==ID){
	        return 0;
	    }
		p = p -> next;

	}	while(p != head->next);


	    if(prev_ID!="Empty")
			head = addAfter(ID,prev_ID,size++);
		else 
			head= addEnd(ID,++size);

head->MachineNumber=size;
return 1;
}
MachineNode *addToEmpty(string ID,int n)
{
	// This function is only for empty list
	if (head != NULL)
	return head;

	// Creating a MachineNode dynamically.
	 MachineNode *temp = new MachineNode(n);

	// Assigning the ID.
	temp -> ID = ID;
	head = temp;

	// Creating the link.
	head -> next = head;

	return head;
}

 MachineNode *addBegin(string ID,int n)
{
	if (head == NULL)
		return addToEmpty(ID,n);

	MachineNode *temp = new MachineNode(n);

	temp -> ID = ID;
	temp -> next = head -> next;
	head -> next = temp;

	return head;
}

 MachineNode *addEnd(string ID,int n)
{
	if (head == NULL)
		return addToEmpty( ID,n);
	
	MachineNode *temp = 	new MachineNode(n);

	temp -> ID = ID;
	temp -> next = head -> next;
	head -> next = temp;
	temp->prev_ID=head->ID;

	head = temp;
	return head;
}

 MachineNode *addAfter( string ID, string prev_ID,int n)
{
	if (head == NULL)
		return NULL;

	 MachineNode *temp, *p;
	p = head -> next;
	do
	{
		if (p ->ID == prev_ID)
		{
			temp = new MachineNode (n);
			temp -> ID = ID;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == head)
				head = temp;
			return head;
		}
		p = p -> next;
	} while(p != head -> next);

	cout << prev_ID << " not present in the list." << endl;
	return head;

}
MachineNode* Search(string IDs)
{
	 MachineNode *p;

	// If list is empty, return.
	if (head == NULL)
	{
		cout << "List is empty." << endl;
		return nullptr;
	}

	// Pointing to first MachineNode of the list.
	p = head ->next;

	// Traversing the list.
	do
	{

	    if(p->ID==IDs)
	        return p;
		p = p -> next;

	}
	while(p != head->next);

    return nullptr;
}
void traverse()
{
	 MachineNode *p;

	// If list is empty, return.
	if (head == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first MachineNode of the list.
	p = head -> next;

	// Traversing the list.
	do
	{
		cout << p -> ID <<" "<<p->MachineNumber<<" Routing Table:"<< endl;
//	    p->routing_table.Display();
		p = p -> next;

	}
	while(p != head->next);

}

};

