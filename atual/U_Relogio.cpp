#ifndef U_Relogio_H
#define U_Relogio_H
    #include <U_Relogio.h>
#endif

TColor Fundo(int p_Hora)
{
    int Vermelho[24]={28,34,36,28,36,37,30,28,27,115,161,213,255,253,249,245,237,236,234,219,172,116,93,44},
        Verde[24]   ={28,36,62,80,118,153,166,171,180,197,213,233,250,226,196,140,94,55,26,3,27,41,38,34},
        Azul[24]    ={76,94,132,150,192,196,160,148,146,147,156,168,165,166,165,150,107,95,97,121,121,111,100,89};

    return (TColor)RGB(Vermelho[p_Hora],Verde[p_Hora],Azul[p_Hora]);
}

void Horarios( TPanel *p_Painel )
{
    int quant=24, cont=0, largura=0, delta_Larg=0, delta_Cont=0, ini=0;
    float ajuste=0;
    TPanel *horario = NULL;

    largura = p_Painel->Width / quant;
    ajuste = ((float)p_Painel->Width / quant) - largura;
    for( cont=0; cont<quant; cont++ )
    {
        horario = new TPanel(p_Painel);
        horario->Parent = p_Painel;
        horario->Top = 42;
        horario->Left = ini;
        horario->Height = 8;
        horario->Width = largura+delta_Larg;
        horario->Color = Fundo(cont);
        //horario->Font->Color = clWhite;
        //horario->Caption = cont;

        ini += horario->Width;
        if (ajuste*delta_Cont > 1)
        {
            delta_Larg = 1;
            delta_Cont = 0;
        }
        else
        {
            delta_Larg = 0;
            delta_Cont++;
        }

        if (cont == quant-2)
        {
            largura = p_Painel->Width - ini;
        }
    }
}

