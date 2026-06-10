#ifndef BLACKJACKCONTROLLER_H
#define BLACKJACKCONTROLLER_H

#include "../Model/Blackjack.h"
#include "../View/BlackjackView.h"
#include "../Model/Ranking.h"
#include <string>

class BlackjackController {
private:
    Blackjack model;
    BlackjackView view;
    std::string playerUsername;

public:
    BlackjackController(std::string username, double startingBalance);
    void playBlackjackRound(double& userBalance, Ranking& ranking);
};

#endif