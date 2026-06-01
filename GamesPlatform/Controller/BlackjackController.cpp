#include "BlackjackController.h"
#include <iostream>

BlackjackController::BlackjackController(double startingBalance) : model(startingBalance), view() {}

void BlackjackController::playBlackjackRound(double& userBalance) {
    bool keepPlaying = true;

    while (keepPlaying && model.getBalance() > 0) {
        int bet = 0;
        while (true) {
            view.displaySaldo(model.getBalance());
            view.displayPedirAposta();
            std::cin >> bet;

            if (bet == 10 || bet == 20 || bet == 50 || bet == 100) {
                if (bet <= model.getBalance()) break;
                else view.displayMensagem("Erro: Nao tem saldo suficiente para esta aposta.");
            } else {
                view.displayMensagem("Erro: Quantia invalida.");
            }
        }

        model.initializeDeck();
        model.clearHands();

        model.hitPlayer(); model.hitPlayer();
        model.hitDealer(); model.hitDealer();

        while (model.calculateScore(model.getPlayerHand()) < 21) {
            view.displayHands(model.getPlayerHand(), model.calculateScore(model.getPlayerHand()),
                              model.getDealerHand(), model.calculateScore(model.getDealerHand()), true);
            view.displayOpcoesTurno();
            char choice;
            std::cin >> choice;

            if (choice == 'h') model.hitPlayer();
            else break;
        }

        int pScore = model.calculateScore(model.getPlayerHand());
        bool playerBusted = (pScore > 21);

        if (!playerBusted) {
            while (model.calculateScore(model.getDealerHand()) < 17) {
                model.hitDealer();
            }
        }

        int dScore = model.calculateScore(model.getDealerHand());
        view.displayHands(model.getPlayerHand(), pScore, model.getDealerHand(), dScore, false);
        view.displayResultado(pScore, dScore, playerBusted, bet);

        if (playerBusted) model.setBalance(model.getBalance() - bet);
        else if (dScore > 21 || pScore > dScore) model.setBalance(model.getBalance() + bet);
        else if (pScore < dScore) model.setBalance(model.getBalance() - bet);

        userBalance = model.getBalance();

        if (model.getBalance() <= 0) {
            view.displayMensagem("Banca rota! O seu saldo chegou a 0.");
            break;
        }

        view.displayMensagem("\nQuer jogar mais uma ronda? (y/n): ");
        char again;
        std::cin >> again;
        if (again != 'y') keepPlaying = false;
    }
}