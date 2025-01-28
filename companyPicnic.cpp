// kattis problem

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

struct Node {
    double speed;
    vector<string> children;

};

pair<int, double> teamUp (string root, map<string, Node *> &people) {
    if (people[root]->children.empty()) {
        return {0, 0};
    }

    vector<pair<int, double>> bestWithout;
    pair<int, double> sum = {0, 0};
    for (string child : people[root]->children) {
        bestWithout.push_back(teamUp(child, people));
        sum.first += bestWithout[bestWithout.size() - 1].first;
        sum.second += bestWithout[bestWithout.size() - 1].second;
    }

    for (int i = 0; i < people[root]->children.size(); ++i) {
        pair<int, double> offer;
        for (int j = 0; j < people[root]->children.size(); ++j) {
            if (i == j) {
                offer.first++;
                offer.second += min(people[root]->speed, people[people[root]->children[j]]->speed);
                for (string grandChild : people[people[root]->children[j]]->children) {
                    pair<int, double> add = teamUp(grandChild, people);
                    offer.first += add.first;
                    offer.second += add.second; 
                }
            }
            else {
                offer.first += bestWithout[j].first;
                offer.second += bestWithout[j].second;
            }
        }
        sum = max(sum, offer);
    }

    return sum;
} 


int main() {
    int n; cin >> n;
    
    string root;
    map<string, Node *> people;

    for (int i = 0; i < n; ++i) {
        string name, boss;
        double speed;
        cin >> name >> speed >> boss;

        people[name]->speed = speed;
        people[boss]->children.push_back(name);
        if (boss == "CEO") {
            root = name;
        }
    }

    pair<int, double> result = teamUp(root, people);
    cout << result.second / result.first << endl;
}