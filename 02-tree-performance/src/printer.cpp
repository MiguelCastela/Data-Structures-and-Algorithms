#include <iostream>
#include <vector>
#include <cmath>
#include "node.cpp"

using namespace std;

class TreePrinter {
public:
    void printTree(Node* root, string indent = "", bool isLast = true) {
        if (root == nullptr) {
            return;
        }

        cout << indent;
        if (isLast){
            cout << "├── ";
            indent += "│   ";
        }
        else{
            cout << "└── ";
            indent += "    ";
        }

        cout << root->value << endl;  // Changed root->data to root->value

        printTree(root->right, indent, true);
        printTree(root->left, indent, false);
    }
};