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

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");
    uint16_t neurons[4] = {16, 32, 32,4};
    NeuralNet net(4, neurons);

    try {
        CScreen screen;
        screen.cursor_show(false);
        screen.text_attr((WORD)0x0a);
        screen.cls();
        CGame game(screen, 80, 24, 120);



        //game.pak(18);

        do {
            game.game_loop(net);
            //vector<vector<double>> first_layer = net.weights[0];
            //for (int row = 0, row < first_layer[0].size())

            //game.top10(true);
        } while (true);

        game.goodbye();
    }
    catch(CSScreenException& ex) {
        cerr << "*** " << ex.what() << endl;
    }

    return 0;
}
