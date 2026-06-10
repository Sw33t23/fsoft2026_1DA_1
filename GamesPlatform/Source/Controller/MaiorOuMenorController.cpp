//
// Created by andre on 30/05/2026.
//

#include "../Controller/MaiorOuMenorController.h"
#include "../Model/RankingModel.h"
#include <exception>
#include "MenorOuMaiorView.h"

using namespace std;

MaiorOuMenorController::MaiorOuMenorController(Jogador *jogadorAutenticado, RankingModel *ranking){
    this->loggedClient = jogadorAutenticado;
    this->ranking = ranking;
}

void MaiorOuMenorController::playGame()
{
    MenorOuMaiorView view;

    game.iniciarJogoNovo();
    view.mostrarInstrucoes();

    bool acertou = false;

    while (!acertou)
    {
        int palpite = view.pedirPalpite();
        try
        {
            int resultado = game.verificarPalpite(palpite);

            if (resultado == 0)
            {
                int recordeAntigo = loggedClient->leastTrys;
                loggedClient->setLeastTrys(game.getTentativasAtuais());

                ranking->atualizarMaiorMenor(loggedClient->username, game.getTentativasAtuais());

                view.mostrarResultadoFinal(game.getTentativasAtuais(), recordeAntigo);
                acertou = true;
            }
            else
            {
                view.mostrarFeedbackPalpite(resultado);
                view.mostrarTentativas(game.getTentativasAtuais());
            }
        }
        catch (const InvalidDataException &e) 
        {
            view.mostrarAviso(e.what()); 
        }
        catch (const exception &e)
        {
            view.mostrarAviso(e.what());
        }
    }
}
