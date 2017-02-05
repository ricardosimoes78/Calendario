
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


void Abrir_Projeto( Tp_Projeto *p_Lst_Projeto, TButton *p_Bto_Salvar, TPanel *p_Painel, Tfrm_Calendario *p_Form );

void Incluir_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto, String p_Nome, String p_Data_Entrega, String p_Data_Alteracao,  Tfrm_Calendario *p_Form );

void Salvar_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto);

void Mostrar_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, int p_Posicao, String p_Nome, String p_Data_Entrega, String p_Data_Alteracao, Tfrm_Calendario *p_Form );

void Atualiza_Projeto( Tp_Projeto *p_Lst_Projeto, TEdit *p_Edit );

void Remover_Projeto( Tp_Projeto *p_Lst_Projeto, TButton *p_Button );
