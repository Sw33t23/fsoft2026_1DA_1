//
// Created by andre on 30/05/2026.
//

#include "../Controller/controller.h"
#include <iostream>

using namespace std;

MaiorOuMenorController::MaiorOuMenorController(){
}

void MaiorOuMenorController::playGame()
{
    this->game.iniciarJogoNovo();

    cout << "==== JOGO: MAIOR OU MENOR ====" << endl;
    cout << "==== Regras: ====" << endl;
    cout << "- Deve adivinhar um número aleatório de 1 a 100" << endl;
    cout << "- Serão contadas as tentativas que precisou para acertar" << endl;

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
                cout << "O teu palpite está ACIMA do número!" << endl;
            }
            if (estadoJogo == -1)
            {
                cout << "O teu palpite está ABAIXO do número!" << endl;
            }
        }
        catch ( const std::exception &e )
        {
            cout << "AVISO! " << e.what() << endl;
        }
    }

    cout << "\n PARABÉNS! Adivinhaste o número secreto!" << endl;
    cout << "Tentantivas realizadas: " << this->game.getTentativasAtuais() << endl;
}
