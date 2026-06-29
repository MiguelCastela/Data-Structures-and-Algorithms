#pragma once
#include <iostream>
#include <queue>
#include <cstdlib>
#include "node.cpp"

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
        srand(time(0));  // Seed the random number generator
    }

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    void insert(int value) {
        if (search(value)) {
        //std::cout << "Value already exists in the tree.\n";
        return;
        }
        Node* newNode = createNode(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (rand() % 2 == 0) {  // 50% chance to go left
                if (temp->left != nullptr)
                    q.push(temp->left);
                else {
                    temp->left = newNode;
                    return;
                }
            } else {  // 50% chance to go right
                if (temp->right != nullptr)
                    q.push(temp->right);
                else {
                    temp->right = newNode;
                    return;
                }
            }
        }
    }

    bool search(int value) {
        if (root == nullptr)
            return false;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->value == value)
                return true;

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }

        return false;
    }
};