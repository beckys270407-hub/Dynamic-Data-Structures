#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = NULL;
        right = NULL;
    }
};

class Queue {
private:
    Node* arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool empty() {
        return front > rear;
    }

    void push(Node* n) {
        rear++;
        arr[rear] = n;
    }

    Node* pop() {
        return arr[front++];
    }
};

class Tree {
private:
    Node* root;

    int path[100];
    int best[100];
    int bestLen;
    double minDiff;

public:
    Tree() {
        root = NULL;
        bestLen = 0;
        minDiff = 999999;
    }

    void insert(int val) {
        Node* n = new Node(val);

        if (root == NULL) {
            root = n;
            return;
        }

        Queue q;
        q.push(root);

        while (!q.empty()) {
            Node* t = q.pop();

            if (t->left == NULL) {
                t->left = n;
                return;
            } else {
                q.push(t->left);
            }

            if (t->right == NULL) {
                t->right = n;
                return;
            } else {
                q.push(t->right);
            }
        }
    }

    void sumPaths(Node* node, int len, int& total, int& count) {
        if (node == NULL) return;

        path[len] = node->data;
        len++;

        if (node->left == NULL && node->right == NULL) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += path[i];
            }
            total += sum;
            count++;
        } else {
            sumPaths(node->left, len, total, count);
            sumPaths(node->right, len, total, count);
        }
    }

    void bestPath(Node* node, int len, double avg) {
        if (node == NULL) return;

        path[len] = node->data;
        len++;

        if (node->left == NULL && node->right == NULL) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += path[i];
            }

            double diff = fabs(sum - avg);

            if (diff < minDiff) {
                minDiff = diff;
                bestLen = len;

                for (int i = 0; i < len; i++) {
                    best[i] = path[i];
                }
            }
        } else {
            bestPath(node->left, len, avg);
            bestPath(node->right, len, avg);
        }
    }

    void solve() {
        if (root == NULL) {
            cout << "Tree empty\n";
            return;
        }

        int total = 0;
        int count = 0;

        sumPaths(root, 0, total, count);

        cout << "DEBUG -> paths found: " << count << endl;

        if (count == 0) return;

        double avg = (double)total / count;

        bestPath(root, 0, avg);

        cout << "\nAverage: " << avg << endl;

        cout << "Best path: ";
        for (int i = 0; i < bestLen; i++) {
            cout << best[i];
            if (i < bestLen - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    cout << "START PROGRAM\n";

    Tree t;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "You entered: " << n << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Value " << i+1 << ": ";
        cin >> x;

        cout << "Read: " << x << endl;

        t.insert(x);
    }

    cout << "\n--- PROCESS ---\n";
    t.solve();

    cout << "\nEND PROGRAM\n";
    return 0;
}