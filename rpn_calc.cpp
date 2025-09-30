#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

class RPNCalculator {
public:
    void clear() { while (!st.empty()) st.pop(); }

    void show() const {
        stack<double> tmp = st;
        cout << "[栈顶] ";
        while (!tmp.empty()) {
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << "[栈底]" << endl;
    }

    double eval(const string& expr) {
        istringstream iss(expr);
        string token;
        while (iss >> token) {
            if (token == "clear") { clear(); }
            else if (token == "stack") { show(); }
            else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                if (st.size() < 2) throw runtime_error("操作数不足");
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") {
                    if (b == 0) throw runtime_error("除零错误");
                    st.push(a / b);
                }
                else if (token == "^") {
                    st.push(pow(a, b));
                }
            }
            else {
                try {
                    double num = stod(token);
                    st.push(num);
                } catch (...) {
                    throw runtime_error("未知符号: " + token);
                }
            }
        }
        if (st.empty()) throw runtime_error("表达式无结果");
        return st.top();
    }

private:
    stack<double> st;
};

int main() {
    RPNCalculator calc;
    string line;
    cout << "RPN 计算器 (输入 q 退出)" << endl;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line == "q" || line == "quit" || line == "exit") break;
        try {
            double result = calc.eval(line);
            cout << "结果: " << result << endl;
        } catch (const exception& e) {
            cout << "错误: " << e#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

class RPNCalculator {
public:
    void clear() { while (!st.empty()) st.pop(); }

    void show() const {
        stack<double> tmp = st;
        cout << "[栈顶] ";
        while (!tmp.empty()) {
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << "[栈底]" << endl;
    }

    double eval(const string& expr) {
        istringstream iss(expr);
        string token;
        while (iss >> token) {
            if (token == "clear") { clear(); }
            else if (token == "stack") { show(); }
            else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                if (st.size() < 2) throw runtime_error("操作数不足");
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") {
                    if (b == 0) throw runtime_error("除零错误");
                    st.push(a / b);
                }
                else if (token == "^") {
                    st.push(pow(a, b));
                }
            }
            else if (token == "sqrt") {
                if (st.size() < 1) throw runtime_error("操作数不足");
                double a = st.top(); st.pop();
                if (a < 0) throw runtime_error("平方根不能是负数");
                st.push(sqrt(a));
            }
            else {
                try {
                    double num = stod(token);
                    st.push(num);
                } catch (...) {
                    throw runtime_error("未知符号: " + token);
                }
            }
        }
        if (st.empty()) throw runtime_error("表达式无结果");
        return st.top();
    }

private:
    stack<double> st;
};

int main() {
    RPNCalculator calc;
    string line;
    cout << "RPN 计算器 (输入 q 退出)" << endl;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line == "q" || line == "quit" || line == "exit") break;
        try {
            double result = calc.eval(line);
            cout << "结果: " << result << endl;
        } catch (const exception& e) {
            cout << "错误: " << e.what() << endl;
        }
    }
    return 0;
}
.what() << endl;
        }
    }
    return 0;
}

