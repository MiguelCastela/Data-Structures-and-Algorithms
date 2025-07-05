#pragma once
#include <iostream>
#include "node.cpp"



class RedBlackTree {
public:
    Node* root;
    int rotations;

    RedBlackTree() {
        root = nullptr;    
        rotations = 0;

    }

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        newNode->color = RED;  // New nodes are always red
        return newNode;
    }

    void rotateLeft(Node*& root, Node*& pt) {
        rotations++;
        Node* pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != nullptr)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node*& root, Node*& pt) {
        rotations++;
        Node* pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != nullptr)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(Node*& root, Node*& pt) {
        Node* parent_pt = nullptr;
        Node* grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left) {
                Node* uncle_pt = grand_parent_pt->right;

                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateRight(root, grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            } else {
                Node* uncle_pt = grand_parent_pt->left;

                if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateLeft(root, grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

bool insert(const int& value) {
    Node* pt = createNode(value);

    if (!contains(root, pt->value)) {
        root = insert(root, pt);
        fixViolation(root, pt);
        return true;
    }

    delete pt;  // Free the memory of the duplicate node
    return false;
}

Node* insert(Node*& root, Node*& pt) {
    if (root == nullptr)
        return pt;

    if (pt->value < root->value) {
        root->left = insert(root->left, pt);
        root->left->parent = root;
    } else if (pt->value > root->value) {
        root->right = insert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

bool contains(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (value < root->value)
        return contains(root->left, value);
    else if (value > root->value)
        return contains(root->right, value);
    else
        return true;  // Value found in the tree
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