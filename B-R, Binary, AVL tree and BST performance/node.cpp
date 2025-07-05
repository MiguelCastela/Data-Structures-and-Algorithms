#pragma once
enum Color {RED, BLACK};
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    int height;

    Node() {
        value = 0;
        left = right = parent = nullptr;
        color = RED;
        height = 1;
    }
};