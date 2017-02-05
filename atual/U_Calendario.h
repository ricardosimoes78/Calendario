//---------------------------------------------------------------------------

#ifndef U_CalendarioH
#define U_CalendarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class Tfrm_Calendario : public TForm
{
__published:	// IDE-managed Components
    TMonthCalendar *Calendario;
    TTimer *Relogio;
    TPanel *pnl_Horario_Fundo;
    TLabel *lbl_Horario_Fundo;
    TPanel *pnl_Horario_Cores;
    TLabel *lbl_Horario_Cores;
    TPanel *Projeto;
    TButton *bto_IncProjeto;
    TEdit *edt_IncProjeto;
    TEdit *edt_DataProjeto;
    TButton *bto_Salvar;
    TLabel *H0600;
    TLabel *H0800;
    TLabel *H1400;
    TLabel *H1200;
    TLabel *H1000;
    TLabel *H2200;
    TLabel *H2000;
    TLabel *H1800;
    TLabel *H1600;
    TLabel *lbl_Sem_Domingo;
    TLabel *lbl_Sem_Segunda;
    TLabel *lbl_Sem_Quarta;
    TLabel *lbl_Sem_Terca;
    TLabel *lbl_Sem_Sabado;
    TLabel *lbl_Sem_Sexta;
    TLabel *lbl_Sem_Quinta;
    TBevel *bvl_Separador2;
    TMemo *Memo1;
        void __fastcall FormShow(TObject *Sender);
    void __fastcall RelogioTimer(TObject *Sender);
    void __fastcall bto_IncProjetoClick(TObject *Sender);
    void __fastcall bto_SalvarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_Calendario(TComponent* Owner);
    void __fastcall  Alarme_Gravar( TObject *p_Sender );
    void __fastcall  Alarme_Salvo( TObject *p_Sender );
    void __fastcall  Deletar_Projeto( TObject *p_Sender );
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_Calendario *frm_Calendario;
//---------------------------------------------------------------------------
#endif
