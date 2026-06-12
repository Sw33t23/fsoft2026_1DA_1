#include "../../Headers/Controller/GaloController.h"

GaloController::GaloController(Jogador* jogador, Ranking* r)
    : model(nullptr), jogadorAtivo(jogador), ranking(r) {}

GaloController::~GaloController() {
    delete model;
}

void GaloController::iniciarJogo() {
    bool jogarNovamente = true;

    while (jogarNovamente) {
        char escolha = view.pedirSimboloJogador();
        delete model;
        model = new Galo(escolha);

        view.mostrarMensagem("\n--- O Jogo Comecou! ---");
        view.mostrarTabuleiro(model->getTabuleiro());

        while (model->jogoAtivo()) {
            bool jogadaValida = false;
            while (!jogadaValida) {
                std::pair<int, int> jogada = view.pedirJogada();
                jogadaValida = model->validarEJogar(jogada.first, jogada.second);
                if (!jogadaValida)
                    view.mostrarMensagem("Jogada invalida! Tente novamente.");
            }

            view.mostrarTabuleiro(model->getTabuleiro());

            if (!model->jogoAtivo()) break;

            view.mostrarMensagem("Computador a pensar...");
            model->jogarComputador();
            view.mostrarTabuleiro(model->getTabuleiro());
        }

        char res = model->verificarResultado();

        if (res == 'J') {
            jogadorAtivo->streakGalo++;
            ranking->atualizarGalo(jogadorAtivo->username, jogadorAtivo->streakGalo);
        } else if (res == 'I') {
            jogadorAtivo->streakGalo = 0;
        }

        view.mostrarResultado(res, jogadorAtivo->streakGalo);

        jogarNovamente = view.perguntarJogarNovamente();
    }
}