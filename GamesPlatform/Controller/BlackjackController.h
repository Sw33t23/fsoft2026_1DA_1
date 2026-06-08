#ifndef BLACKJACKCONTROLLER_H
#define BLACKJACKCONTROLLER_H

#include "../Model/blackjack.h"
#include "../View/BlackjackView.h"
#include "../Model/RankingModel.h"
#include <string>

class BlackjackController {
private:
    Blackjack model;
    BlackjackView view;
    std::string playerUsername;

public:
    BlackjackController(std::string username, double startingBalance);
    void playBlackjackRound(double& userBalance, RankingModel& ranking);
};

#endif