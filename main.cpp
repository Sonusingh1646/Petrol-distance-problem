
#include <iostream>

using namespace std;

class list
{
	public :
		int petrol, distance;
		list *next;
		
		list(int petrol, int distance);
};

list::list(int petrol, int distance)
{
	this->petrol = petrol;
	this->distance = distance;
    this->next = NULL;
}



int check_station(list *head)
{
	list* trav = head;
	list* temp = trav->next;
	int found=0,start=0,i=0,sumP=0,sumD=0;
	while(trav!=NULL)
	{

		if((trav->petrol)>=(trav->distance) && found==0)
		{
			
			found=1;
			start=i;			
		}
		if(found==1)
		{
			sumP+=trav->petrol;
			sumD+=trav->distance;
			if(sumP<sumD)
			{
				found=0;
				sumP=0;
				sumD=0;
			}
		}
		i++;
		trav=trav->next;
	}
	return start;
}

int main()
{
	
	list *head=NULL;
	int n, petrol, distance,i=0,sumP=0,sumD=0;
	
	cout << "Enter the number of petrol pumps : ";
	cin >> n;

	cout << "\nEnter the amount of petrol at station and distance to next petrol pump : \n";
	cin >> petrol>>distance;	
	list * curr = new list(petrol, distance);
	head=curr;
	i++;
	while(i < n)
	{
		cin >> petrol>>distance;	
		curr->next = new list(petrol, distance);
		curr=curr->next;
		sumP+=petrol;
		sumD+=distance;	
		i++;
	}
	
	if(sumP>=sumD)
		cout<<"\nStarting point from there full circle is possible is station with index :"<<check_station(head);
	else
		cout<<"\nThere not existing such starting point";
	return 0;
}
