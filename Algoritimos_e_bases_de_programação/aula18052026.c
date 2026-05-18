#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>

#define max 50
int op=0, sop=0, ida=0, idc=0, idt=0;
char resp;

struct aluno{
    char pk_cpf[15];
    char nome[max];
    char admissao[10];
    char dtNasc[10];
    char escolaridade[max];
};

struct curso{
    int pk_codCurso;
    char nome[max];
    int cargaHoraria;
};

struct turma{
    int pk_codTurma;
    char nomeTurma[max];
    int qtdAlunos;
    char turno[20];
};

struct matricula{
    int pk_ra;
    char fk_cpf[15];
    int fk_codTurma;
    int fk_codCurso;
};

struct aluno a;
struct curso c;
struct turma t;
struct matricula m;

struct aluno tbaluno[max];
struct curso tbcurso[max];
struct turma tbturma[max];
struct matricula tbmatricula[max];


void submenuCadastrar(){
    printf("***********************************\n");
    printf("*            CADASTRAR            *\n");
    printf("***********************************\n");
    printf("*   1 - ALUNO                     *\n");
    printf("*   2 - CURSO                     *\n");
    printf("*   3 - TURMA                     *\n");
    printf("*   4 - MATRICULA                 *\n");
    printf("*   5 - RETORNAR                  *\n");
    printf("***********************************\n\n");
}

void menu(){
    printf("***********************************\n");
    printf("*         MENU PRINCIPAL          *\n");
    printf("***********************************\n");
    printf("*   1 - CADASTRAR                 *\n");
    printf("*   2 - CONSULTAR                 *\n");
    printf("*   3 - ALTERAR                   *\n");
    printf("*   4 - EXCLUIR                   *\n");
    printf("*   5 - ORDENAR                   *\n");
    printf("*   6 - IMPRIMIR                  *\n");
    printf("*   7 - FINALIZAR                 *\n");
    printf("***********************************\n\n");
}

void submenuOrdenar(){
    printf("***********************************\n");
    printf("*             ORDENAR             *\n");
    printf("***********************************\n");
    printf("*   1 - CRESCENTE                 *\n");
    printf("*   2 - DECRESCENTE               *\n");
    printf("*   3 - RETORNAR                  *\n");
    printf("***********************************\n\n");
}

_Bool buscar_aluno_pk_cpf(char cpf[15]){
    _Bool enc=false;
    int i=0;
    while((i<ida)&&(enc==false)){
        if (strcmp(tbaluno[i].pk_cpf,cpf)==0){
           enc=true; 
        }else{
            i++;
        } 
    }
    return enc;
}

_Bool buscar_curso_pk_codCurso(int codCurso){
    _Bool enc=false;
    int i=0;
    while((i<idc)&&(enc==false)){
        if (tbcurso[i].pk_codCurso==codCurso){
           enc=true; 
        }else{
            i++;
        } 
    }
    return enc;
}

//void ordenarCrescente(){
    
//}

void main()
{
    setlocale(LC_ALL, "");
    do{
        system("clear");
        menu();
        printf("Escolha a opção desejada: ");
        scanf("%d",&op);
        system("clear");
        switch(op){
            case 1:
                submenuCadastrar();
                printf("Escolha a opção desejada: ");
                scanf("%d",&sop);
                system("clear");
                switch(sop){
                    case 1:
                        do{
                            _Bool enc=false;
                            do{
                                system("clear");
                                printf("CPF: ");
                                scanf("%s",&a.pk_cpf);
                                if (ida>0) enc=buscar_aluno_pk_cpf(a.pk_cpf);
                                if (enc==true) {
                                    printf("CPF já cadastrado!\n");
                                    sleep(3);
                                }
                            }while(enc==true);
                            printf("Nome do Aluno: ");
                            getchar();
                            fgets(a.nome,sizeof(a.nome),stdin);
                            a.nome[strcspn(a.nome,"\n")] ='\0';
                            printf("Admissão: ");
                            scanf("%s",a.admissao);
                            printf("Data de Nascimento: ");
                            scanf("%s",a.dtNasc);
                            printf("Escolaridade: ");
                            getchar();
                            fgets(a.escolaridade,sizeof(a.escolaridade),stdin);
                            a.escolaridade[strcspn(a.escolaridade,"\n")] ='\0';
                            
                            tbaluno[ida]=a;
                            ida++;
                            printf("\nDeseja continuar cadastrando [s/n]: ");
                            scanf(" %c",&resp);
                        }while((ida<max) && (tolower(resp)=='s'));
                        break;
                    case 2:
                        do{
                            _Bool enc=false;
                            do{
                                system("clear");
                                printf("codCurso: ");
                                scanf("%d",&c.pk_codCurso);
                                if (idc>0) enc=buscar_curso_pk_codCurso(c.pk_codCurso);
                                if (enc==true) {
                                    printf("Código já cadastrado!\n");
                                    sleep(3);
                                }
                            }while(enc==true);
                            printf("Nome do Curso: ");
                            getchar();
                            fgets(c.nome,sizeof(c.nome),stdin);
                            c.nome[strcspn(c.nome,"\n")] ='\0';
                            printf("cargaHoraria: ");
                            scanf("%d",&c.cargaHoraria);
                            
                            tbcurso[idc]=c;
                            idc++;
                            printf("\nDeseja continuar cadastrando [s/n]: ");
                            scanf(" %c",&resp);
                        }while((idc<max) && (tolower(resp)=='s'));
                        break;
                    case 3:
                        do{
                            printf("Código da turma: \n");
                            scanf("%d",&t.pk_codTurma);
                            getchar();
                            
                            printf("Nome da turma: ");
                            fgets(t.nomeTurma,sizeof(t.nomeTurma),stdin);
                            t.nomeTurma[strcspn(t.nomeTurma,"\n")] ='\0';
                            
                            printf("Quantidade de alunos na turma: \n");
                            scanf("%d",&t.qtdAlunos);
                            getchar();
                       
                            printf("Turno: ");
                            fgets(t.turno,sizeof(t.turno),stdin);
                            t.turno[strcspn(t.turno,"\n")] = '\0';
                        
                            
                            tbturma[idt]=t;
                            idt++;
                            printf("\nDeseja continuar cadastrando [s/n]?");
                            scanf("%c",&resp);
                        }while((idt<max) && (tolower(resp)=='s'));
                        
                    // case 4 cadastrar_matricula():
                    
                    
                    default:
                        if (sop!=5) {
                            printf("Opção inválida!");
                            sleep(3);
                        }
                        break;
                    }
            
            
            case 5:
                system("clear");
                submenuOrdenar();
                printf("Escolha a opção desejada: ");
                scanf("%d",&sop);
                system("clear");
                switch(sop){
                   case 1:
                      //ordenarCrescente();
                   //case 2:ordenarDecrescente();
                   default:
                        if (sop!=3) {
                            printf("Opção inválida!");
                            sleep(3);
                        }
                        break;
                }
                break;
        }
    }while(op!=7);
    system("clear");
    printf("Sistema finalizado com sucesso!");
}
