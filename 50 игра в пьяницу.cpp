#include <iostream>
#include <deque>

void game(std::deque<int>& player1, std::deque<int>& player2) {
    int step = 0;
    
    while (step <= 1000000 && player1.size() > 0 && player2.size() > 0) {
        step++;
        int card11 = player1.front();
        int card21 = player2.front();
        player1.erase(player1.begin());
        player2.erase(player2.begin());

        if (card11 == 0 && card21 == 9) {
            player1.push_back(card11);
            player1.push_back(card21);
        }
        else if (card21 == 0 && card11 == 9) {
            player2.push_back(card11);
            player2.push_back(card21);
        }
        else if (card11 > card21) {
            player1.push_back(card11);
            player1.push_back(card21);
        }
        else if (card11 < card21) {
            player2.push_back(card11);
            player2.push_back(card21);
        }
    }

    if (player1.size() == 0) {
        std::cout << "second " << step << std::endl;
    }
    else if (player2.size() == 0) {
        std::cout << "first " << step << std::endl;
    }
    else {
        std::cout << "botva" << std::endl;
    }
}


int main()
{
    std::deque<int> player1(5);
    std::deque<int> player2(5);

    for (int i = 0; i < 5; i++) {
        std::cin >> player1[i];
    }


    for (int i = 0; i < 5; i++) {
        std::cin >> player2[i];
    }

    game(player1, player2);
    
    return 0;
}