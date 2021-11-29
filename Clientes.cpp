#include <stdio.h>
#include <Windows.h> //sleep
#include <stdlib.h>
#include <locale.h>

void Cadastro();
void Listar();

struct VarG {
    char Cd;
    int op;
}; 

struct Cadastro {
    char Email[35];
    char Cpf[15];
    char Nome[25];
}; 

FILE* DB; //database

struct VarG Global;
struct Cadastro Cliente; 


int main() {
	
	setlocale(LC_ALL,"");
	
    system("cls");
    printf("=========================\n");
    printf(" ADMINISTRAÇÃO DE CLIENTES\n");
    printf("=========================\n\n");

    printf("[1] - Cadastrar\n");
    printf("[2] - Modificar\n");
    printf("[3] - Listar\n");
    printf("[4] - Remover\n");
	printf("[5] - Encerrar\n");
    printf("===============\n");
    printf("Opção: ");
    scanf("%d", &Global.op);
    getchar();

    switch (Global.op) {
        case 1:
            Cadastro(); //Funcão Cadastro 
            break;
        case 2:
            system("cls");
            printf("=========\n");
            printf(" MODIFICAR\n");
            printf("=========\n\n");

            printf("Para alterar os dados de um cadastro, acesse o\narquivo ");
            printf("clientes.txt e modifique manualmente através\nde um editor ");
            printf("de texto.\n\n");

            printf("\nVoltar ao Menu Principal? [s/n]: ");
            scanf("%c", &Global.Cd);

            if(Global.Cd == 's') {
                main();

            } else if(Global.Cd != 's' && Global.Cd != 'n') {
                printf("Inválido.\nVoltando ao Menu Principal...\n");
                Sleep(2);
                main();
            }

            break;

        case 3:
            Listar(); //Função Listar
            break;

        case 4:
            system("cls");;
            printf("=========\n");
            printf(" REMOVER\n");
            printf("=========\n\n");

            printf("Se quiser remover os dados, acesse\no arquivo ");
            printf("clientes.txt e realize o processo \nmanualmente, salvando o ");
            printf("arquivo logo em seguida.\n\n");

            printf("\nVoltar ao Menu Principal? [s/n]: ");
            scanf("%c", &Global.Cd);

            if(Global.Cd == 's') {
                main();

            } else if(Global.Cd != 's' && Global.Cd != 'n') {
                printf("Inválido.\nVoltando ao Menu Principal...\n");
                Sleep(1);
                main();

            }

            break;

        case 5:
            system("cls");;
            printf("======================\n");
            printf("   Saindo do programa   \n");
            printf("======================\n\n");
            break;
    
        default:
            printf("Valor inválido...\n");
            Sleep(1); 
            main();
            break;

    }

} 

void Cadastro() {
    system("cls");;
    DB = fopen("clientes.txt", "a"); 

    if(DB == NULL) { 
        printf("\nErro no Banco de Dados...\n");
        return;

    } else {
        printf("==========\n");
        printf(" CADASTRO\n");
        printf("==========\n");

        printf("\nNome: ");
        fgets(Cliente.Nome, 25, stdin); 
        
        printf("\nE-mail: ");
        fgets(Cliente.Email, 35, stdin); 
        
        printf("\nDigite seu CPF: ");
        fgets(Cliente.Cpf, 15, stdin); 

        system("cls");
        printf("\n=============================\n");
        printf("Finalizar cadastro? [s/n] : ");
        scanf("%c", &Global.Cd); 

        if(Global.Cd == 's') {
            fprintf(DB, "Nome: %sE-mail: %sCPF: %s", Cliente.Nome, Cliente.Email, Cliente.Cpf);
            fprintf(DB, "----------------------\n"); 

            fclose(DB); 

            system("cls");;
            printf("======================\n");
            printf("= Cadastro com sucesso =\n");
            printf("======================\n");
            Sleep(1);
            main();

        } else if(Global.Cd == 'n') {
            system("cls");;
            printf("Cadastro Cancelado.\nVoltando ao Menu Principal...\n");
            fclose(DB); 
            getchar();        
            Sleep(1);
            main();

        } else {
            printf("Valor inválido. Tente novamente...\n");
            fclose(DB); 
            Sleep(1);
            Cadastro();
        }
    }
} 

void Listar() {
    system("cls");;
    DB = fopen("clientes.txt", "r");

    if(DB == NULL) { 
        printf("\nErro no Banco de Dados...\n");
        return;

    } else {
        printf("======================\n");
        printf(" LISTAGEM DE CLIENTES\n");
        printf("======================\n\n");

        char mostragem[250]; 

        while(fgets(mostragem, 250, DB) != NULL) {
            printf("%s", mostragem);

        } 
        fclose(DB);

        printf("\nVoltar ao Menu Principal? [s/n]: ");
        scanf("%c", &Global.Cd);

        if(Global.Cd == 's') {
            main();

        } else if(Global.Cd != 's' && Global.Cd != 'n') {
            printf("Valor inválido.\nVoltando ao Menu Principal...\n");
            Sleep(1);
            main();
        }
    }
}
