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
class DHT{
    private:
        MachineList My_List;
        int machines;
        int id_space;
    public:
        DHT(){
            cout<<"Enter the number of machines:";
            cin>>machines;
            cout<<"Enter the size of Identifier Space:";
            cin>>id_space;
            char choice;
            cout<<"Do You want to Assign ids to machines(y/Y for yes):";
            cin>>choice;
            if(choice=='y' || choice=='Y')
            {
            cout<<"Enter keys in ascending order:\n";

                string ids[machines];
                for(int i=0;i<machines;i++)
                { 
                    cout<<"\nEnter The Key for machine "<<i+1<<":";
                    input:
                    {
                        cin>>ids[i];
                        //ids[i]=hashed(ids[i]);
                        for(int j=0;j<i;j++)
                        {
                            if(ids[j]==ids[i])
                            {
                                cout<<"Repeating IDs, Insert Again:";
                                goto input;
                            }
                        }
                    }
                    
                }
                string *ptr=sort(ids,machines);
                for(int i=0;i<machines;i++)
                {
                    My_List.insert(ptr[i]);
                }
                setRoutingTableManual(ptr);
            }
			else{
				for(int i=0;i<machines;i++){
					My_List.insert(to_string((i+1)*1000));
				}
				setRoutingTable();
			}
            My_List.traverse();
        }
		void Input_Data(){
			
				cout<<"From which machine do you want to enter data, enter id: ";
				string machine_id;
				cin>>machine_id;
				MachineNode* active_machine=My_List.Search(machine_id);//hashed(machine_id));
				if(active_machine) active_machine->insert_data();
				else cout <<"\nMachine Not Found\n";
		}
		void Display_Data(){
				cout<<"Data of which machine do you want to display, enter id: ";
				string machine_id;
				cin>>machine_id;
				MachineNode* active_machine=My_List.Search(machine_id);//(hashed(machine_id));
                if(active_machine) active_machine->Display_Tree();
				else cout <<"\nMachine Not Found\n";
		    
		}
		void setRoutingTable(){
		    for(int i=0;i<machines;i++)
		    {
		        MachineNode* Machine=My_List.Search(to_string((i+1)*1000));
		        for(int j=i;j<machines+i-1;j++)
		        {
		            Machine->routing_table.add_Node(My_List.Search(to_string(((j+1)%machines+1)*1000)));
		        }
		    }
//		    My_List.traverse();
		    
		}
		void setRoutingTableManual(string *array){
		    for(int i=0;i<machines;i++)
		    {
		        MachineNode* Machine=My_List.Search(array[i]);
		        for(int j=i+1;j<machines+i;j++)
		        {
		            Machine->routing_table.add_Node(My_List.Search(array[j%machines]));
		        }
		    }
//		    My_List.traverse();
		    
		}
		void printRoutingTable(){
				cout<<"Routing Table of which machine do you want to Display, enter id: ";
				string machine_id;
				cin>>machine_id;
				MachineNode* active_machine=My_List.Search(machine_id);//hashed(machine_id));
				if(active_machine) active_machine->routing_table.Display();
				else cout <<"\nMachine Not Found\n";
		}
		
    
};
