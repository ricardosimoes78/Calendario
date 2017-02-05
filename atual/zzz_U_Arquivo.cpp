#include <stdio.h>
#include <dirent.h>
#include <vcl.h>

struct struct_Projeto
{
    String Nome;
    String Data_Entrega;
    String Data_Alteracao;
    int Tamanho;
};

int Salvar_Arquivo( TPanel *p_Painel, struct struct_Projeto *p_Lst_Projeto )
{
    FILE *arquivo = NULL;
    char  nome[256], data[16];
    int quant=p_Painel->Tag, cont=0, tam=0;

    arquivo = fopen( "projeto.txt", "w" );
    if( arquivo != NULL )
    {
        while (cont<quant)
        {
            tam += fprintf(arquivo, "%s %s %s\n\0", p_Lst_Projeto[cont].Nome, p_Lst_Projeto[cont].Data_Entrega, p_Lst_Projeto[cont].Data_Alteracao);
            cont++;
        }
    }

    fclose (arquivo);

    return tam;
}


int Abrir_Arquivo( TPanel *p_Painel, struct struct_Projeto *p_Lst_Projeto )
{
    FILE *arquivo = NULL;
    char  nome[256], data_entrega[16], data_alteracao[16];
    int tam=0, cont=0;

    arquivo = fopen( "projeto.txt", "r" );
    if( arquivo != NULL )
    {
        while ( fscanf(arquivo, "%s %s %s", nome, data_entrega, data_alteracao) > 0) //!feof(arquivo))
        {
            //tam += fscanf(arquivo, "%s %s", nome, data);
            p_Lst_Projeto[cont].Nome = nome;
            p_Lst_Projeto[cont].Data_Entrega = data_entrega;
            p_Lst_Projeto[cont].Data_Alteracao = data_alteracao;
            cont++;
        }

        p_Painel->Tag = cont;
    }

    fclose (arquivo);

    return tam;
}


/*


int Tamanho_Arquivo( char p_Arquivo[256] )
{
	FILE * pFile;
	long size;

	pFile = fopen (p_Arquivo,"rb");
	if (pFile!=NULL) 
	{
		fseek(pFile, 0, SEEK_END);
		size=ftell(pFile);		
	}
	fclose (pFile);
	return size;
}

int Tamanho_SubDiretorio( char p_Dir[256] )
{

    DIR *dpdf, *aux;
    struct dirent *epdf;
    int tamanho=0;

    dpdf = opendir(p_Dir);
    if (dpdf != NULL)
    {
        while (epdf = readdir(dpdf))
        {
            if ((strcmp(epdf->d_name, ".")!=0) && (strcmp(epdf->d_name, "..")!=0))
            {
                aux = opendir(epdf->d_name);
                if (aux != NULL)
                {
                    tamanho += Tamanho_SubDiretorio( epdf->d_name );
                }
                else
                {
                    tamanho += Tamanho_Arquivo( epdf->d_name );
                }
                aux = NULL;
            }
        }
    }

    return tamanho;
}

int Tamanho_Diretorio()
{
    DIR *dpdf, *aux;
    struct dirent *epdf;
    int tamanho=0;

    dpdf = opendir("./");
    if (dpdf != NULL)
    {
        while (epdf = readdir(dpdf))
        {
            if ((strcmp(epdf->d_name, ".")!=0) && (strcmp(epdf->d_name, "..")!=0))
            {
                aux = opendir(epdf->d_name);
                if (aux != NULL)
                {
                    tamanho += Tamanho_SubDiretorio( epdf->d_name );
                }
                else
                {
                    tamanho += Tamanho_Arquivo( epdf->d_name );
                }
                aux = NULL;
            }
        }
    }

    return tamanho;
}

*/