#pragma once
#include "Modulo.hpp"

class ModuloNormal : public Modulo{
    public:
        ModuloNormal(char tipo);
        ModuloNormal();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};