#pragma once
#include <iostream>
#include <algorithm>
#include "node.cpp"

class AVLTree {
public:
    Node* root;
    int rotations;
    AVLTree() {
        root = nullptr;
        rotations = 0;

    }

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        newNode->height = 1;  // New nodes are added at leaf
        return newNode;
    }

    int height(Node* N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int balanceFactor(Node* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node* rotateRight(Node* y) {
        rotations++;
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        rotations++;
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }
    void insert(int value) {
    root = insert(root, value);
}

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return createNode(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            return node;  // Equal values are not allowed in BST

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && value < node->left->value)
            return rotateRight(node);

        if (balance < -1 && value > node->right->value)
            return rotateLeft(node);

        if (balance > 1 && value > node->left->value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool search(Node* root, int value) {
        if (root == nullptr)
            return false;

        if (value < root->value)
            return search(root->left, value);
        else if (value > root->value)
            return search(root->right, value);
        else
            return true;  // Value found in the tree
    }
    int getRotations() {
        return rotations;
    }
};