#include "printer.cpp"
#include "avl_tree.cpp"
#include "bst_tree.cpp"
#include "rbt_tree.cpp"
#include "node.cpp"
#include <iostream>
#include "binary_tree.cpp"
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <chrono>
#include <functional>

enum InsertionOrder {
    ORDERED,
    REVERSE_ORDERED,
    RANDOM
};
template <typename TreeType>
void insertNodes(TreeType& tree, int numNodes, bool reverse = false) {
    int duplicateOffset = numNodes / 10; // Calculate the offset for duplicate nodes
    if (reverse) {
        for (int i = numNodes; i >= 1; --i) {
            tree.insert(i);
            if (i % duplicateOffset == 0 && i != numNodes) { // Insert duplicate every 10th node
                tree.insert(i);
            }
        }
    } else {
        for (int i = 1; i <= numNodes; ++i) {
            tree.insert(i);
            if (i % duplicateOffset == 0 && i != numNodes) { // Insert duplicate every 10th node
                tree.insert(i);
            }
        }
    }
}
template <typename TreeType>
void insertNodesOrdered(TreeType& tree, int numNodes) {
    insertNodes(tree, numNodes, false);
}

template <typename TreeType>
void insertNodesRandomly(TreeType& tree, int numNodes) {
    std::vector<int> values(numNodes);
    std::iota(values.begin(), values.end(), 1);  // Fill the vector with 1, 2, ..., numNodes

    // Duplicate every 10th value
    int duplicateOffset = numNodes / 10;
    for (int i = duplicateOffset; i < numNodes; i += duplicateOffset) {
        values.push_back(i);
    }

    // Shuffle the values
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    // Insert the values into the tree
    for (int value : values) {
        tree.insert(value);
    }
}


template <typename TreeType>
void insertNodesRandomlyWithHighDuplication(TreeType& tree, int numNodes) {
    std::vector<int> values(numNodes);
    std::iota(values.begin(), values.end(), 1);  // Fill the vector with 1, 2, ..., numNodes

    // Duplicate every 10th value
    int duplicateOffset = numNodes / 10;
    for (int i = 1; i <= numNodes; ++i) {
        if (i % duplicateOffset != 0) { // Duplicate 90% of the nodes
            values.push_back(i);
        }
    }

    // Shuffle the values
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    // Insert the values into the tree
    for (int value : values) {
        tree.insert(value);
    }
}
template <typename TreeType>
void testTreeInsertionPerformance(TreeType& tree, int numNodes, InsertionOrder order, int duplicatePercentage) {
    std::function<void(TreeType&, int)> insertFunction;

    switch (order) {
        case ORDERED:
            insertFunction = insertNodesOrdered<TreeType>;
            break;
        case REVERSE_ORDERED:
            insertFunction = [](TreeType& tree, int numNodes) { insertNodes(tree, numNodes, true); };
            break;
        case RANDOM:
            if (duplicatePercentage == 10) {
                insertFunction = insertNodesRandomly<TreeType>;
            } else if (duplicatePercentage == 90) {
                insertFunction = insertNodesRandomlyWithHighDuplication<TreeType>;
            }
            break;
    }

    auto start = std::chrono::high_resolution_clock::now();
    insertFunction(tree, numNodes);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insert nodes into " << typeid(TreeType).name() << ": " << diff.count() << " s\n";
}
void runTestSet(int set) {
    BinaryTree bt;
    BinarySearchTree bst;
    AVLTree avl;
    RedBlackTree rbt;
    TreePrinter tp;

    switch (set) {
        case 1: // CONJUNTO A
            testTreeInsertionPerformance(bt, 100000, ORDERED, 10);
            testTreeInsertionPerformance(bst, 100000, ORDERED, 10);
            testTreeInsertionPerformance(avl, 100000, ORDERED, 10);
            std::cout << "Number of rotations in AVL Tree: " << avl.getRotations() << "\n";
            testTreeInsertionPerformance(rbt, 100000, ORDERED, 10);
            std::cout << "Number of rotations in Red-Black Tree: " << rbt.getRotations() << "\n";
            break;
        case 2: // CONJUNTO B
            testTreeInsertionPerformance(bt, 70000, REVERSE_ORDERED, 10);
            testTreeInsertionPerformance(bst, 70000, REVERSE_ORDERED, 10);
            testTreeInsertionPerformance(avl, 70000, REVERSE_ORDERED, 10);
            std::cout << "Number of rotations in AVL Tree: " << avl.getRotations() << "\n";
            testTreeInsertionPerformance(rbt, 70000, REVERSE_ORDERED, 10);
            std::cout << "Number of rotations in Red-Black Tree: " << rbt.getRotations() << "\n";
            break;
        case 3: // CONJUNTO C
            testTreeInsertionPerformance(bt, 10000, RANDOM, 10);
            testTreeInsertionPerformance(bst, 10000, RANDOM, 10);
            testTreeInsertionPerformance(avl, 10000, RANDOM, 10);
            std::cout << "Number of rotations in AVL Tree: " << avl.getRotations() << "\n";
            testTreeInsertionPerformance(rbt, 10000, RANDOM, 10);
            std::cout << "Number of rotations in Red-Black Tree: " << rbt.getRotations() << "\n";
            break;
        case 4: // CONJUNTO D
            testTreeInsertionPerformance(bt, 10000, RANDOM, 90);
            testTreeInsertionPerformance(bst, 10000, RANDOM, 90);
            testTreeInsertionPerformance(avl, 10000, RANDOM, 90);
            std::cout << "Number of rotations in AVL Tree: " << avl.getRotations() << "\n";
            testTreeInsertionPerformance(rbt, 10000, RANDOM, 90);
            std::cout << "Number of rotations in Red-Black Tree: " << rbt.getRotations() << "\n";
            break;
        default:
            std::cout << "Invalid test set number. Please enter a number between 1 and 4.\n";
            break;
    }
}
int main() {
    runTestSet(2);
    return 0;






/*
    //conunto1
    auto start = std::chrono::high_resolution_clock::now();
    insertNodes(bt, 200000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insert nodes into BinaryTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(bst, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into BinarySearchTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(avl, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into AVLTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(rbt, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into RedBlackTree: " << diff.count() << " s\n";
    




    //conjunto2 
    auto start = std::chrono::high_resolution_clock::now();
    insertNodes(bt, 200000, true);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insert nodes into BinaryTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(bst, 200000,   true);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into BinarySearchTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(avl, 200000, true);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into AVLTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodes(rbt, 200000, true);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into RedBlackTree: " << diff.count() << " s\n";
    return 0;



    //conjunto3
    //random dor 10% duplication
    auto start = std::chrono::high_resolution_clock::now();
    insertNodesRandomly(bt, 200000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insert nodes into BinaryTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomly(bst, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into BinarySearchTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomly(avl, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into AVLTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomly(rbt, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into RedBlackTree: " << diff.count() << " s\n";
    


    //conjunto4
    //random dor 90% duplication
    auto start = std::chrono::high_resolution_clock::now();
    insertNodesRandomlyWithHighDuplication(bt, 200000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insert nodes into BinaryTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomlyWithHighDuplication(bst, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into BinarySearchTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomlyWithHighDuplication(avl, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into AVLTree: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    insertNodesRandomlyWithHighDuplication(rbt, 200000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to insert nodes into RedBlackTree: " << diff.count() << " s\n";
*/
}