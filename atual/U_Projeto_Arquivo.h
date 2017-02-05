
#ifndef Base_CPP_H
#define Base_CPP_H
    #include <vcl.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <time.h>
#endif

#ifndef U_Projeto_Struct_H
#define U_Projeto_Struct_H
    #include <U_Projeto_Struct.h>
#endif

#ifndef U_Calendario_H
#define U_Calendario_H
    #include <U_Calendario.h>
#endif

int Salvar_Arquivo_Projeto( TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto );

int Abrir_Arquivo_Projeto( TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto );
 
