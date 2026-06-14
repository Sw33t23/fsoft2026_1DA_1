#include <gtest/gtest.h>
#include "Service/JogadorService.h"
#include "Container/JogadorContainer.h"

class JogadorServiceTest : public ::testing::Test {
protected:
    JogadorContainer container;
    JogadorService service{container};
};

TEST_F(JogadorServiceTest, RegisterEmptyUsername) {
    RegistoDTO dto{"", "1234"};

    EXPECT_THROW(service.registarJogador(dto), std::exception);
}

TEST_F(JogadorServiceTest, RegisterShortPassword) {
    RegistoDTO dto{"andre", "123"};
    EXPECT_THROW(service.registarJogador(dto), std::exception);
}

TEST_F(JogadorServiceTest, RegisterDuplicateUsername) {
    RegistoDTO dto1{"andre", "1234"};
    RegistoDTO dto2{"andre", "5678"};

    service.registarJogador(dto1);

    EXPECT_THROW(service.registarJogador(dto2), std::exception);
}

TEST_F(JogadorServiceTest, RegisterValid) {
    RegistoDTO dto{"andre", "1234"};

    EXPECT_NO_THROW(service.registarJogador(dto));

    EXPECT_TRUE(container.usernameExiste("andre"));
}

TEST_F(JogadorServiceTest, AuthenticateEmptyUsername) {
    LoginDTO dto{"", "1234"};

    EXPECT_THROW(service.autenticar(dto), std::exception);
}

TEST_F(JogadorServiceTest, AuthenticateEmptyPassword) {
    LoginDTO dto{"andre", ""};

    EXPECT_THROW(service.autenticar(dto), std::exception);
}

TEST_F(JogadorServiceTest, AuthenticateWrongCredentials) {
    RegistoDTO regDto{"andre", "1234"};
    service.registarJogador(regDto);

    LoginDTO loginDto{"andre", "errada"};
    EXPECT_THROW(service.autenticar(loginDto), std::exception);
}

TEST_F(JogadorServiceTest, AuthenticateNonexistentUsername) {
    LoginDTO dto{"nonexistent", "1234"};

    EXPECT_THROW(service.autenticar(dto), std::exception);
}

TEST_F(JogadorServiceTest, AuthenticateValidCredentials) {
    RegistoDTO regDto{"andre", "1234"};
    service.registarJogador(regDto);

    LoginDTO loginDto{"andre", "1234"};

    Jogador* player = nullptr;
    EXPECT_NO_THROW(player = service.autenticar(loginDto));
    EXPECT_NE(player, nullptr);
    EXPECT_EQ(player->username, "andre");
}

TEST_F(JogadorServiceTest, RegisterThenAuthenticate) {
    RegistoDTO regDto{"diogo", "5678"};
    service.registarJogador(regDto);
    
    LoginDTO loginDto{"diogo", "5678"};
    Jogador* player = service.autenticar(loginDto);
    
    EXPECT_NE(player, nullptr);
    EXPECT_EQ(player->username, "diogo");
}

TEST_F(JogadorServiceTest, MultipleRegistrationsAndAuthentications) {
    service.registarJogador(RegistoDTO{"andre", "1234"});
    service.registarJogador(RegistoDTO{"diogo", "5678"});
    service.registarJogador(RegistoDTO{"goncalo", "9012"});

    Jogador* andre = service.autenticar(LoginDTO{"andre", "1234"});
    Jogador* diogo = service.autenticar(LoginDTO{"diogo", "5678"});
    Jogador* goncalo = service.autenticar(LoginDTO{"goncalo", "9012"});
    
    EXPECT_NE(andre, nullptr);
    EXPECT_NE(diogo, nullptr);
    EXPECT_NE(goncalo, nullptr);
    EXPECT_EQ(andre->username, "andre");
    EXPECT_EQ(diogo->username, "diogo");
    EXPECT_EQ(goncalo->username, "goncalo");
}

TEST_F(JogadorServiceTest, RegisterLongUsername) {
    RegistoDTO dto{std::string(100, 'a'), "1234"};

    EXPECT_NO_THROW(service.registarJogador(dto));
}

TEST_F(JogadorServiceTest, InitialBalanceIs1000) {
    RegistoDTO dto{"andre", "1234"};
    service.registarJogador(dto);
    
    Jogador* player = service.autenticar(LoginDTO{"andre", "1234"});
    EXPECT_EQ(player->saldo, 1000.0);
}