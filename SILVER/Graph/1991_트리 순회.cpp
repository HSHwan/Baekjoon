#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    Node* leftNode;
    Node* rightNode;
    char name;

    Node(char name) {
        this->name = name;
        leftNode = NULL;
        rightNode = NULL;
    }

    bool isNodeName(char name) {
        return this->name == name;
    }

    void setNodes(Node* leftNode, Node* rightNode) {
        if (!leftNode->isNodeName('.'))
            this->leftNode = leftNode;
        if (!rightNode->isNodeName('.'))
            this->rightNode = rightNode;
    }

    bool isLeftNull() {
        return leftNode == NULL;
    }

    bool isRightNull() {
        return rightNode == NULL;
    }
};

class Tree {
public:
    Node* rootNode;

    Tree() {
        rootNode = NULL;
    }
    
    void insert(char root, char left, char right) {
        if (rootNode == NULL) {
            rootNode = new Node(root);
            rootNode->setNodes(new Node(left), new Node(right));
            return;
        }

        queue<Node*> nodeQ;
        nodeQ.push(rootNode);
        
        while (!nodeQ.empty()) {
            Node* nowNode = nodeQ.front();
            nodeQ.pop();
            if (nowNode->isNodeName(root)) {
                nowNode->setNodes(new Node(left), new Node(right));
                return;
            }
            if (!nowNode->isLeftNull())
                nodeQ.push(nowNode->leftNode);
            if (!nowNode->isRightNull())
                nodeQ.push(nowNode->rightNode);
        }
    }
};

void traversalPreOrder(Node* node) {
    cout << node->name;
    if (!node->isLeftNull())
        traversalPreOrder(node->leftNode);
    if (!node->isRightNull())
        traversalPreOrder(node->rightNode);
}

void traversalInOrder(Node* node) {
    if (!node->isLeftNull())
        traversalInOrder(node->leftNode);
    cout << node->name;
    if (!node->isRightNull())
        traversalInOrder(node->rightNode);
}

void traversalPostOrder(Node* node) {
    if (!node->isLeftNull())
        traversalPostOrder(node->leftNode);
    if (!node->isRightNull())
        traversalPostOrder(node->rightNode);
    cout << node->name;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int nodeNum;
    cin >> nodeNum;

    Tree* tree = new Tree();
    char root, left, right;
    for (int i = 0; i < nodeNum; i++) {
        cin >> root >> left >> right;
        tree->insert(root, left, right);
    }
    
    traversalPreOrder(tree->rootNode);
    cout << '\n';
    traversalInOrder(tree->rootNode);
    cout << '\n';
    traversalPostOrder(tree->rootNode);
}