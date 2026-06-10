#include "../../Headers/Controller/RankingController.h"

void RankingController::registarBlackjack(const std::string& username, int saldo) {
    model.atualizarBlackjack(username, saldo);
}

void RankingController::registarGalo(const std::string& username, int vitorias_consecutivas) {
    model.atualizarGalo(username, vitorias_consecutivas);
}

void RankingController::registarMaiorMenor(const std::string& username, int tentativas) {
    model.atualizarMaiorMenor(username, tentativas);
}

void RankingController::consultarRanking() {
    int opcao = -1;

    while (opcao != 0) {
        opcao = view.pedirOpcaoMenu();

        if (opcao == 1) {
            view.exibirTop10(model.getBlackjack(),"Blackjack","Saldo");
        } else if (opcao == 2) {
            view.exibirTop10(model.getGalo(),"Galo","Streak");
        } else if (opcao == 3) {
            view.exibirTop10(model.getMaiorMenor(),"Maior ou Menor","Tentativas");
        } else if (opcao == 0) {
            view.mostrarAVoltar();
        } else {
            view.mostrarOpcaoInvalida();
        }
    }
}
