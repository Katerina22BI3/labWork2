#include <iostream>
#include <stack>
#include <sstream>
#include <string>

int postfixMath(std::string expression) {
    std::stack<int> operands;
    std::string curOper; //для чтения строчки после её разделения

    std::stringstream spltStr(expression); //принимает нашу введённую строку и разбивает её на "слова"

    while (spltStr >> curOper) {
        if (curOper == "+") {
            int oper2 = operands.top();
            operands.pop();
            int oper1 = operands.top();
            operands.pop();
            operands.push(oper1 + oper2);
        }
        else if (curOper == "-") {
            int oper2 = operands.top();
            operands.pop();
            int oper1 = operands.top();
            operands.pop();
            operands.push(oper1 - oper2);
        }
        else if (curOper == "*") {
            int oper2 = operands.top();
            operands.pop();
            int oper1 = operands.top();
            operands.pop();
            operands.push(oper1 * oper2);
        }
        else {
            operands.push(stoi(curOper)); //нашли число, добавим его в стек, преобразовав в int 
        }
    }
    return operands.top();
}

int main()
{
    std::string expression;
    getline(std::cin, expression); //сохраняет введённую строчку с клавиатуры в переменную expression

    int res = postfixMath(expression);

    std::cout << res << std::endl;
}
