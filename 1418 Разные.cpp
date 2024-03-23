#include <iostream>
#include <set>

int main()
{
    int N;
    std::cin >> N;

    std::set<int> numbers;

    for (int n = 0; n < N; n++) {
        int nums;
        std::cin >> nums;
        numbers.insert(nums);
    }

    std::cout << numbers.size() << std::endl;

    return 0;
}