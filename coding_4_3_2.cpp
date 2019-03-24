#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int name;
	Node *children[];
};

class Floor
{
public:
	int name;
	Floor *next;
};

vector<vector<Floor*>> flooring(Node *root, int depth);
vector<Floor*> flooring_ts(Node *root, int depth);
void printList(Floor *n);

void flooring_nd(Node *root);

int main()
{
	//initialize the given tree

	Node *nodes[8];

	for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); i++)
	{
		Node *ob = new Node();
		nodes[i] = ob;
	}

	nodes[0]->name = 5; 
	nodes[1]->name = 2;
	nodes[2]->name = 7;
	nodes[3]->name = 12; 
	nodes[4]->name = 8;
	nodes[5]->name = 3;
	nodes[6]->name = 9;
	nodes[7]->name = 13;

	nodes[0]->children[0] = nodes[1];
	nodes[0]->children[1] = nodes[2];
	nodes[1]->children[0] = nodes[3];
	nodes[1]->children[1] = nullptr;
	nodes[2]->children[0] = nodes[4];
	nodes[2]->children[1] = nodes[5];
	nodes[3]->children[0] = nullptr;
	nodes[4]->children[0] = nodes[6];
	nodes[4]->children[1] = nodes[7];
	nodes[5]->children[0] = nullptr;
	nodes[6]->children[0] = nullptr;
	nodes[7]->children[0] = nullptr;

    //save each floor to a linked list
    //breadth first search
    auto fs = flooring_ts(nodes[0], 4);

	for (auto f : fs)
	{
		printList(f);
	}

	int a;
	cin >> a;

    return 0;
}

void flooring_nd(Node *root)
{
	vector<Node*> queue;
	vector<int> temp;

	queue.push_back(root);
	
	vector<int> numbers;
	vector<int> floors;
	int floor = 1;
	
	numbers.push_back(queue.back()->name);
	floors.push_back(floor);
	temp.push_back(floor);

	while (queue.size() != 0)
	{
		floor = temp.front();

		for (int i = 0; i < 2; i++)
		{
			if (queue.front()->children[i] == nullptr)
			{
				break;
			}
			else
			{
				queue.push_back(queue.front()->children[i]);
				floors.push_back(floor + 1);
				numbers.push_back(queue.front()->children[i]->name);
				temp.push_back(floor + 1);
			}
		}
		queue.erase(queue.begin());
		temp.erase(temp.begin());
	}
	
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << floors[i] << ", " << numbers[i] << "\n";
	}
}

vector<vector<Floor*>> flooring(Node *root, int depth)
{
	vector<Node*> queue;
	vector<int> temp;
	int floor = 0;

	vector<vector<Floor*>> floors(depth);

	queue.push_back(root);
	temp.push_back(floor);
	
	while (queue.size() != 0)
	{
		Floor *f, *fn;
		floor = temp.front();
		
		if (floors[floor].size()==0)
		{
			f = new Floor();
			f->name = queue.front()->name;
			f->next = nullptr;
			floors[floor].push_back(f);
		}
		else
		{
			f = floors[floor].back();
			fn = new Floor();
			fn->name = queue.front()->name;
			fn->next = nullptr;
			f->next = fn;
			floors[floor].push_back(fn);
		}

		for (int i = 0; i < 2; i++)
		{
			if (queue.front()->children[i] == nullptr)
			{
				break;
			}
			else
			{
				queue.push_back(queue.front()->children[i]);
				temp.push_back(floor + 1);				
			}
		}
		queue.erase(queue.begin());
		temp.erase(temp.begin());
	}
	return floors;
}

vector<Floor*> flooring_ts(Node *root, int depth)
{
	vector<Node*> queue;
	vector<int> temp;
	int floor = 0;

	vector<Floor*> floors;

	queue.push_back(root);
	temp.push_back(floor);

	while (queue.size() != 0)
	{
		Floor *f, *fn;
		floor = temp.front();

		if (floors.size() <= floor)
		{
			f = new Floor();
			f->name = queue.front()->name;
			f->next = nullptr;
			floors.push_back(f);
		}
		else
		{
			f = floors[floor];
			if (f->next == nullptr)
			{
				fn = new Floor();
				fn->name = queue.front()->name;
				f->next = fn;
			}
			else
			{
				f = f->next;
				fn = new Floor();
				fn->name = queue.front()->name;
				f->next = fn;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (queue.front()->children[i] == nullptr)
			{
				break;
			}
			else
			{
				queue.push_back(queue.front()->children[i]);
				temp.push_back(floor + 1);
			}
		}
		queue.erase(queue.begin());
		temp.erase(temp.begin());
	}
	return floors;
}

void printList(Floor *n)
{
	while (n != NULL)
	{
		cout << n->name <<", ";
		n = n->next;
	}
	cout << "\n";
}
