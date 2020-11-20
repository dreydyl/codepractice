#include <iostream>
#include <stack>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

bool isValid(std::string s) {
  std::stack<char> st;
  if(s.empty()) return true;
  if(s.size()%2 == 1) return false;
  if(s.at(0) == ')' || s.at(0) == '}' || s.at(0) == ']') return false;
  if(s.at(s.size()-1) == '(' || s.at(s.size()-1) == '{' || s.at(s.size()-1) == '[') return false;
    for(int i = 0;i < s.size();i++){
      if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '['){
        st.push(s.at(i));
      }
      else if(st.empty()){
        return false;
      }
        else if(st.top() == '(' && s.at(i) != ')') return false;
        else if(st.top() == '{' && s.at(i) != '}') return false;
        else if(st.top() == '[' && s.at(i) != ']') return false;
        else st.pop();
    }
    return true;
}

int main() {
  std::cout << isValid("(())");
  std::cout << isValid("[()]");
  std::cout << isValid("{[])");
  std::cout << isValid("");
  std::cout << isValid("(())[]");
  std::cout << isValid("(");
  std::cout << isValid(")");
}

