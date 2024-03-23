#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    // ключ - это номер класса,значение - вектор фамилии
    map<int, vector<string>> class_name;

    // ввод и чтение данных
    int class_num;
    string name;
    while (cin >> class_num >> name) {
        class_name[class_num].push_back(name);
    }

    //вывод фамилий по порядку классов
    for (const auto& student : class_name) {
        for (const string& student_name : student.second) {
            cout << student.first << " " << student_name << endl;
        }
    }

    return 0;
}
