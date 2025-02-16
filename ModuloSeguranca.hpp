#pragma once
#include "Modulo.hpp"

class ModuloSeguranca : public Modulo{
    public:
        ModuloSeguranca(char tipo);
        ModuloSeguranca();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};