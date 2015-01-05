//
//  main.cpp
//  BST
//
//  Created by Breezewish on 11/24/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int key;
    int n;
    Node* left;
    Node* right;
    Node(int k):key(k),n(1),left(NULL),right(NULL){};
};

void insert(Node* &node, int key)
{
    if (node == NULL) {
        node = new Node(key);
        return;
    }
    if (key < node->key) {
        insert(node->left, key);
    } else if (key > node->key) {
        insert(node->right, key);
    } else {
        node->n++;
    }
}

Node* find(Node* node, int key)
{
    if (node == NULL) {
        return NULL;
    }
    if (key < node->key) {
        return find(node->left, key);
    } else if (key > node->key) {
        return find(node->right, key);
    } else {
        return node;
    }
}

void remove(Node* &node, int key)
{
    if (node == NULL) {
        return;
    }
    if (key < node->key) {
        remove(node->left, key);
    } else if (key > node->key) {
        remove(node->right, key);
    } else {
        if (node->n > 1) {
            node->n--;
            return;
        }
        if (node->left == NULL) {
            Node *temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == NULL) {
            Node *temp = node;
            node = node->left;
            delete temp;
        } else {
            Node *min = node->right;
            while (min->left != NULL) min = min->left;
            node->key = min->key;
            node->n = min->n;
            remove(node->right, min->key);
        }
    }
}

string inorder(Node* node)
{
    string ret = "";
    if (node != NULL) {
        ret += inorder(node->left);
        for (int i = 0; i < node->n; ++i) {
            ret += to_string(node->key);
            ret += " ";
        }
        ret += inorder(node->right);
    }
    return ret;
}

const int OP_CREATE = 1;
const int OP_INSERT = 2;
const int OP_SEARCH = 3;
const int OP_DELETE = 4;
const int OP_EXIT = 5;

#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

Node* root = NULL;

int main(int argc, const char * argv[]) {

    cout << "Binary Search Tree Demo" << endl;
    cout << "1 -- Create BST" << endl;
    cout << "2 -- Insert element" << endl;
    cout << "3 -- Search element" << endl;
    cout << "4 -- Delete element" << endl;
    cout << "5 -- Exit" << endl;
    
    int operation;
    do {
        string opl;
        cout << endl;
        cout << ">> ";
        getline(cin, opl);
        operation = stoi(opl);
        
        switch (operation) {
            case OP_CREATE: {
                cout << "Input initial elements: ";
                string line;
                getline(cin, line);
                
                vector<int> elements;
                istringstream iss(line);
                copy(istream_iterator<int>(iss),
                     istream_iterator<int>(),
                     back_inserter(elements));
                
                for (int i = 0; i < elements.size(); ++i) {
                    insert(root, elements[i]);
                }
                
                cout << endl << "Operation done." << endl;
                cout << "Inorder Tree: " << inorder(root) << endl;
                break;
            }
            case OP_INSERT: {
                cout << "Input the element to insert: ";
                int el; cin >> el; getchar();
                
                insert(root, el);
                
                cout << endl << "Operation done." << endl;
                cout << "Inorder Tree: " << inorder(root) << endl;
                break;
            }
            case OP_SEARCH: {
                cout << "Input the element to find: ";
                int el; cin >> el; getchar();
                
                Node* n = find(root, el);
                if (n == NULL) {
                    cout << "Cannot find element in the tree!" << endl;
                } else {
                    cout << "Element found in the tree." << endl;
                }
                break;
            }
            case OP_DELETE: {
                cout << "Input the element to delete: ";
                int el; cin >> el; getchar();
                
                remove(root, el);
                
                cout << endl << "Operation done." << endl;
                cout << "Inorder Tree: " << inorder(root) << endl;
                break;
            }
            case OP_EXIT: {
                break;
            }
            default: {
                cout << "Unknown operation." << endl;
                break;
            }
                
        }
    } while (operation != OP_EXIT);
    
    cout << "bye!" << endl;
    
    return 0;
}
