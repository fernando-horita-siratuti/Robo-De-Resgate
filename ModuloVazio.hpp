#pragma once
#include "Modulo.hpp"

class ModuloVazio : public Modulo{
    public:
        ModuloVazio(char tipo);
        ModuloVazio();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};