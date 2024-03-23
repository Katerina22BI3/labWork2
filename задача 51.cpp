#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

bool checker(const string& s) {
    //  функция принимает строку s - скобочную последовательность и возвращает true, если последовательность правильная
    unordered_map<char, char> brackets = { {')', '('}, {']', '['}, {'}', '{'} }; //пары ключ-значение скобок
    stack<char> st; //хранит открывающую скобку

    for (char ch : s) {
        //если текущий символ это ключ, т.е. закрывающая скобка
        if (brackets.count(ch)) {
            // если стек пуст или верхний элемент стека не подходит открывающей скобке
            if (st.empty() || st.top() != brackets[ch]) {
                return false; 
            }
            st.pop(); //удалить открывающую скобку из стека, скобки проверены
        }
        else {
            // добавляем открывающую скобку в стек
            st.push(ch);
        }
    }

    //стек пуст - скобки корректно закрыты
    return st.empty();
}

int main() {
    string sequence;
    getline(cin, sequence);

    if (checker(sequence)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}
