#include "../../Headers/Controller/JogadorController.h"
#include "../../Headers/Exception/Exception.h"
#include "../../Headers/Model/Jogador.h"
#include <iostream>

JogadorController::JogadorController(JogadorService& service) : service(service) {}

Jogador* JogadorController::correrMenuAutenticacao() {
    Jogador* jogadorAtivo = nullptr;

    while (jogadorAtivo == nullptr) {
        int opcao = view.pedirOpcaoMenuPrincipal();

        switch (opcao) {
            case 1: {
                Jogador* jogadorLogado = fluxoRegisto();
                if (jogadorLogado != nullptr) {
                    jogadorAtivo = jogadorLogado;
                }
                break;
            }
            case 2:
                jogadorAtivo = fluxoLogin();
                break;

            case 3:
                view.mostrarSucesso("A encerrar o sistema...");
                return nullptr;

            default:
                view.mostrarErro("Opcao invalida. Tente novamente.");
                break;
        }
    }

    return jogadorAtivo;
}

Jogador* JogadorController::fluxoRegisto() {
    try {
        RegistoDTO dados = view.pedirDadosRegisto();
        service.registarJogador(dados);
        view.mostrarSucesso("Conta criada com sucesso!");

        LoginDTO loginDados;
        loginDados.username = dados.username;
        loginDados.password = dados.password;

        Jogador* jogador = service.autenticar(loginDados);
        view.mostrarPerfil(jogador->username, jogador->saldo);
        return jogador;
    } catch (const InvalidDataException& e) {
        view.mostrarErro(e.what());
    } catch (const DuplicatePlayerException& e) {
        view.mostrarErro(e.what());
    }
    return nullptr;
}

Jogador* JogadorController::fluxoLogin() {
    try {
        LoginDTO dados = view.pedirDadosLogin();
        Jogador* jogador = service.autenticar(dados);
        view.mostrarPerfil(jogador->username, jogador->saldo);
        return jogador;
    } catch (const InvalidLoginException& e) {
        view.mostrarErro(e.what());
        return nullptr;
    }
}
