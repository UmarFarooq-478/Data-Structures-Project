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

#include "SHA_1.cpp"
#include "AVL_TREES.cpp"
#include "Machines_List.cpp"
#include "DHT.cpp"
int main()
{
	cout<<"<---- Welcome to Distributed Hash Table ---->";
	cout<<" <----------Specify DHT Properties--------->";
	DHT My_DHT;
	
	int ch;
	while(1)
	{
	cout<<"Enter your Choice:\n\n1. Input Data\n2.Display Data\n3.Print Routing Table of Any Machine\n4.Add Machine\n5.Delete Machine\n6.Exit\nEnter an Integer from 1 - 6 :\n";
	cin>>ch;
		switch(ch)
		{
			case 1:
				My_DHT.Input_Data();
				break;
			case 2:
				My_DHT.Display_Data();
				break;
			case 3:
				My_DHT.printRoutingTable();
				break;
			case 6:
				return 0;
			default:
				cout<<"\n\nInvalid Choice !!!!!!!\n\n";
		}
	}
return 0;
}