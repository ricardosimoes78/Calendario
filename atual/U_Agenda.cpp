
#ifndef U_Agenda_H
#define U_Agenda_H
    #include <U_Agenda.h>
#endif

#ifndef U_Agenda_Arquivo_H
#define U_Agenda_Arquivo_H
    #include <U_Agenda_Arquivo.h>
#endif   

void Mostrar_Agenda( Tp_Agenda *p_Agenda, Tfrm_Calendario *p_Form )
{
    TPanel *pn_Horario = NULL;
    int dia=0, quant_dias=7, hora=0, quant_horas=9;
    int delta_X=72, delta_Y=24;
    int Top=0, Left=0;

    Top = p_Form->lbl_Sem_Domingo->Top + p_Form->lbl_Sem_Domingo->Height + 4;
    Left = p_Form->lbl_Sem_Domingo->Left;
    for( dia=0; dia<quant_dias; dia++ )
    {
        for( hora=0; hora<quant_horas; hora++ )
        {
            pn_Horario = new TPanel(p_Form);
            pn_Horario->Parent = p_Form;
            pn_Horario->Top = Top + delta_Y*hora;
            pn_Horario->Left = Left + delta_X*dia;
            pn_Horario->Height = delta_Y;
            pn_Horario->Width = delta_X;
            pn_Horario->Hint = hora;
            pn_Horario->Tag = dia;

            switch(dia)
            {
                case 0: pn_Horario->Caption = p_Agenda->Domingo[hora]; break;
                case 1: pn_Horario->Caption = p_Agenda->Segunda[hora]; break;
                case 2: pn_Horario->Caption = p_Agenda->Terca[hora]; break;
                case 3: pn_Horario->Caption = p_Agenda->Quarta[hora]; break;
                case 4: pn_Horario->Caption = p_Agenda->Quinta[hora]; break;
                case 5: pn_Horario->Caption = p_Agenda->Sexta[hora]; break;
                case 6: pn_Horario->Caption = p_Agenda->Sabado[hora]; break;
                default: pn_Horario->Caption = "???";
            }
        }
    }

}

void Abrir_Agenda( Tp_Agenda *p_Agenda, Tfrm_Calendario *p_Form )
{
    int dia = Now().CurrentDate().DayOfWeek();
     
	switch(dia)
	{
		case 1: p_Form->lbl_Sem_Domingo->Color = clActiveCaption; break;
		case 2: p_Form->lbl_Sem_Segunda->Color = clActiveCaption; break;
		case 3: p_Form->lbl_Sem_Terca->Color = clActiveCaption; break;
		case 4: p_Form->lbl_Sem_Quarta->Color = clActiveCaption; break;
		case 5: p_Form->lbl_Sem_Quinta->Color = clActiveCaption; break;
		case 6: p_Form->lbl_Sem_Sexta->Color = clActiveCaption; break;
		case 7: p_Form->lbl_Sem_Sabado->Color = clActiveCaption; break;
	}

    Abrir_Arquivo_Agenda( p_Agenda );

    Mostrar_Agenda(p_Agenda, p_Form);

}
