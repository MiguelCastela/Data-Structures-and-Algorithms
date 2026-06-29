#pragma once
#include <iostream>
#include <queue>
#include "node.cpp"

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    int insert(int value) {
        Node* newNode = createNode(value);

        if (root == nullptr) {
            root = newNode;
            return -1;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value < current->value)
                current = current->left;
            else if (value > current->value)
                current = current->right;
            else
                return current->value;  // Value is already in the tree
        }

        if (value < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;

        return -1;
    }

    bool search(int value) {
        Node* current = root;

        while (current != nullptr) {
            if (value < current->value)
                current = current->left;
            else if (value > current->value)
                current = current->right;
            else
                return true;  // Value found in the tree
        }

        return false;  // Value not found in the tree
    }
};