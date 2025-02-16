#pragma once
#include "Modulo.hpp"

class ModuloComFogo : public Modulo{
    public:
        ModuloComFogo(char tipo);
        ModuloComFogo();

        char getTipo() const override;
        bool podeAcessar() const override;
        void setTipo(char tipo) override;
};