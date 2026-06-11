#include "../../Headers/Controller/BlackjackController.h"
#include <iostream>
#include <climits> // Necessário para limpar o buffer do cin

BlackjackController::BlackjackController(std::string username, double startingBalance)
    : model(startingBalance), view(), playerUsername(username) {}

void BlackjackController::playBlackjackRound(double& userBalance, Ranking& ranking) {
    bool keepPlaying = true;

    while (keepPlaying && model.getBalance() > 0) {
        // Imprime a interface estilizada de regras antes de pedir a aposta
        view.displayHands({}, 0, {}, 0, false);
        view.displaySaldo(model.getBalance());

        int bet = 0;
        while (true) {
            view.displayPedirAposta();
            std::cin >> bet;

            // PROTEÇÃO CONTRA LETRAS: Se o utilizador meter uma letra, o cin falha
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro do cin
                std::cin.ignore(INT_MAX, '\n'); // Descarta a entrada inválida do buffer
                view.displayMensagem("Erro: Por favor, introduza apenas numeros.");
                continue;
            }

            if (bet == 10 || bet == 20 || bet == 50 || bet == 100) {
                if (bet <= model.getBalance()) {
                    break;
                } else {
                    view.displayMensagem("Erro: Nao tem saldo suficiente para esta aposta.");
                }
            } else {
                view.displayMensagem("Erro: Selecione uma quantia valida (10, 20, 50, 100).");
            }
        }

        model.initializeDeck();
        model.clearHands();

        model.hitPlayer(); model.hitPlayer();
        model.hitDealer(); model.hitDealer();

        // TURNO DO JOGADOR
        while (model.calculateScore(model.getPlayerHand()) < 21) {
            view.displayHands(model.getPlayerHand(), model.calculateScore(model.getPlayerHand()),
                              model.getDealerHand(), model.calculateScore(model.getDealerHand()), true);
            view.displayOpcoesTurno();
            char choice;
            std::cin >> choice;

            if (choice == 'h' || choice == 'H') {
                model.hitPlayer();
            }
            else if (choice == 's' || choice == 'S') {
                break;
            }
            else {
                view.displayMensagem("Opcao invalida! Escolha 'h' para pedir ou 's' para parar.");
            }
        }

        int pScore = model.calculateScore(model.getPlayerHand());
        bool playerBusted = (pScore > 21);

        if (!playerBusted) {
            while (model.calculateScore(model.getDealerHand()) < 17) {
                model.hitDealer();
            }
        }

        int dScore = model.calculateScore(model.getDealerHand());

        // Revelação final das cartas e aplicação do resultado
        view.displayHands(model.getPlayerHand(), pScore, model.getDealerHand(), dScore, false);
        view.displayResultado(pScore, dScore, playerBusted, bet);

        // Atualização matemática do saldo no Modelo
        if (playerBusted) model.setBalance(model.getBalance() - bet);
        else if (dScore > 21 || pScore > dScore) model.setBalance(model.getBalance() + bet);
        else if (pScore < dScore) model.setBalance(model.getBalance() - bet);

        // Atualiza a RAM do main
        userBalance = model.getBalance();

        // MOSTRAR SALDO NO FIM DA RODADA
        view.displaySaldo(model.getBalance());

        if (model.getBalance() <= 0) {
            view.displayMensagem("Banca rota! O seu saldo chegou a 0.");
            break;
        }

        // CONTROLADOR DE CONTINUIDADE
        while (true) {
            view.displayMensagem("Quer jogar mais uma ronda? (y/n): ");
            char again;
            std::cin >> again;

            if (again == 'n' || again == 'N') {
                keepPlaying = false;
                break;
            }
            else if (again == 'y' || again == 'Y') {
                break;
            }
            else {
                view.displayMensagem("Opcao invalida! Digite 'y' para sim ou 'n' para nao.");
            }
        }
    }

    // Gravação estável no ranking antes de sair
    view.displayMensagem("\nA atualizar o teu registo no Ranking Global do Blackjack...");
    ranking.atualizarBlackjack(playerUsername, static_cast<int>(model.getBalance()));
    view.displayMensagem("Ranking atualizado com sucesso!");
    view.displayMensagem("\nA sair do Blackjack... A redirecionar para o Menu Principal.");
}