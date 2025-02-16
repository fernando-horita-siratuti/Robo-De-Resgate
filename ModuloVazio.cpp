#include "ModuloVazio.hpp"
#include <iostream>

ModuloVazio::ModuloVazio(char tipo) : Modulo(tipo){}
ModuloVazio::ModuloVazio(){}

char ModuloVazio::getTipo() const{
    return tipo;
}
bool ModuloVazio::podeAcessar() const{
    return false;
}
void ModuloVazio::setTipo(char tipo){
    this->tipo = tipo;
}