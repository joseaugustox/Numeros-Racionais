#include "Racionais.h"


namespace jaos {
    Racionais::Racionais()
    {
        numerador = 0;
        denominador=1;
    }

    Racionais::Racionais(int a, int b)
    {
        setNumerador(a);
        setDenominador(b);
        reduzRacional();
    }

    void Racionais::setNumerador(int a)
    {
        numerador = a;
    }

    void Racionais::setDenominador(int b)
    {
        if(b==0)
        {
            throw QString("Denominador nao poder ser 0");
        }
        denominador = b;
    }

    int Racionais::getNumerador()
    {
        return numerador;
    }

    int Racionais::getDenominador()
    {
        return denominador;
    }

    QString Racionais::obterRacional()
    {
        return QString::number(numerador) + "/" + QString::number(denominador);
    }

    Racionais Racionais::operator +(Racionais &numero)
    {
        int X = mmc(numero.getDenominador(),denominador);
        int a = X/denominador*numerador;
        int b = X/numero.getDenominador()*numero.getNumerador();
        Racionais aux(a+b,X);
        numerador = (aux.getNumerador());
        denominador=(aux.getDenominador());
        reduzRacional();
        numero.setNumerador(numerador);
        numero.setDenominador(denominador);
        return numero;
    }

    Racionais Racionais::operator -(Racionais &numero)
    {
        int X = mmc(numero.getDenominador(),denominador);
        int a = X/denominador*numerador;
        int b = X/numero.getDenominador()*numero.getNumerador();
        Racionais aux(a-b,X);
        numerador=(aux.getNumerador());
        denominador=(aux.getDenominador());
        reduzRacional();
        numero.setNumerador(numerador);
        numero.setDenominador(denominador);
        return numero;
    }

    Racionais Racionais::operator *(Racionais &numero)
    {
        Racionais aux(numero.getNumerador(),numero.getDenominador());
        numerador = (aux.getNumerador()*numerador);
        denominador = (aux.getDenominador()*denominador);
        reduzRacional();
        numero.setNumerador(numerador);
        numero.setDenominador(denominador);
        return numero;
    }

    Racionais Racionais::operator /(Racionais &numero)
    {
        //tenho que trabalhar com essa classe, depois reduzir e depois passar para &numero
        Racionais aux(numero.getNumerador(),numero.getDenominador());
        int x= aux.getNumerador();
        numerador = (aux.getDenominador()*numerador);
        denominador = (x*denominador);
        reduzRacional();
        numero.setNumerador(numerador);
        numero.setDenominador(denominador);
        return numero;
    }

    bool Racionais::operator ==(Racionais &numero)
    {
        return (obterRacional()==numero.obterRacional())?true:false;
    }

    void Racionais::reduzRacional()
    {
        if(numerador>0)
        {
            int X = mdc(numerador,denominador);
            while(X>1)
            {
                numerador = numerador/X;
                denominador = denominador/X;
                X=mdc(numerador,denominador);
            }
        }
    }

    int Racionais::mdc(int n1, int n2)
    {
        int resto=1;
        while (resto != 0)
        {
            resto = n1%n2;
            n1=n2;
            n2=resto;
        }
        return n1;
    }

    int Racionais::mmc(int n1, int n2)
    {
        return (n1*n2)/mdc(n1,n2);
    }
}

