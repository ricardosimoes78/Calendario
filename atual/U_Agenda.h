
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

#ifndef U_Calendario_H
#define U_Calendario_H
    #include <U_Calendario.h>
#endif


void Mostrar_Agenda( Tp_Agenda *p_Agenda, Tfrm_Calendario *p_Form );

void Abrir_Agenda( Tp_Agenda *p_Agenda, Tfrm_Calendario *p_Form );
