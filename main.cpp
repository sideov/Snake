/*
 * (c) Cranium, aka Череп. 2014
 * GNU GPL
 *
 * Game "Oldschool Snake
 * oaoaoaoa
 */

#include <iostream>
#include <conio.h>
#include "neuro.h"

#include "CScreen.h"
#include "CGame.h"

#include "functions.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");
    uint16_t neurons[4] = {16, 32, 32,4};
    NeuralNet net(4, neurons);

    /*
    string last_weights = get_last_lane("results.txt");


    istringstream act_weights(last_weights);
    double val;

    for (int layer = 0; layer < net.weights.size(); layer++) {
        for (int column = 0; column < net.weights[layer].size(); column++) {
            for (int row = 0; row < net.weights[layer][column].size(); row ++) {
                act_weights >> val;
                cout << val << "\n";
                net.weights[row][column][layer] = val;
            }
        }
    }
     */

    try {
        CScreen screen;
        screen.cursor_show(false);
        screen.text_attr((WORD)0x0a);
        screen.cls();
        CGame game(screen, 80, 24, 120);



        //game.pak(18);

        do {
            game.game_loop(net);

            ofstream F;
            F.open("results.txt", std::ios::app);
            vector<vector<vector<double>>> results  = net.weights;
            for (int layer = 0; layer < results.size(); layer++) {
                for (int column = 0; column < results[layer].size(); column++) {
                    for (int row = 0; row < results[layer][column].size(); row ++) {
                        F << results[row][column][layer] << " ";
                    }
                }
            }
            F << "\n";
            F.close();



            //game.top10(true);
        } while (true);

        game.goodbye();
    }
    catch(CSScreenException& ex) {
        cerr << "*** " << ex.what() << endl;
    }

    return 0;
}
