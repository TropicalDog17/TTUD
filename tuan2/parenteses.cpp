#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  cin >> str;
  stack<char> s;
  for (auto &ch : str) {
    if (s.empty() && (ch == '}' || ch == '}' || ch == '}')) {
      cout << 0;
      return 0;
    }
    if (ch == '(' || ch == '[' || ch == '{') {
      s.push(ch);
    }

    else {
      if (!s.empty() &&
          ((s.top() == '(' && ch == ')') || (s.top() == '[' && ch == ']') ||
           (s.top() == '{' && ch == '}'))) {
        s.pop();
      } else {
        cout << 0;
        return 0;
      }
    }
  }
  cout << s.empty() ? 1 : 0;
}