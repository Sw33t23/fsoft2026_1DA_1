//
// Created by andre on 30/05/2026.
//

#include "../../Headers/Controller/MaiorOuMenorController.h"
#include "../../Headers/Model/Ranking.h"
#include <exception>
#include "../../Headers/Exception/Exception.h"
#include "../../Headers/View/MaiorOuMenorView.h"

using namespace std;

MaiorOuMenorController::MaiorOuMenorController(Jogador *jogadorAutenticado, Ranking *ranking){
    this->loggedClient = jogadorAutenticado;
    this->ranking = ranking;
}

void MaiorOuMenorController::playGame()
{
    MaiorOuMenorView view;
    bool keepPlaying = true;

    while (keepPlaying)
    {
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

        while (true)
        {
            cout << ("\nQuer jogar mais uma ronda? (y/n): ");
            char again;
            cin >> again;

            if (again == 'n' || again == 'N') {
                keepPlaying = false;
                break;
            }
            else if (again == 'y' || again == 'Y') {
                break;
            }
            else {
                view.mostrarAviso("Opcao invalida! Digite 'y' para sim ou 'n' para nao.");
            }
        }
    }
}