#include <iostream>
#include <vector>
using namespace std;

class BNode {
public:
    vector<int> key;  // Keys in the node
    vector<BNode*> children; // Child nodes
    int size; // Degree of the B-tree (maximum number of children)
    bool isLeaf; // True if the node is a leaf node, false otherwise

    // Constructor to initialize a node with degree and leaf status
    BNode(int size, bool isLeaf) {
        this->size = size;
        this->isLeaf = isLeaf;
        key.reserve(2 * size - 1);   // Reserve space for keys
        children.reserve(2 * size);  // Reserve space for children
    }

    // Function to split a child node of the current node
    void splitChildren(int place, BNode* root) {
        BNode* newNode = new BNode(size, root->isLeaf); // Create new node
        newNode->key.assign(root->key.begin() + size, root->key.end()); // Move keys
        root->key.resize(size - 1); // Keep only the first half of keys

        if (!root->isLeaf) {
            newNode->children.assign(root->children.begin() + size, root->children.end()); // Move children
            root->children.resize(size); // Resize to fit the parent
        }

        // Insert new node and middle key into the parent
        children.insert(children.begin() + place + 1, newNode);
        key.insert(key.begin() + place, root->key[size - 1]);
    }

    // Insert a key when the current node is full
    void insertKeyFull(int value) {
        int i = key.size() - 1;
        if (isLeaf) {
            // Insert key in sorted order for leaf nodes
            while (i >= 0 && key[i] > value) {
                i--;
            }
            i++;
            key.insert(key.begin() + i, value);
        } else {
            // Find the correct child to insert the key recursively
            while (i >= 0 && key[i] > value) {
                i--;
            }
            i++;

            // Split the child if it's full
            if (children[i]->key.size() == 2 * size - 1) {
                children[i]->splitChildren(i, children[i]);
                if (key[i] < value) {
                    i++; // Move to the next child if necessary
                }
            }
            children[i]->insertKeyFull(value); // Recursively insert in the child node
        }
    }

    // Traverse the tree and print the keys in sorted order
    void traverse() {
        int i;
        for (i = 0; i < key.size(); i++) {
            if (!isLeaf) {
                children[i]->traverse(); // Traverse the child node if not a leaf
            }
            cout << key[i] << " "; // Print the key
        }
        if (!isLeaf) {
            children[i]->traverse(); // Traverse the last child node if not a leaf
        }
    }
};

class BTree {
private:
    BNode* root; // Root node of the B-tree
    int size; // Degree (size) of the B-tree

public:
    // Constructor to initialize the B-tree
    BTree(int size) {
        this->size = size;
        root = new BNode(size, true); // Initialize root as a leaf node
    }

    // Insert a key into the B-tree
    void insert(int value) {
        if (root->key.size() == 2 * size - 1) { // If root is full
            BNode* newNode = new BNode(size, false); // Create a new non-leaf node
            newNode->children.push_back(root); // Make root a child of the new node
            newNode->splitChildren(0, root); // Split the old root node
            root = newNode; // Update root to the new node
        }
        root->insertKeyFull(value); // Insert the key into the tree
    }

    // Traverse and print the B-tree
    void traverse() {
        if (root) {
            root->traverse(); // Start traversal from the root node
        }
        cout << endl;
    }
};

int main() {
    BTree btree(3); // Create a B-tree of order 3 (t=3)

    // Insert values into the B-tree
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);

    cout << "B-Tree traversal: ";
    btree.traverse(); // Print the keys of the B-tree

    return 0;
}
