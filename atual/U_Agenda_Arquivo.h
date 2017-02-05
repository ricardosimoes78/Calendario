
#ifndef Base_CPP_H
#define Base_CPP_H
    #include <vcl.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <time.h>
#endif

#ifndef U_Agenda_Struct_H
#define U_Agenda_Struct_H
    #include <U_Agenda_Struct.h>
#endif

int Salvar_Arquivo_Agenda( Tp_Agenda *p_Agenda );

int Abrir_Arquivo_Agenda( Tp_Agenda *p_Agenda );
 