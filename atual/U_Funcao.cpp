//---------------------------------------------------------------------------


#pragma hdrstop

#include "U_Funcao.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TColor Fundo(int p_Hora)
{
    if (p_Hora <= 12) return clLime;
    if (p_Hora <= 12) return clAqua;
    if (p_Hora <= 18) return clYellow;
    if (p_Hora >  18) return clBlue;
}