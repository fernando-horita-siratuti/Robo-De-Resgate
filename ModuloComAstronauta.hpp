#pragma once
#include "Modulo.hpp"

class ModuloComAstronauta : public Modulo{
    public:
        ModuloComAstronauta(char tipo);
        ModuloComAstronauta();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};