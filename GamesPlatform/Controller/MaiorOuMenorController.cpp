//
// Created by andre on 30/05/2026.
//

#include "../Controller/MaiorOuMenorController.h"
#include "../Ranking/Ranking.h"
#include <iostream>

using namespace std;

MaiorOuMenorController::MaiorOuMenorController(Jogador *jogadorAutenticado){
    this->loggedClient = jogadorAutenticado;
}

void MaiorOuMenorController::playGame()
{
    this->game.iniciarJogoNovo();

    cout << "==== MAIOR OU MENOR ====" << endl;
    cout << "REGRAS:" << endl;
    cout << "- Deve adivinhar um numero aleatorio de 1 a 100" << endl;
    cout << "- Serao contadas as tentativas que precisou para acertar" << endl;

    int estadoJogo = -1;
    int palpite;

    while (estadoJogo != 0)
    {
        cout << "\nIntroduz o teu palpite: ";
        cin >> palpite;

        try
        {
            estadoJogo = this->game.verificarPalpite(palpite);

            if (estadoJogo == 1)
            {
                cout << "O teu palpite esta ACIMA do numero!" << endl;
            }
            if (estadoJogo == -1)
            {
                cout << "O teu palpite esta ABAIXO do numero!" << endl;
            }
        }
        catch ( const std::exception &e )
        {
            cout << "AVISO! " << e.what() << endl;
        }
    }

    cout << "\n PARABENS! Adivinhaste o numero secreto!" << endl;

    int totalTentativas = this->game.getTentativasAtuais();
    cout << "Tentantivas realizadas: " << this->game.getTentativasAtuais() << endl;
    this->loggedClient->setLeastTrys(totalTentativas);
    Ranking sistemaRanking;
    sistemaRanking.atualizarMaiorMenor(this->loggedClient->username, this->loggedClient->leastTrys);
    cout << "Recorde Pessoal: " << this->loggedClient->leastTrys << endl;
}
