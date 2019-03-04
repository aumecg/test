#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
void enqueue(int type, char name);
void dequeue(int type);

vector<int> types;
vector<char> animals;
vector<clock_t> ages;

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

	int shelter_size =0;
	
	for(int i=0;i<types.size();i++)
	{
		if(types[i]>shelter_size)
			shelter_size++;
	}


//interface for adoption
	cout<<"We now has "<<shelter_size<<" types of animals in our shelter.\n";
	cout<<"Please choose one animal of any type for your adoption ([0,"<<shelter_size<<"], 0 if no preference): ";
	cin>>select_name;
	cout<<"\n";
	dequeue(select_name);

//interface for saving animals
	char new_name;
	int ani_type;
	cout<<"The type of the animal?"<<endl;
	cin>>ani_type;
	cout<<"The name of the animal?"<<endl;
	cin>>new_name;
	enqueue(ani_type, new_name);
	cout<<"Thank you for saving an animal. It is safe in the shelter now.\n"<<endl;

	cout<<"Here is the latest list of our animals:\nType,Name,Age"<<endl;
	for (int i=0;i<animals.size();i++)
	{
	cout<<types[i]<<","<<animals[i]<<","<<ages[i]<<endl;
	}

}

void enqueue(int type, char name)
{	
	types.push_back(type);
	animals.push_back(name);
	ages.push_back(clock());
	//cout<<"Welcome "<<name<<" to our shelter!"<<endl;
}

void dequeue(int type)
{
  char animal;
  int type_ani = type;
  clock_t age_time = clock();
 
  if (type != 0)
  {
    for (int i=0; i<types.size(); i++)
    {
       if(types[i] == type)
	{
	  type_ani = type;
          animal = animals[i];
          age_time = ages[i];

	  types.erase(types.begin()+i);
	  animals.erase(animals.begin()+i);
 	  ages.erase(ages.begin()+i);
          break;
	}
	i++;
    } 
  }
  else{
  type_ani = types.front();
  animal = animals.front();
  age_time = ages.front();

  types.erase(types.begin());
  animals.erase(animals.begin());
  ages.erase(ages.begin());
  }

  cout<<"Congraduations to "<<animal<<" for finding a home!"<<endl;
  cout<<animal<<" is of type "<<type_ani<<". It came to the shelter at day "<<age_time<<".\n"<<endl;	

}
