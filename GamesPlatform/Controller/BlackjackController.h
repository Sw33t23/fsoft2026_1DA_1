#ifndef BLACKJACKCONTROLLER_H
#define BLACKJACKCONTROLLER_H

#include "../blackjack/blackjack.h"
#include "../View/BlackjackView.h"

class BlackjackController {
private:
    Blackjack model;
    BlackjackView view;

public:
    BlackjackController(double startingBalance);
    void playBlackjackRound(double& userBalance);
};

#endif