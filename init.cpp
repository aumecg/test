#include <iostream>
#include <list>
#include <map>
#include <time.h>

using namespace std;
void enqueue(int type, char name);
void dequeue(int type);


map<int, list<char>> animals;
map<int, list<clock_t>> ages;

int main()
{
	int select_name;
//save animals in shelter
	enqueue(1, 'd');
	enqueue(2, 's');
	enqueue(2, 'c');
	enqueue(1, 'x');
	enqueue(3, 'e');
	enqueue(1, 'm');
	enqueue(3, 'w');
	enqueue(2, 'g');
	int shelter_size = animals.size();

//interface for adoption
	cout<<"We now has "<<shelter_size<<" types of animals in our shelter.\n";
	cout<<"Please choose one animal of any type for your adoption ([0,"<<shelter_size<<"], 0 if no preference): ";
	cin>>select_name;
	cout<<"\n";
	dequeue(select_name);
}

void enqueue(int type, char name)
{
	animals[type].push_back(name);
	ages[type].push_back(clock());
	//cout<<"Welcome "<<name<<" to our shelter!"<<endl;
}

void dequeue(int type)
{
  char animal;
  int type_ani = type;
  clock_t age_time = clock();

  if (type == 0)
  {
    for(auto& age : ages)
    {
	  if(age_time - age.second.front() > 0)
	    {
		age_time = age.second.front();
		type_ani = age.first;
	    }
    }
 
  }
  animal = animals[type_ani].front();
  age_time = ages[type_ani].front();

  animals[type_ani].pop_front();
  ages[type_ani].pop_front();

  cout<<"Congraduations to "<<animal<<" for finding a home!"<<endl;
  cout<<animal<<" is of type "<<type_ani<<". It came to the shelter at day "<<age_time<<".\n"<<endl;	

}
