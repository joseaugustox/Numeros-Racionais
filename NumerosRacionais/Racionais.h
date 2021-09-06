#ifndef RACIONAIS_H
#define RACIONAIS_H

#include <QString>

namespace jaos
{
    class Racionais
    {
    private:
        int numerador;
        int denominador;
        void reduzRacional();
        int mdc(int n1, int n2);
        int mmc(int n1, int n2);
    public:
        Racionais();
        Racionais(int a, int b);
        void setNumerador(int a);
        void setDenominador(int b);
        int getNumerador();
        int getDenominador();
        QString obterRacional();
        Racionais operator +(Racionais &numero);
        Racionais operator -(Racionais &numero);
        Racionais operator *(Racionais &numero);
        Racionais operator /(Racionais &numero);
        bool operator ==(Racionais &numero);
     };
}


#endif // RACIONAIS_H
