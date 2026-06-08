#include <iostream>
#include <string>
#include <vector>
#include "View/BlackjackView.h"
#include "Controller/BlackjackController.h"
#include "Model/RankingModel.h"

using namespace std;

struct User {
    string username;
    double balance = 1000.0;
};

int main() {
    vector<User> memoryDb;
    User* loggedInUser = nullptr;
    BlackjackView globalView;
    RankingModel sistemaRanking; // Instância única do ranking na memória RAM
    int choice = 0;

    while (loggedInUser == nullptr) {
        globalView.displayMenuPrincipal();
        cin >> choice;

        if (choice == 1) {
            globalView.displayCriarUtilizador();
            string newName;
            cin >> newName;

            bool exists = false;
            for (const auto& u : memoryDb) {
                if (u.username == newName) { exists = true; break; }
            }

            if (!exists) {
                memoryDb.push_back({newName, 1000.0});
                globalView.displayMensagem("Utilizador registado! Conta inicializada com $1000.");
            } else {
                globalView.displayMensagem("Erro: Esse nome de utilizador ja se encontra registado.");
            }
        }
        else if (choice == 2) {
            globalView.displayLogin();
            string loginName;
            cin >> loginName;

            for (auto& u : memoryDb) {
                if (u.username == loginName) {
                    loggedInUser = &u;
                    break;
                }
            }
            if (loggedInUser == nullptr) {
                globalView.displayMensagem("Erro: Login falhou. Nome incorreto.");
            } else {
                globalView.displayMensagem("Bem-vindo de volta, " + loggedInUser->username + "!");
            }
        }
        else if (choice == 3) {
            globalView.displayMensagem("A encerrar o sistema...");
            return 0;
        }
    }

    while (true) {
        globalView.displayHub(loggedInUser->username, loggedInUser->balance);
        cin >> choice;

        if (choice == 1) {
            globalView.displayMensagem("\nA chamar o jogo: Maior ou Menor... (Falta integrar)");
        }
        else if (choice == 2) {
            globalView.displayMensagem("\nA inicializar o modulo do Blackjack...");
            // Passa o username e a instância global de ranking
            BlackjackController blackjackCtrl(loggedInUser->username, loggedInUser->balance);
            blackjackCtrl.playBlackjackRound(loggedInUser->balance, sistemaRanking);
        }
        else if (choice == 3) {
            globalView.displayMensagem("\nA chamar o jogo: Jogo do Galo... (Falta integrar)");
        }
        else if (choice == 4) {
            globalView.displayMensagem("Sessao terminada de " + loggedInUser->username);
            loggedInUser = nullptr;

            while (loggedInUser == nullptr) {
                globalView.displayMenuPrincipal();
                cin >> choice;
                if (choice == 1) {
                    globalView.displayCriarUtilizador();
                    string newName; cin >> newName;
                    memoryDb.push_back({newName, 1000.0});
                    globalView.displayMensagem("Conta criada!");
                } else if (choice == 2) {
                    globalView.displayLogin();
                    string loginName; cin >> loginName;
                    for (auto& u : memoryDb) {
                        if (u.username == loginName) { loggedInUser = &u; break; }
                    }
                } else return 0;
            }
        }
    }
    return 0;
}