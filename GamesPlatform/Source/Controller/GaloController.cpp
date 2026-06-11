#include "../../Headers/Controller/GaloController.h"

GaloController::GaloController() : model(nullptr) {}

GaloController::~GaloController() {
    delete model;
}

void GaloController::iniciarJogo() {
    // 1. Inicializa o Model através da escolha feita na View
    char escolha = view.pedirSimboloJogador();
    model = new Galo(escolha);

    view.mostrarMensagem("\n--- O Jogo Comecou! ---");
    view.mostrarTabuleiro(model->getTabuleiro());

    // 2. Loop principal do Jogo
    while (model->jogoAtivo()) {
        // Turno do Jogador
        bool jogadaValida = false;
        while (!jogadaValida) {
            std::pair<int, int> jogada = view.pedirJogada();
            jogadaValida = model->validarEJogar(jogada.first, jogada.second);
            if (!jogadaValida) {
                view.mostrarMensagem("Jogada invalida! Tente novamente.");
            }
        }

        view.mostrarTabuleiro(model->getTabuleiro());

        // Verifica se o jogador ganhou ou empatou após a sua jogada
        if (!model->jogoAtivo()) break;

        // Turno da IA
        view.mostrarMensagem("Computador a pensar...");
        model->jogarComputador();
        view.mostrarTabuleiro(model->getTabuleiro());
    }

    // 3. Fim do Jogo e Atualização de Pontuação
    char res = model->verificarResultado();
    if (res == 'J') {
        model->incrementarVitorias();
    }
    
    view.mostrarResultado(res, model->getVitorias());
}