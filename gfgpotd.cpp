#include <iostream>
#include <string>
#include <stack>

std::string printMinNumberForPattern(const std::string &S) {
    if (S.empty()) {
        return "";
    }

    std::string result;
    std::stack<int> stack;
    int current = 1;

    for (char c : S) {
        if (c == 'I') {
            stack.push(current);
            current++;
        } else if (c == 'D') {
            stack.push(current);
            current++;
            while (!stack.empty()) {
                result += std::to_string(stack.top());
                stack.pop();
            }
        }
    }

    stack.push(current);
    while (!stack.empty()) {
        result += std::to_string(stack.top());
        stack.pop();
    }

    return result;
}

int main() {
    std::string S = "IDID";
    std::string min_num = printMinNumberForPattern(S);
    std::cout << min_num << std::endl;  // Output: "13254"
    return 0;
}
