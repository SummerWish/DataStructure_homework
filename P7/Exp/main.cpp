//
//  main.cpp
//  Exp
//
//  Created by Breezewish on 11/3/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

class TreeNode
{
public:
    char data;
    TreeNode *left, *right;
    TreeNode(char ch) {
        data = ch;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

// get operator priority
int getOpPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

string generateReversePolish(string exp) {
    stack<char> operators;
    string ret;
    
    for (int i = 0; i < exp.size(); ++i) {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            ret += ch;
        } else {
            if (ch == '(') {
                operators.push('(');
            } else if (ch == ')') {
                // close: pop up all operators in (...)
                while (operators.top() != '(') {
                    ret += operators.top();
                    operators.pop();
                }
                operators.pop();
            } else {
                if (operators.empty()) {
                    // no operators in the stack: push operator to the stack
                    operators.push(ch);
                } else {
                    // compare operator priority
                    if (getOpPriority(ch) > getOpPriority(operators.top())) {
                        operators.push(ch);
                    } else {
                        // push all previous operators
                        while (!operators.empty() && getOpPriority(ch) <= getOpPriority(operators.top())) {
                            ret += operators.top();
                            operators.pop();
                        }
                        operators.push(ch);
                    }
                }
            }
        }
    }
    
    while (!operators.empty()) {
        ret += operators.top();
        operators.pop();
    }
    
    return ret;
}

// create tree from reverse polish expression
TreeNode* createExpressionTree(string exp) {
    stack<TreeNode*> s;
    for (int i = 0; i < exp.size(); ++i) {
        char ch = exp[i];
        if (getOpPriority(ch) != 0) {
            // it is an operator
            TreeNode *node = new TreeNode(ch);
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
            s.push(node);
        } else {
            s.push(new TreeNode(ch));
        }
    }
    return s.top();
}

// Traverse a tree in pre-order
string preorder(TreeNode *root) {
    string ret = "";
    if (root != NULL) {
        ret += root->data;
        ret += preorder(root->left);
        ret += preorder(root->right);
    }
    return ret;
}

// Traverse a tree in in-order
string inorder(TreeNode *root) {
    string ret = "";
    if (root != NULL) {
        ret += inorder(root->left);
        ret += root->data;
        ret += inorder(root->right);
    }
    return ret;
}

// Traverse a tree in post-order
string postorder(TreeNode *root) {
    string ret = "";
    if (root != NULL) {
        ret += postorder(root->left);
        ret += postorder(root->right);
        ret += root->data;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    string exp;
    cout << "Please input an expression: ";
    getline(cin, exp);
    
    string revPolish = generateReversePolish(exp);
    cout << "Reverse polish expression: " << revPolish << endl;
    
    // let's build the tree from reverse polish expression
    TreeNode *head = createExpressionTree(revPolish);
    
    cout << "Pre-order tree traverse: " << preorder(head) << endl;
    cout << "In-order tree traverse: " << inorder(head) << endl;
    cout << "Post-order tree traverse: " << postorder(head) << endl;
    
    return 0;
}
