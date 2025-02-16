#include "ModuloComAstronauta.hpp"
#include <iostream>

ModuloComAstronauta::ModuloComAstronauta(char tipo) : Modulo(tipo){}
ModuloComAstronauta::ModuloComAstronauta(){}

char ModuloComAstronauta::getTipo() const{
    return tipo;
}
bool ModuloComAstronauta::podeAcessar() const{
    return true;
}
void ModuloComAstronauta::setTipo(char tipo){
    this->tipo = tipo;
}