#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

struct Node {
    int val;
    Node* left, * right;

};

void insert (int val, Node *root) {
    if (root->val > val) {
        if (root->left != nullptr) {
            insert(val, root->left);
        }
        else {
            root->left = new Node;
            root->left->val = val;
            root->left->left = nullptr;
            root->left->right = nullptr;
        }
    }
    else {
       if (root->right != nullptr) {
            insert(val, root->right);
        }
        else {
            root->right = new Node;
            root->right->val = val;
            root->right->left = nullptr;
            root->right->right = nullptr;
        } 
    }
}

bool sameSkele(Node *r1, Node *r2) {
    if (r1->left == nullptr && r2->left == nullptr && r1->right == nullptr && r2->right == nullptr) {
        return true;
    }

    if (r1->left == nullptr && r2->left == nullptr) {
    }
    else if (r1->left == nullptr || r2->left == nullptr) {
        return false;
    }
    else {
        if (!sameSkele(r1->left, r2->left)) {
            return false;
        }
    }

    if (r1->right == nullptr && r2->right == nullptr) {
    }
    else if (r1->right == nullptr || r2->right == nullptr) {
        return false;
    }
    else {
        if (!sameSkele(r1->right, r2->right)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k; cin >> n >> k;
    vector<Node *> roots(n);
    for (int i = 0; i < n; ++i) {
        Node *newNode = new Node;
        newNode->left = nullptr;
        newNode->right = nullptr;
        int val; cin >> val;
        newNode->val = val;

        roots[i] = newNode;

        for (int j = 1; j < k; ++j) {
            cin >> val;
            insert(val, newNode);
        }
    }

    vector<Node *> skeletons;
    skeletons.push_back(roots[0]);
    for (int i = 1; i < n; ++i) {
        bool noMatch = true;
        for (int j = 0; j < skeletons.size() && noMatch; ++j) {
            if (sameSkele(roots[i], skeletons[j])) {
                noMatch = false;
                // cout << "tree " << i << " matches skeleton w/ root val: " << skeletons[j]->val << endl;
            }
        }
        if (noMatch) {
            skeletons.push_back(roots[i]);
        }
    }

    cout << skeletons.size() << endl;
}