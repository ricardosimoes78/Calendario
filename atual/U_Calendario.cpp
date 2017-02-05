//---------------------------------------------------------------------------

#pragma hdrstop

#ifndef U_Calendario_H
#define U_Calendario_H
    #include <U_Calendario.h>
#endif                

#ifndef U_Projeto_H
#define U_Projeto_H
    #include <U_Projeto.h>
#endif

#ifndef U_Agenda_H
#define U_Agenda_H
    #include <U_Agenda.h>
#endif

#ifndef U_Relogio_H
#define U_Relogio_H
    #include <U_Relogio.h>
#endif

#ifndef U_Fim_H
#define U_Fim_H
    #include <U_Fim.h>
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int dia; int mes; int ano;
int hora; int min; int seg;

Tp_Projeto Lst_Projeto[10];
Tp_Agenda Agenda;

Tfrm_Calendario *frm_Calendario;
//---------------------------------------------------------------------------
__fastcall Tfrm_Calendario::Tfrm_Calendario(TComponent* Owner): TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Calendario::FormShow(TObject *Sender)
{
    this->Projeto->Tag = 0;

    this->Left = 0; //(1920-this->Width)/2;
    this->Top = 0;

    if(Screen->DesktopWidth>1920)
    {
        this->Left = 1920;
        this->Top = 312;
    }

    //Screen->MonitorCount;
    //Screen->Monitors->MonitorNum;

    Abrir_Projeto( (Tp_Projeto *)Lst_Projeto, this->bto_Salvar, this->Projeto, this );
    Abrir_Agenda( &Agenda, this );

    Calendario->Date = Now();
    Calendario->Font->Name = "Verdana";
    //Calendario->Font->Size = 20;
    //Calendario->Top    = 56;
    //Calendario->Left   = 60;
    //Calendario->Height = 353;
    //Calendario->Width  = 428;

    lbl_Horario_Fundo->Align       = alNone;
    lbl_Horario_Fundo->AutoSize    = false;
    lbl_Horario_Fundo->Alignment   = taCenter;
    lbl_Horario_Fundo->Height      = 30;
    lbl_Horario_Fundo->Top         = 0;
    lbl_Horario_Fundo->Left        = 0;
    lbl_Horario_Fundo->Width       = this->Width;
    lbl_Horario_Fundo->Font->Name  = "Courier New";
    lbl_Horario_Fundo->Font->Size  = 20;
    lbl_Horario_Fundo->Font->Color = clGreen;

    pnl_Horario_Fundo->Height = 50;
    pnl_Horario_Fundo->Top    = 0;
    pnl_Horario_Fundo->Left   = 0;
    pnl_Horario_Fundo->Width  = this->Width;

    lbl_Horario_Cores->Align       = lbl_Horario_Fundo->Align;
    lbl_Horario_Cores->AutoSize    = lbl_Horario_Fundo->AutoSize;
    lbl_Horario_Cores->Alignment   = lbl_Horario_Fundo->Alignment;
    lbl_Horario_Cores->Height      = lbl_Horario_Fundo->Height;
    lbl_Horario_Cores->Left        = lbl_Horario_Fundo->Left;
    lbl_Horario_Cores->Top         = lbl_Horario_Fundo->Top;
    lbl_Horario_Cores->Width       = lbl_Horario_Fundo->Width;
    lbl_Horario_Cores->Font->Name  = lbl_Horario_Fundo->Font->Name;
    lbl_Horario_Cores->Font->Size  = lbl_Horario_Fundo->Font->Size;
    lbl_Horario_Cores->Font->Color = lbl_Horario_Fundo->Font->Color;

    pnl_Horario_Cores->Height     = pnl_Horario_Fundo->Height-8;
    pnl_Horario_Cores->Top        = pnl_Horario_Fundo->Top;
    pnl_Horario_Cores->Left       = pnl_Horario_Fundo->Left;
    pnl_Horario_Cores->BevelOuter = bvNone;

    Horarios( this->pnl_Horario_Fundo );

    lbl_Horario_Fundo->Caption = Calendario->Date;
    sscanf(lbl_Horario_Fundo->Caption.c_str(), "%02d/%02d/%04d %02d:%02d:%02d", &dia, &mes, &ano, &hora, &min, &seg );
    this->RelogioTimer(Sender);

}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Calendario::RelogioTimer(TObject *Sender)
{
    char relogio[256];
    TLabel *Horario = new TLabel(this);

    Horario->Caption = Now();
    sscanf(Horario->Caption.c_str(), "%02d/%02d/%04d %02d:%02d:%02d", &dia, &mes, &ano, &hora, &min, &seg );

    sprintf(relogio, "%02d:%02d:%02d", hora, min, seg);
    this->lbl_Horario_Fundo->Caption = relogio;
    this->lbl_Horario_Cores->Caption = relogio;

    this->pnl_Horario_Cores->Color = Fundo(hora);
    this->pnl_Horario_Cores->Width = (hora+((float)min/60))/24 * this->pnl_Horario_Fundo->Width;

    if((hora == 22)&&(min%5==0))
    {
        frm_Fim->Left = this->Left;
        frm_Fim->Top  = this->Top;

        frm_Fim->Show();
        frm_Fim->BringToFront();
        frm_Fim->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Calendario::bto_IncProjetoClick(TObject *Sender)
{

    Incluir_Projeto(this->bto_Salvar, this->Projeto, (struct struct_Projeto *)Lst_Projeto, this->edt_IncProjeto->Text, this->edt_DataProjeto->Text, "", this);
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Calendario::bto_SalvarClick(TObject *Sender)
{
    Salvar_Projeto(this->bto_Salvar, this->Projeto, (struct struct_Projeto *)Lst_Projeto);
    this->Alarme_Salvo(Sender);

    this->Left;
    this->Top;
}
//---------------------------------------------------------------------------


void __fastcall Tfrm_Calendario::Alarme_Gravar( TObject *p_Sender )
{
    TEdit *edt_Campo = (TEdit *) p_Sender;
    Atualiza_Projeto( (struct struct_Projeto *)Lst_Projeto, edt_Campo );

    this->bto_Salvar->Font->Color = clRed;
    this->bto_Salvar->Caption = "V GRAVAR";
    this->bto_Salvar->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Calendario::Alarme_Salvo( TObject *p_Sender )
{
    this->bto_Salvar->Font->Color = clGreen;
    this->bto_Salvar->Caption = "v Salvo";
    this->bto_Salvar->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Calendario::Deletar_Projeto( TObject *p_Sender )
{

    MessageBox(NULL, "Alterar o arquivo texto PROJETO.TXT", "-- AVISO --", MB_OK);

/*
    TButton *bto_Deletar = (TButton *) p_Sender;
    Remover_Projeto( (struct struct_Projeto *)Lst_Projeto, bto_Deletar );
    this->Projeto->Tag--;

    Salvar_Projeto(this->bto_Salvar, this->Projeto, (struct struct_Projeto *)Lst_Projeto);

    // Remover todos os projetos (Lst_Projetos) do formulário:
    int quant=0, cont=0;
    TComponent *componente;

    quant = this->Projeto->ComponentCount;
    do
    {
        componente = this->Projeto->Components[cont];
        cont++;
    } while (( componente->Name != "Lst_Projetos" ) && ( (cont-1)<quant ));

    delete componente;

    Abrir_Projeto( this->bto_Salvar, this->Projeto, (struct struct_Projeto *)Lst_Projeto, this );
*/
}
//---------------------------------------------------------------------------


