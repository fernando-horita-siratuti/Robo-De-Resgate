#pragma once
#include "Modulo.hpp"

class ModuloObstaculo : public Modulo{
    public:
        ModuloObstaculo(char tipo);
        ModuloObstaculo();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};