//---------------------------------------------------------------------------

#ifndef U_FimH
#define U_FimH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tfrm_Fim : public TForm
{
__published:	// IDE-managed Components
        TLabel *lbl_Preto;
        TLabel *lbl_Branco;
        TImage *Image1;
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_Fim(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_Fim *frm_Fim;
//---------------------------------------------------------------------------
#endif
