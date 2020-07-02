#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <time.h>
#include <conio.h>

using namespace std;


int dice[5] = {
    rand() % 6 + 1,
    rand() % 6 + 1,
    rand() % 6 + 1,
    rand() % 6 + 1,
    rand() % 6 + 1 };

int held_dice[5] = {
    0,
    0,
    0,
    0,
    0

};

bool holds[5] = {
    false,
    false,
    false,
    false,
    false
};

std::map<string, int> scores;



int hold_iterator = 0;


void roll() {
    for (int x = 0; x < 5; x++) {
        held_dice[x] = dice[x];
    }
}

void holdit() {
    for (int x = 0; x < 5; x++) {
        cout << held_dice[x];
    }
    cout << endl;
    cout <<"_____" << endl;
    for (int x = 0; x < 5; x++) {
        cout << "Die " << x + 1 << ": hold the " << held_dice[x] << "? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            holds[x] = true;
        }
        else if (choice == 'n') {
            holds[x] = false;
        }
        else {
            printf("invalid choice: dice will be held");
            holds[x] = true;
        }
    }
    for (int y = 0; y < 5; y++) {
        if (holds[y] == false) {
            held_dice[y] = rand() % 6 + 1;
        }
    }
}

bool scoring() {

    int temp_score = 0;
    std::map<string, int> ::iterator it = scores.begin();
    for (std::pair<string, int> element : scores) {
        //for (auto& x : scores) {
          //  string first = x.first;
            //int second = x.second;
        if (element.second == -1) {
            cout.setf(ios::left);
            cout.width(18);
            cout << element.first;
            cout << "| __" << endl;
        }
        else {
            cout.setf(ios::left);
            cout.width(18);
            cout << element.first;
            cout << "| " << element.second << endl;
        }
    }

        int choice;
        cout << "Select a number to choose where to score: ";
        cin >> choice;

        if ((choice == 1) && (scores[" 1_ones"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 1) {
                    temp_score += 1;
                }
            }
            scores[" 1_ones"] = temp_score;
        }
        else if ((choice == 2) && (scores[" 2_twos"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 2) {
                    temp_score += 2;
                }
            }
            scores[" 2_twos"] = temp_score;
        }
        else if ((choice == 3) && (scores[" 3_threes"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 3) {
                    temp_score += 3;
                }
            }
            scores[" 3_threes"] = temp_score;
        }
        else if ((choice == 4) && (scores[" 4_fours"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 4) {
                    temp_score += 4;
                }
            }
            scores[" 4_fours"] = temp_score;
        }
        else if ((choice == 5) && (scores[" 5_fives"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 5) {
                    temp_score += 5;
                }
            }
            scores[" 5_fives"] = temp_score;
        }
        else if ((choice == 6) && (scores[" 6_sixes"] == -1)) {
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 6) {
                    temp_score += 6;
                }
            }
            scores[" 6_sixes"] = temp_score;
        }
        else if ((choice == 7) && (scores[" 7_three_of_kind"] == -1)) {
            for (int x = 1; x < 7; x++) {
                if (std::count(held_dice, held_dice + 6, held_dice[x]) >= 3) {
                    scores[" 7_three_of_kind"] = std::accumulate(held_dice, held_dice + 5, 0);
                }
                else if (scores[" 7_three_of_kind"] == -1) {
                    scores[" 7_three_of_kind"] = 0;
                }
            }
        }
        else if ((choice == 8) && (scores[" 8_four_of_kind"] == -1)) {
            for (int x = 1; x < 7; x++) {
                if (std::count(held_dice, held_dice + 6, held_dice[x]) >= 4) {
                    scores[" 8_four_of_kind"] = std::accumulate(held_dice, held_dice + 5, 0);
                }
                else if (scores[" 8_four_of_kind"] == -1) {
                    scores[" 8_four_of_kind"] = 0;
                }
            }
        }
        else if ((choice == 9) && (scores[" 9_full_house"] == -1)) {
            bool check_2 = false;
            bool check_3 = false;
            for (int x = 1; x < 7; x++) {
                if (std::count(held_dice, held_dice + 6, held_dice[x]) == 2) {
                    check_2 = true;
                }
                else if (std::count(held_dice, held_dice + 6, held_dice[x]) == 3) {
                    check_3 = true;
                }
                if ((check_2) && (check_3)) {
                    scores[" 9_full_house"] = 25;
                }
                else
                {
                    scores[" 9_full_house"] = 0;
                }

            }
        }
        else if ((choice == 10) && (scores["10_small_straight"] == -1)) {
            bool one = false;
            bool two = false;
            bool three = false;
            bool four = false;
            bool five = false;
            bool six = false;
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 1) {
                    one = true;
                }
                else if (held_dice[x] == 2) {
                    two = true;
                }
                else if (held_dice[x] == 3) {
                    three = true;
                }
                else if (held_dice[x] == 4) {
                    four = true;
                }
                else if (held_dice[x] == 5) {
                    five = true;
                }
                else if (held_dice[x] == 6) {
                    six = true;
                }
                if (((one && (two) && (three) && four) || ((two) && (three) && (four) && (five)) || ((three) && (four) && (five) && (six)))) {
                    scores["10_small_straight"] = 30;
                }
                else {
                    scores["10_small_straight"] = 0;
                }
            }
        }
        else if ((choice == 11) && (scores["11_large_straight"] == -1)) {
            bool one = false;
            bool two = false;
            bool three = false;
            bool four = false;
            bool five = false;
            bool six = false;
            for (int x = 0; x < 5; x++) {
                if (held_dice[x] == 1) {
                    one = true;
                }
                else if (held_dice[x] == 2) {
                    two = true;
                }
                else if (held_dice[x] == 3) {
                    three = true;
                }
                else if (held_dice[x] == 4) {
                    four = true;
                }
                else if (held_dice[x] == 5) {
                    five = true;
                }
                else if (held_dice[x] == 6) {
                    six = true;
                }
            }
            if (((one) && (two) && (three) && (four) && (five)) || ((two) && (three) && (four) && (five) && (six))) {
                scores["11_large_straight"] = 40;
            }
            else {
                scores["11_large_straight"] = 0;
            }
        }
        else if ((choice == 12) && (scores["12_yahtzee"] == -1)) {

            if (std::count(held_dice, held_dice + 6, held_dice[0]) >= 5) {
                scores["12_yahtzee"] = 50;
            }
            else if (scores["12_yahtzee"] == -1) {
                scores["12_yahtzee"] = 0;
            }

        }
        else if ((choice == 12) && (scores["12_yahtzee"] == 50) && (scores["yahtzee_bonus"] == 0)) {
            if (std::count(held_dice, held_dice + 6, held_dice[0]) >= 5) {
                scores["yahtzee_bonus"] = 100;
            }
            else {
                scores["yahtzee_bonus"] = 0;
            }
        }
        else if ((choice == 13) && (scores["13_chance"] == -1)) {
            scores["13_chance"] = std::accumulate(held_dice, held_dice + 5, 0);
        }
        else {
            cout << "invalid selection";
            return false;
        }

        int bonus_check = scores[" 1_ones"] + scores[" 2_twos"] + scores[" 3_threes"] + scores[" 4_fours"] + scores[" 5_fives"] + scores[" 6_sixes"];
        if (bonus_check >= 63) {
            scores["upper_bonus"] = 35;
        }
        for (auto& x : scores) {
            string first = x.first;
            int second = x.second;
            if (x.second == -1) {
                cout.setf(ios::left);
                cout.width(18);
                cout << first.c_str();
                cout << "| __" << endl;

            }
            else {
                cout.setf(ios::left);
                cout.width(18);
                cout << first.c_str();
                cout << "| " << second << endl;

            }
        }
            return true;
        
    }








int main()
{
    srand(time(0));
    for (int x = 0; x < 5; x++) {
        dice[x] = rand() % 6 + 1;
    }
    scores.insert(pair<string, int>(" 1_ones", -1));
    scores.insert(pair<string, int>(" 2_twos", -1));
    scores.insert(pair<string, int>(" 3_threes", -1));
    scores.insert(pair<string, int>(" 4_fours", -1));
    scores.insert(pair<string, int>(" 5_fives", -1));
    scores.insert(pair<string, int>(" 6_sixes", -1));
    scores.insert(pair<string, int>(" 7_three_of_kind", -1));
    scores.insert(pair<string, int>(" 8_four_of_kind", -1));
    scores.insert(pair<string, int>(" 9_full_house", -1));
    scores.insert(pair<string, int>("10_small_straight", -1));
    scores.insert(pair<string, int>("11_large_straight", -1));
    scores.insert(pair<string, int>("12_yahtzee", -1));
    scores.insert(pair<string, int>("13_chance", -1));
    scores.insert(pair<string, int>("upper_bonus", 0));
    scores.insert(pair<string, int>("yahtzee_bonus", 0));

    bool finish_test = false;
    while (finish_test == false) {
        if ((scores[" 1_ones"] >= 0) && (scores[" 2_twos"] >= 0) && (scores[" 3_threes"] >= 0) && (scores[" 4_fours"] >= 0) && (scores[" 5_fives"] >= 0) && (scores[" 6_sixes"] >= 0) && (scores[" 7_three_of_kind"] >= 0) &&
            (scores[" 8_four_of_kind"] >= 0) && (scores[" 9_full_house"] >= 0) && (scores["10_small_straight"] >= 0) && (scores["11_large_straight"] >= 0) && (scores["12_yahtzee"] >= 0) && (scores["13_chance"] >= 0)) {
            break;
        }

        printf(" ");
        roll();
        while (hold_iterator < 2) {
            holdit();
            if ((holds[0] == true) && (holds[1] == true) && (holds[2] == true) && (holds[3] == true) && (holds[4] == true)) {
                hold_iterator = 2;
            }
            hold_iterator++;
        }


        cout << " ";
        cout << held_dice[0] << held_dice[1] << held_dice[2] << held_dice[3] << held_dice[4] << std::endl;
        cout << "__________" << std::endl;


        bool score_test = false;
        while (score_test == false) {
            score_test = scoring();
            hold_iterator = 0;
            for (int x = 0; x < 5; x++) {
                holds[x] = false;
            }
            for (int x = 0; x < 5; x++) {
                dice[x] = rand() % 6 + 1;
            }
        }
    }
        int score = scores[" 1_ones"] + scores[" 2_twos"] + scores[" 3_threes"] + scores[" 4_fours"] + scores[" 5_fives"] + scores[" 6_sixes"] + scores[" 7_three_of_kind"] + scores[" 8_four_of_kind"] +
            scores[" 9_full_house"] + scores["10_small_straight"] + scores["11_large_straight"] + scores["12_yahtzee"] + scores["13_chance"];
        
        
        cout << "Final Score =" << score;



    

}