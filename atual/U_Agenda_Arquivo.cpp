
#ifndef U_Agenda_Arquivo_H
#define U_Agenda_Arquivo_H
    #include <U_Agenda_Arquivo.h>
#endif

#ifndef U_Agenda_H
#define U_Agenda_H
    #include <U_Agenda.h>
#endif

#ifndef U_Calendario_H
#define U_Calendario_H
    #include <U_Calendario.h>
#endif


int Salvar_Arquivo_Agenda( Tp_Agenda *p_Agenda )
{
    //

    return 0;
}


int Abrir_Arquivo_Agenda( Tp_Agenda *p_Agenda )
{
    FILE *arquivo = NULL;
    char  hora[16], domingo[256], segunda[256], terca[256], quarta[256], quinta[256], sexta[256], sabado[256];
    int tam=0, cont=0;

    arquivo = fopen( "agenda.txt", "r" );
    if( arquivo != NULL )
    {
        while ( fscanf(arquivo, "%s %s %s %s %s %s %s %s", hora, domingo, segunda, terca, quarta, quinta, sexta, sabado) > 0)
        {
            tam += 1;
            p_Agenda->Domingo[cont] = domingo;
            p_Agenda->Segunda[cont] = segunda;
            p_Agenda->Terca[cont] = terca;
            p_Agenda->Quarta[cont] = quarta;
            p_Agenda->Quinta[cont] = quinta;
            p_Agenda->Sexta[cont] = sexta;
            p_Agenda->Sabado[cont] = sabado;
            cont++;
        }
    }

    fclose (arquivo);

    return tam;
}

 