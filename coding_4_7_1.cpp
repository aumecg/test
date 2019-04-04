// project_build.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Node // could be realized with graph
{
public:
	char name;
	Node *children[];
};

using namespace std;

int main()
{

	char projects[6] = { 'a','b','c','d','e','f' };
	char dependencies[][2] = { {'a','d'}, {'f','b'}, {'b','d'}, {'f','a'}, {'d','c'} };

	vector<int> floor;
	vector<char> temp;
	Node *nodes[6];

	//get the floor and the project from the dependencies
	for (int i = 0; i < sizeof(dependencies) / sizeof(*dependencies); i++)
	{
		char node = dependencies[i][0];
		char depe = dependencies[i][1];
		
		if (find(temp.begin(), temp.end(), node) != temp.end())
		{
			int xn = find(temp.begin(), temp.end(), node) - temp.begin();
			int nf = floor[xn];

			if (find(temp.begin(), temp.end(), depe) == temp.end())
			{
				temp.push_back(depe);
				floor.push_back(nf + 1);
			}
			else
			{
				int x = find(temp.begin(), temp.end(), depe) - temp.begin();
				if(nf + 1 >= floor[x])
					floor[x] = nf + 1;
			}
		}
		else
		{
			temp.push_back(node);
			floor.push_back(1);
			if (find(temp.begin(), temp.end(), depe) == temp.end())
			{
				temp.push_back(depe);
				floor.push_back(2);
			}
			else
			{
				int x = find(temp.begin(), temp.end(), depe) - temp.begin();
				if(2 >= floor[x])
					floor[x] = 2;
			}
		}
	}

	//check if there is any missing project
	for (int i = 0; i < sizeof(projects); i++)
	{
		if (find(temp.begin(), temp.end(), projects[i]) == temp.end())
		{
			temp.push_back(projects[i]);
			floor.push_back(1);
		}
	}

	//print the order and the project
	for (int i = 0; i < floor.size(); i++)
	{
		cout << temp[i] << "," << floor[i]<<"\n";
	}
}