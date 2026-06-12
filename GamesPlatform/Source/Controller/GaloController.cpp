#include "../../Headers/Controller/GaloController.h"
#include <iostream>

GaloController::GaloController(Jogador* jogador, Ranking* r)
    : model(nullptr), jogadorAtivo(jogador), ranking(r) {}

GaloController::~GaloController() {
    delete model;
}

void GaloController::iniciarJogo() {
    bool keepPlaying = true;

    while (keepPlaying) {
        if (model != nullptr) {
            delete model;
            model = nullptr;
        }

        char escolha = view.pedirSimboloJogador();
        model = new Galo(escolha);

        view.mostrarMensagem("\n--- O Jogo Comecou! ---");
        view.mostrarTabuleiro(model->getTabuleiro());

        while (model->jogoAtivo()) {
            bool jogadaValida = false;
            while (!jogadaValida) {
                std::pair<int, int> jogada = view.pedirJogada();
                jogadaValida = model->validarEJogar(jogada.first, jogada.second);
                if (!jogadaValida) {
                    view.mostrarMensagem("Jogada invalida! Tente novamente.");
                }
            }

            view.mostrarTabuleiro(model->getTabuleiro());

            if (!model->jogoAtivo()) break;

            view.mostrarMensagem("\nComputador a pensar...");
            model->jogarComputador();
            view.mostrarTabuleiro(model->getTabuleiro());
        }

        char res = model->verificarResultado();
        if (res == 'J') {
            model->incrementarVitorias();
            ranking->atualizarGalo(jogadorAtivo->username, model->getVitorias());
        }

        view.mostrarResultado(res, model->getVitorias());

        while (true) {
            std::cout << "Quer jogar mais uma ronda? (y/n): ";
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
                std::cout << "Opcao invalida! Digite 'y' para sim ou 'n' para nao.\n\n";
            }
        }
    }
}