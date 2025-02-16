#pragma once
#include <string>
#include <vector>
#include <utility>
#include "EstacaoEspacial.hpp"
#include "Astronauta.hpp"
#include "ModuloComFogo.hpp"
#include "Modulo.hpp"

class RoboDeResgate{
    protected:
        int posicaoInicialX, posicaoInicialY, passos = 0;
        EstacaoEspacial& estacaoEspacial;
        std::vector<Astronauta> resgatados;
        std::vector<Astronauta> naoResgatados;
        std::vector<std::vector<bool>> visitado;
        std::vector<std::vector<int>> distancias;
        ModuloComFogo moduloComFogo;
        struct Posicao{
            int x, y;
        };

    public:
        RoboDeResgate(int posicaoInicnalX, int posicaoInicnalY, EstacaoEspacial& estacaoEspacial);

        void iniciarResgate();
        bool proximoAoFogo(int posicaoX, int posicaoY);
        void resgatarAstronauta(Astronauta astronauta);
        void registrarRelatorio(std::string relatorio);
        void imprimirCaminho(std::vector<Posicao>& anterior);
};