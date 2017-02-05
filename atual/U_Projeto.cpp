
#ifndef U_Projeto_H
#define U_Projeto_H
    #include <U_Projeto.h>
#endif

#ifndef U_Projeto_Arquivo_H
#define U_Projeto_Arquivo_H
    #include <U_Projeto_Arquivo.h>
#endif


/*
struct struct_Projeto
{
    String Nome;
    String Data_Entrega;
    String Data_Alteracao;
    int Tamanho;
} Lst_Projeto[10];
*/


void Abrir_Projeto( Tp_Projeto *p_Lst_Projeto, TButton *p_Bto_Salvar, TPanel *p_Painel, Tfrm_Calendario *p_Form )
{

    int quant = 0,
        cont  = 0;

    Abrir_Arquivo_Projeto( p_Painel, p_Lst_Projeto );

    TPanel *painel = new TPanel(p_Painel);
    painel->Parent = p_Painel;
    painel->Name = "Lst_Projetos";
    painel->Caption = "";
    painel->Align = alClient;

    TLabel *lbl_Projeto = new TLabel(painel);
    lbl_Projeto->Parent = painel;
    lbl_Projeto->Caption = "Projeto";
    lbl_Projeto->Top = 8;
    lbl_Projeto->Left = 8;

    TLabel *lbl_Entrega = new TLabel(painel);
    lbl_Entrega->Parent = painel;
    lbl_Entrega->Caption = "Entrega";
    lbl_Entrega->Top = lbl_Projeto->Top;
    lbl_Entrega->Left = 166;

    TLabel *lbl_Alteracao = new TLabel(painel);
    lbl_Alteracao->Parent = painel;
    lbl_Alteracao->Caption = "Alteração";
    lbl_Alteracao->Top = lbl_Projeto->Top;
    lbl_Alteracao->Left = 280;

    TLabel *lbl_Deletar = new TLabel(painel);
    lbl_Deletar->Parent = painel;
    lbl_Deletar->Caption = "Del";
    lbl_Deletar->Top = lbl_Projeto->Top;
    lbl_Deletar->Left = 394;

    quant = p_Painel->Tag;
    while(cont<quant)
    {
        Mostrar_Projeto( p_Bto_Salvar, painel, cont, p_Lst_Projeto[cont].Nome, p_Lst_Projeto[cont].Data_Entrega, p_Lst_Projeto[cont].Data_Alteracao, p_Form );
        cont++;
    }
}

void Incluir_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto, String p_Nome, String p_Data_Entrega, String p_Data_Alteracao, Tfrm_Calendario *p_Form )
{
    int cont = p_Painel->Tag;
    p_Lst_Projeto[cont].Nome = p_Nome;
    p_Lst_Projeto[cont].Data_Entrega = p_Data_Entrega;
    p_Lst_Projeto[cont].Data_Alteracao = p_Data_Alteracao;
    p_Painel->Tag++;

    Mostrar_Projeto( p_Bto_Salvar, p_Painel, cont, p_Nome, p_Data_Entrega, p_Data_Alteracao, p_Form );
}

void Salvar_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, Tp_Projeto *p_Lst_Projeto)
{
    Salvar_Arquivo_Projeto( p_Painel, p_Lst_Projeto );
}

void Mostrar_Projeto( TButton *p_Bto_Salvar, TPanel *p_Painel, int p_Posicao, String p_Nome, String p_Data_Entrega, String p_Data_Alteracao, Tfrm_Calendario *p_Form )
{
    int H_dia=0, H_mes=0, H_ano=0, H_Prazo=0, /* Data Atual, Prazo em dias */
        E_dia=0, E_mes=0, E_ano=0, E_Prazo=0, /* Data da Entrega, Prazo em dias */
        A_dia=0, A_mes=0, A_ano=0, A_Prazo=0; /* Data da última Alteração, Prazo em dias */
    int Vermelho=0, Verde=0, Azul=0;

    TEdit *nome = new TEdit(p_Painel);
    TEdit *dt_Entrega = new TEdit(p_Painel);
    TPanel *sn_Entrega = new TPanel(p_Painel);
    TEdit *dt_Alteracao = new TEdit(p_Painel);
    TPanel *sn_Alteracao = new TPanel(p_Painel);
    TButton *bto_Retirar = new TButton(p_Painel);

    sscanf(Now().DateString().c_str(), "%02d/%02d/%04d", &H_dia, &H_mes, &H_ano );
    H_Prazo = H_ano*365+H_mes*30+H_dia;

    nome->Parent = p_Painel;
    nome->OnChange = p_Form->Alarme_Gravar;
    nome->Top = 24 + 20*p_Posicao;
    nome->Left = 8;
    nome->Width = 150;
    nome->Text = p_Nome;
    nome->Tag = p_Posicao;
    nome->Hint = "Nome";

    dt_Entrega->Parent = nome->Parent;
    dt_Entrega->OnChange = p_Form->Alarme_Gravar;
    dt_Entrega->Top = nome->Top;
    dt_Entrega->Left = 166; //nome->Left + nome->Width;
    dt_Entrega->Width = 76;
    dt_Entrega->Text = p_Data_Entrega;
    dt_Entrega->Tag = p_Posicao;
    dt_Entrega->Hint = "Entrega";

    sn_Entrega->Parent = p_Painel;
    sn_Entrega->Top = dt_Entrega->Top;
    sn_Entrega->Left = dt_Entrega->Left + dt_Entrega->Width;
    sn_Entrega->Height = 18;
    sn_Entrega->Width = 30;

    sscanf(p_Data_Entrega.c_str(), "%02d/%02d/%04d", &E_dia, &E_mes, &E_ano );
    E_Prazo = E_ano*365+E_mes*30+E_dia;

    Vermelho=0; Verde=0; Azul=0;

         if( (E_Prazo-H_Prazo > 30) ) { Vermelho=  0; Verde=255; Azul=0; } // Azul     = 255; Verde = 255*((float)(E_Prazo-H_Prazo-30)/30); if (Verde>255) { Verde = 255; } }
    else if( (E_Prazo-H_Prazo > 25) ) { Vermelho= 84; Verde=255; Azul=0; }
    else if( (E_Prazo-H_Prazo > 15) ) { Vermelho=168; Verde=255; Azul=0; } // Verde    = 255; Azul  = 255*((float)(E_Prazo-H_Prazo-15)/15); if (Azul>255) { Azul = 255; } }
    else if( (E_Prazo-H_Prazo > 10) ) { Vermelho=255; Verde=168; Azul=0; }
    else if( (E_Prazo-H_Prazo >  5) ) { Vermelho=255; Verde= 84; Azul=0; } // Vermelho = 255; Verde = 255*((float)(E_Prazo-H_Prazo- 5)/ 5); if (Verde>255) { Verde = 255; } }
    else if( (E_Prazo-H_Prazo >  0) ) { Vermelho=255; Verde=  0; Azul=0; } // Vermelho = 255*((float)(E_Prazo-H_Prazo)/5); if (Vermelho>255) { Vermelho = 255; } }

    sn_Entrega->Color = (TColor)RGB( Vermelho, Verde, Azul);

    dt_Alteracao->Parent = sn_Entrega->Parent;
    dt_Alteracao->OnChange = p_Form->Alarme_Gravar;
    dt_Alteracao->Top = sn_Entrega->Top;
    dt_Alteracao->Left = 280; //sn_Entrega->Left + sn_Entrega->Width;
    dt_Alteracao->Width = dt_Entrega->Width;
    dt_Alteracao->Text = p_Data_Alteracao;
    dt_Alteracao->Tag = p_Posicao;
	dt_Alteracao->Hint = "Alteracao";

    sn_Alteracao->Parent = dt_Alteracao->Parent;
    sn_Alteracao->Top = dt_Alteracao->Top;
    sn_Alteracao->Left = dt_Alteracao->Left + dt_Alteracao->Width;
    sn_Alteracao->Height = 18;
    sn_Alteracao->Width = 30;

    sscanf(p_Data_Alteracao.c_str(), "%02d/%02d/%04d", &A_dia, &A_mes, &A_ano );
    A_Prazo = A_ano*365+A_mes*30+A_dia;

    Vermelho=255; Verde=255; Azul=255;

         if( (H_Prazo-A_Prazo == 0) ) { Vermelho=0; Verde=255; Azul=  0; } // sn_Alteracao->Color = (TColor)RGB(  0,255,  0); }
    else if( (H_Prazo-A_Prazo <  5) ) { Vermelho=0; Verde=255; Azul= 84; } // sn_Alteracao->Color = (TColor)RGB(  0,255,255); }
    else if( (H_Prazo-A_Prazo < 10) ) { Vermelho=0; Verde=255; Azul=168; } // sn_Alteracao->Color = (TColor)RGB(  0,  0,255); }
    else if( (H_Prazo-A_Prazo < 20) ) { Vermelho=0; Verde=168; Azul=255; } // sn_Alteracao->Color = (TColor)RGB(255,  0,255); }
    else if( (H_Prazo-A_Prazo < 30) ) { Vermelho=0; Verde= 84; Azul=255; } // sn_Alteracao->Color = (TColor)RGB(255,  0,128); }
    else if( (H_Prazo-A_Prazo < 60) ) { Vermelho=0; Verde=  0; Azul=255; } // sn_Alteracao->Color = (TColor)RGB(255,  0,  0); }
    else {  }

    sn_Alteracao->Color = (TColor)RGB( Vermelho, Verde, Azul);

    bto_Retirar->Parent = sn_Alteracao->Parent;
    bto_Retirar->OnClick = p_Form->Deletar_Projeto;
    bto_Retirar->Tag = p_Posicao;
    bto_Retirar->Top = sn_Alteracao->Top;
    bto_Retirar->Left = 390;
    bto_Retirar->Height = 18;
    bto_Retirar->Width = 30;
    bto_Retirar->Caption = "X";

}

void Atualiza_Projeto( struct struct_Projeto *p_Lst_Projeto, TEdit *p_Edit )
{
    int pos = 0;
    pos = p_Edit->Tag;

    if ( p_Edit->Hint == "Nome" )
    {
        p_Lst_Projeto[pos].Nome = p_Edit->Text;
    }
    else if ( p_Edit->Hint == "Entrega" )
    {
        p_Lst_Projeto[pos].Data_Entrega = p_Edit->Text;
    }
    else if ( p_Edit->Hint == "Alteracao" )
    {
        p_Lst_Projeto[pos].Data_Alteracao = p_Edit->Text;
    }
}

void Remover_Projeto( Tp_Projeto *p_Lst_Projeto, TButton *p_Button )
{
    Tp_Projeto Lst_Temp[10];
    int pos=p_Button->Tag, cont=0, quant=10, cont_prj=0;

    for( cont=0; cont<quant; cont++ )
    {
        Lst_Temp[cont].Nome = p_Lst_Projeto[cont].Nome;
        Lst_Temp[cont].Data_Entrega = p_Lst_Projeto[cont].Data_Entrega;
        Lst_Temp[cont].Data_Alteracao = p_Lst_Projeto[cont].Data_Alteracao;
        Lst_Temp[cont].Tamanho = p_Lst_Projeto[cont].Tamanho;

        p_Lst_Projeto[cont].Nome = "";
        p_Lst_Projeto[cont].Data_Entrega = "";
        p_Lst_Projeto[cont].Data_Alteracao = "";
        p_Lst_Projeto[cont].Tamanho = 0;
    }
    for( cont=0; cont<quant; cont++ )
    {
        if( pos != cont )
        {
            p_Lst_Projeto[cont_prj].Nome = Lst_Temp[cont].Nome;
            p_Lst_Projeto[cont_prj].Data_Entrega = Lst_Temp[cont].Data_Entrega;
            p_Lst_Projeto[cont_prj].Data_Alteracao = Lst_Temp[cont].Data_Alteracao;
            p_Lst_Projeto[cont_prj].Tamanho = Lst_Temp[cont].Tamanho;
            cont_prj++;
        }

        if( Lst_Temp[cont].Nome == "" ) cont = quant;
    }
}
