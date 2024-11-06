#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct Pair {
    char type;
    long unsigned int open_pos;
    long unsigned int close_pos;
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string expression;
    getline(cin, expression);

    stack<pair<char, long unsigned int>> s;
    vector<Pair> pairs;

    for (long unsigned int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push({ch, i});
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || !isMatchingPair(s.top().first, ch)) {
                cout << "badly matched pairs" << endl;
                return 0;
            } else {
                pairs.push_back({s.top().first, s.top().second, i});
                s.pop();
            }
        }
    }

    if (!s.empty()) {
        cout << "badly matched pairs" << endl;
    } else if (pairs.empty()) {
        cout << "no brides and grooms to marry" << endl;
    } else {
        for (const auto& p : pairs) {
            char close_type;
            if (p.type == '(') close_type = ')';
            else if (p.type == '[') close_type = ']';
            else if (p.type == '{') close_type = '}';
            cout << p.type << close_type << " " << p.open_pos << " " << p.close_pos << endl;
        }
    }

    return 0;
}