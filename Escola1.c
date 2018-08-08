#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "header.h"

void Menu();
void limpabuffer(void);
void DataEmNumero();
int validarData(char *data);

void CadastroAlunos();
void CadastroProfessores();
void CadastroDisciplina();

void ListarAluno();
void ListarProfessores();


#define MaxTAM 100
#define MaxNomeTAM 50
#define MaxCPF 15
#define MaxCadastro 5


struct DMA {
	int dia;
	int mes;
	int ano;
}; typedef struct DMA dma;

struct ALUNOS { 
	int matricula;
	char nome[MaxNomeTAM];
	char sexo; //M - Masculino F - Feminino
	char cpf[MaxCPF];
	struct DMA dataNascimento;
}; typedef struct ALUNOS alunos;

struct PROFESSOR { 
	int matricula;
	char nome[MaxNomeTAM];
	char sexo; //M - Masculino F - Feminino
	char cpf[MaxCPF];
	struct DMA dataNascimento;
}; typedef struct PROFESSOR professor;

struct DISCIPLINA{
	char name[MaxNomeTAM];
	int codigo;
	int semestre;
	int MatriculaProfDisciplina;
}; typedef struct DISCIPLINA disciplina;



int main () {
	
	int LerOpcaoInicial, sair = 0;

	while (!sair) {  //!Menu
			printf("\n\n\n");		
		puts("###   Bem vindo ao Sistema de Controle Escolar   ###");
			printf("\n");
		puts("Escolha uma das opcoes a seguir para iniciar: ");
			printf("\n\n");
		
		Menu(LerOpcaoInicial);

			printf("\n\n");

		scanf("%d", &LerOpcaoInicial);

		switch (LerOpcaoInicial) {
			case 0 :{
				puts("Sessao Finalizada!!");
				printf("\n************************************************************\n");
				sair = 1;
				break;
			}
			
			case 1 :{  //!Cadastrar Alunos
				system("clear");
					printf("\n");					
				CadastroAlunos();
				break;
			}

			case 2 :{  //!Cadastrar Professor
				system("clear");
					printf("\n");					
				CadastroProfessores();
				break;
			}

			case 3 :{ //!Cadastrar Disciplina
				system("clear");
					printf("\n");					
				CadastroDisciplina();
				break;
			}

			case 4 :{ //! Listar Alunos
				system("clear");
					printf("\n");
				ListarAluno();
				break;
			}

			case 5 :{ //! Listar Professores
				system("clear");
					printf("\n");
				ListarProfessores();
				break;
			}

		/*------------------------------------END SWITCH------------------------------------------------*/
			default:{
				printf("Opção Inválida\n");
			}
		}
	}

  return 1;

}

void Menu(int LerOpcaoInicial){
		puts("[0] - Sair");
		puts("[1] - Cadastrar Aluno");
		puts("[2] - Cadastrar Professor");
		puts("[3] - Cadastrar Disciplina");
		puts("[4] - Listar Alunos");
		puts("[5] - Listar Professores");
		//puts("[6] - Listar Disciplinas");


}

void CadastroAlunos(){
	alunos CadastroAluno;
	alunos listaAluno[MaxCadastro];
	int qtd_alunos = 0;

	system("clear");
	puts("###  Sistema de Cadastro de Aluno  ###");
	printf("\n\nDigite a matricula: ");
		scanf("%d", &listaAluno[qtd_alunos].matricula);
		getchar();
		setbuf(stdin,NULL);
			

	printf("\nDigite o nome: "); //Entrada do Nome
		fgets(listaAluno[qtd_alunos].nome, MaxNomeTAM, stdin);
			size_t ln = strlen(listaAluno[qtd_alunos].nome) - 1; //size_t = unsigned integer type
				if(listaAluno[qtd_alunos].nome[ln] == '\n'){
					listaAluno[qtd_alunos].nome[ln] = '\0';
				}
					

	printf("\nDigite o sexo (M - Masculino / F - Feminino): ");//Entrada do Sexo
		scanf("%c", &listaAluno[qtd_alunos].sexo);
			

	printf("\nDigite a data de nascimento (dd/mm/aaaa: ");//Entrada do Nascimento
		scanf("%d/%d/%d", &listaAluno[qtd_alunos].dataNascimento.dia, &listaAluno[qtd_alunos].dataNascimento.mes, &listaAluno[qtd_alunos].dataNascimento.ano);
			getchar();
				

	printf("\nDigite o CPF: ");//Entrada do CPF
		fgets(listaAluno[qtd_alunos].cpf, MaxCPF, stdin);
			ln = strlen(listaAluno[qtd_alunos].cpf) - 1;
				if (listaAluno[qtd_alunos].cpf[ln] == '\n'){
					listaAluno[qtd_alunos].cpf[ln] = '\0';
				}
	qtd_alunos++;

	printf("\n");
		system("clear");

}

void CadastroProfessores(){

	professor CadastroProfessor;
	professor listaProf[MaxCadastro];
	int qtdProf = 0;

	puts("###  Sistema de Cadastro de Professor  ###");
		printf("\n\nDigite a matricula: ");
			scanf("%d", &listaProf[qtdProf].matricula);
				getchar();
			setbuf(stdin,NULL);
		

	printf("\nDigite o nome: "); //Entrada do Nome
		fgets(listaProf[qtdProf].nome, MaxNomeTAM, stdin);
			size_t ln = strlen(listaProf[qtdProf].nome) - 1; //size_t = unsigned integer type
				if(listaProf[qtdProf].nome[ln] == '\n'){
					listaProf[qtdProf].nome[ln] = '\0';
				}
				

	printf("\nDigite o sexo (M - Masculino / F - Feminino): ");//Entrada do Sexo
		scanf("%c", &listaProf[qtdProf].sexo);
	

	printf("\nDigite a data de nascimento (dd/mm/aaaa: ");//Entrada do Nascimento
		scanf("%d/%d/%d", &listaProf[qtdProf].dataNascimento.dia, &listaProf[qtdProf].dataNascimento.mes, &listaProf[qtdProf].dataNascimento.ano);
			getchar();
			

	printf("\nDigite o CPF: ");//Entrada do CPF
		fgets(listaProf[qtdProf].cpf, MaxCPF, stdin);
			ln = strlen(listaProf[qtdProf].cpf) - 1;
				if (listaProf[qtdProf].cpf[ln] == '\n'){
					listaProf[qtdProf].cpf[ln] = '\0';
				}
	qtdProf++;

	printf("\n");
		system("clear");

}

void CadastroDisciplina(){
		disciplina CadastroDisciplina;
		disciplina listaDisciplina[MaxCadastro];
		int qtd_alunos_disciplina = 0, qtdDisciplina = 0;
		
		int LerOpcaoInicial, out = 0;
		int matricula_professor;
	
	while(!out){		
		puts("Escolha uma das opcoes a seguir para iniciar: ");
			printf("\n");
		puts("[0] - Sair");
		puts("[1] - Cadastrar Disciplina");
		puts("[2] - Inserir Aluno em Disciplina");
		puts("[3] - Excluir Aluno em Disciplina");

			printf("\n");

		scanf("%d", &LerOpcaoInicial);

		switch (LerOpcaoInicial){
			case 0 :{
				puts("Sessao Finalizada!!");
				printf("\n************************************************************\n");
				out = 1;
				break;
			}
			
			case 1:{
				puts("###  Cadastro de Disciplina  ###");

					setbuf(stdin,NULL);

					printf("\n\nDigite o nome da Disciplina: ");
						fgets(listaDisciplina[qtdDisciplina].name, MaxNomeTAM, stdin);
							size_t ln = strlen(listaDisciplina[qtdDisciplina].name) - 1;
								if(listaDisciplina[qtdDisciplina].name[ln] == '\n'){
									listaDisciplina[qtdDisciplina].name[ln] = '\0';
								}			

				printf("\n\nDigite o Codigo da Disciplina: ");
					scanf("%d", &listaDisciplina[qtdDisciplina].codigo);
						getchar();
					setbuf(stdin,NULL);

				printf("\n\nDigite o Semestre da Disciplina: ");
					scanf("%d", &listaDisciplina[qtdDisciplina].semestre);
						getchar();
					setbuf(stdin,NULL);

				printf("\n\nInforme o numero de matricula do Professor da Disciplina: ");
					scanf("%d", &listaDisciplina[qtdDisciplina].MatriculaProfDisciplina);
						getchar();
					setbuf(stdin,NULL);

				break;

			}

			/*case 2:{

				break;
			}*/
			system("clear");
			default:{
				printf("Opção Inválida\n");
			}

		}
	
	}

}

void ListarAluno(){
	alunos CadastroAluno;
	alunos listaAluno[MaxCadastro];
	int qtd_alunos = 0;

	puts("###  Lista de Alunos Cadastrados  ###");
			
	for(int i = 0; i < qtd_alunos; i++){
		printf("Matrícula: %d\n", listaAluno[i].matricula);
		printf("Nome: %s\n", listaAluno[i].nome);
		printf("Sexo: %c\n", listaAluno[i].sexo);
		printf("Data Nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes, listaAluno[i].dataNascimento.ano);
		printf("CPF: %s\n", listaAluno[i].cpf);
	}
}

void ListarProfessores(){
	professor CadastroProfessor;
	professor listaProf[MaxCadastro];
	int qtdProf = 0;

	puts("###  Lista de Professores Cadastrados  ###");
	
	for(int i = 0; i < qtdProf; i++){
		printf("Matrícula: %d\n", listaProf[i].matricula);
		printf("Nome: %s\n", listaProf[i].nome);
		printf("Sexo: %c\n", listaProf[i].sexo);
		printf("Data Nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia, listaProf[i].dataNascimento.mes, listaProf[i].dataNascimento.ano);
		printf("CPF: %s\n", listaProf[i].cpf);
	}

}


/***************************************************************************************************************/


void limpabuffer(void){ //*Funcao para limpar o buffer do teclado
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void DataEmNumero(char *data, int *dia, int *mes, int *ano) {

    int i = 0, j, cont, parada = 0, condicao = 0;
    char string[5];

    for(j = 0; j < 3; j++) {
        cont = 0;
        while(i < strlen(data)) {

            if(data[i] - 47 == 0)
                break;
            if(((data[i] - 48 < 0) && (data[i] - 48 > 9)) || (data[i] - 48 < 0) || (data[i] - 48 > 9)) {
                parada = 1;
                break;
            } else if(data[i] - 48 >= 0 && data[i] - 48 <= 9) { //?demais numeros
                string[cont++] = data[i];
            }
            i++;
        }

        if(parada) {
            condicao = 1;
            break;
        }

        string[cont] = '\0'; //?para não pegar lixo

        if(j == 0 && cont <= 2) //?cont <= 2 para limitar a quantidade de casas
            *dia = atoi(string);
        else if(j == 1 && cont <= 2)
            *mes = atoi(string);
        else if(j == 2 && (cont == 2 || cont == 4))
            *ano = atoi(string);
        else
            condicao = 1;

        i++;
    }

    if(condicao)
        *dia = *mes = *ano = 0;
}
int validarData(char *data) {

    int datavalida = 1;
    dma DATA;

    DataEmNumero(data, &DATA.dia, &DATA.mes, &DATA.ano);

    if(DATA.ano >= 10 && DATA.ano <= 9999) { // checa o ano

        if (DATA.mes >= 1 && DATA.mes <= 12) { // checa o mes

            if ((DATA.dia >= 1 && DATA.dia <= 31) && (DATA.mes == 1 || DATA.mes == 3 || DATA.mes == 5 || DATA.mes == 7 || DATA.mes == 8  || DATA.mes == 10 || DATA.mes == 12)) {
                datavalida = 1; // checa os meses que tem 31 dias
            }
            else if ((DATA.dia >= 1 && DATA.dia <= 30) && (DATA.mes == 4 || DATA.mes == 6 || DATA.mes == 9 || DATA.mes == 11)) {
                datavalida = 1; // checa os meses que tem 30 dias
            }
            else if (DATA.dia >=1 && DATA.dia <= 28 && DATA.mes == 2) {
                datavalida = 1; // valida as datas do mes 2
            }

            else if (DATA.dia == 29 && DATA.mes == 2 && (DATA.ano % 400 == 0 || (DATA.ano % 4 ==0 && DATA.ano % 100 != 0))) {
                datavalida = 1; // checa o ano bissexto e imprime informando
            }

            else {
                datavalida = 0; // informa caso DIA inserido for invalido
            }
        }
        else {
            datavalida = 0; // informa caso MES inserido for invalido
        }
    }

    else {
        datavalida = 0; // informa caso ANO inserido for invalido
    }

    if (datavalida)
        return 1;
    else
        return 0;

}