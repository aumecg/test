#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int>> nodes;

void flooring(map<int, vector<int>> nodes, int root);

int main()
{
    //initialize the given tree
    nodes[5] = {2,7};
    nodes[2] = {12};
    nodes[7] = {8,3};
    nodes[12] = {};
    nodes[8] = {9,13};
    nodes[3] = {};
    nodes[9] = {};
    nodes[13] = {};

    //save each floor to a linked list
    //breadth first search
    flooring(nodes, 5);

    return 0;
}


void flooring(map<int, vector<int>> nodes, int root)
{
    vector<int> node;
    node.push_back(root);

    int floor = 0;
    vector<int> floor_order;
    floor_order.push_back(floor);

    vector<int> floor_node;
    floor_node.push_back(root);

    while (node.size()!=0)
    {
        auto it = find(floor_node.begin(), floor_node.end(), node.front());
        int dist = distance(floor_node.begin(), it);
        if(nodes[node.front()].size()!=0)
            floor = floor_order[dist] + 1;

        for(int s = 0; s < nodes[node.front()].size(); s++)
        {
            node.push_back(nodes[node.front()][s]);
            floor_order.push_back(floor);
            floor_node.push_back(nodes[node.front()][s]);
        }  

        node.erase(node.begin());
    }

    int f=0;

    for(int i=0;i<floor_node.size();i++)
    {
        f = floor_order[i];

        if(i==0)
        {
            cout<<f+1<<"th floor: ";
            cout<<floor_node[i];
        }
        else if (f != floor_order[i-1])
        {
            cout<<"\n"<<f+1<<"th floor: ";
            cout<<floor_node[i];
        }
        else
        {
            cout<<", "<<floor_node[i];
        }
    }
}