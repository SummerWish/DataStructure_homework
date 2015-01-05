//
//  main.cpp
//  MST
//
//  Created by Breezewish on 12/13/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Edge {
public:
    int a;
    int b;
    int v;
    bool selected;
    Edge(int _a, int _b, int _v) {
        a = _a;
        b = _b;
        v = _v;
        selected = false;
    }
};

vector<int> parent;
int findRoot(int x) {
    if (x != parent[x]) {
        parent[x] = findRoot(parent[x]);
    }
    return parent[x];
}

bool sort_func(const Edge &a, const Edge &b) {
    return a.v < b.v;
}

int main(int argc, const char * argv[]) {
    
    cout << "Power Grid Price Assessment System" << endl;
    cout << "==================================" << endl;
    cout << "1 - add vertex" << endl;
    cout << "2 - add edge" << endl;
    cout << "3 - create MST" << endl;
    cout << "4 - show MST" << endl;
    cout << "5 - quit" << endl;
    cout << "==================================" << endl;
    
    int op = -1;
    
    int vertex_count = 0;
    map<string, int> vname2index;
    map<int, string> index2vname;
    vector<Edge> edges;
    
    while (op != 5) {
        string line;
        cout << "Please select an operation: ";
        getline(cin, line);
        op = stoi(line);
        
        switch (op) {
            case 1: { // add vertex
                cout << "Please input vertex names, split by space: ";
                string l; getline(cin, l);
                istringstream iss(l);
                do
                {
                    string name;
                    iss >> name;
                    vname2index[name] = vertex_count;
                    index2vname[vertex_count] = name;
                    vertex_count++;
                } while (iss);
                
                cout << "Completed!" << endl << endl;
                
                break;
            }
            case 2: { // add edge
                while (true) {
                    cout << "Please input the two vertices and their weight: ";
                    string l; getline(cin, l);
                    istringstream iss(l);
                    
                    string sa, sb, sv;
                    iss >> sa >> sb >> sv;
                    if (sa == "?" || sb == "?" || sv == "?") {
                        break;
                    }
                    
                    try {
                        int a, b, v;
                        a = vname2index[sa];
                        b = vname2index[sb];
                        v = stoi(sv);
                        edges.push_back(Edge(a, b, v));
                    } catch(...) {
                        break;
                    }
                }
                
                cout << "Completed!" << endl << endl;
                
                break;
            }
            case 3: { // create MST using Kruskal
                
                // clear select status
                for (int i = 0; i < edges.size(); ++i) {
                    edges[i].selected = false;
                }
                
                // sort all edges
                sort(edges.begin(), edges.end(), sort_func);
                
                // initialize parent array
                parent.clear();
                for (int i = 0; i < vertex_count; ++i) {
                    parent.push_back(i);
                }
                
                // select an edge
                for (int i = 0; i < edges.size(); ++i) {
                    int x = findRoot(edges[i].a);
                    int y = findRoot(edges[i].b);
                    if (x == y) {
                        continue;
                    }
                    edges[i].selected = true;
                    parent[x] = y;
                }
                
                cout << "Completed!" << endl << endl;
                 
                break;
            }
            case 4: { // show MST
                
                cout << "Generated MST edges: " << endl;
                
                for (int i = 0; i < edges.size(); ++i) {
                    if (edges[i].selected) {
                        cout << index2vname[edges[i].a] << "--(" << edges[i].v << ")-->" << index2vname[edges[i].b] << endl;
                    }
                }
                
                cout << endl;
                
                break;
            }
            case 5: {
                
                cout << "bye!" << endl;
                
                break;
            }
        }
        
    }
    
    return 0;
}
