#include <stdio.h>
#include <locale.h>

#define PRODUTOS 3
#define DIAS 5
#define PRECO_BRIGADEIRO 3.00f
#define PRECO_CUPCAKE 5.00f
#define PRECO_SUCO 4.00f

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    //Definir colunas
    int vendas[DIAS][PRODUTOS] = {
        {10, 5, 8}, 
        {15, 7, 12},
        {12, 20, 10},
        {8, 10, 15},
        {20, 15, 30} 
    };
    
    // preços de produto
    float precos[PRODUTOS] = {PRECO_BRIGADEIRO, PRECO_CUPCAKE, PRECO_SUCO};
    
    // dias da semana
    char *dias_nome[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta"};
    
    int op, i, j, brigadeiros_max = -1, dia_max_brigadeiro = 0, dia_max_arrecadacao = 0;
    float dia_arrecadacao, arrecadacao_maior = 0, total_semana = 0;

    // Processamento dos dados
    for(i = 0; i < DIAS; i++){
        dia_arrecadacao = 0; // Zerar a arrecadação do dia antes de somar os produtos
        
        for(j = 0; j < PRODUTOS; j++){
            // dia de arrecadação recebe as vendas e o preço
            dia_arrecadacao += vendas[i][j] * precos[j];
        }
        
        total_semana += dia_arrecadacao; // o dia que foi arrecadado
            
        //Dia com mais brigadeiros
        if(vendas[i][0] > brigadeiros_max){
            brigadeiros_max = vendas[i][0];
            dia_max_brigadeiro = i;
        }

        //maior arrecadação
        if(dia_arrecadacao > arrecadacao_maior){
            arrecadacao_maior = dia_arrecadacao;
            dia_max_arrecadacao = i;
        }
    }
    
	do{
        printf("\n=== Menu ===\n");
        //a) Quantos cupcakes foram vendidos na quarta-feira?
        printf("1 - Quantos cupcakes foram vendidos na quarta-feira?\n");
        //b) Qual foi a quantidade de sucos vendidos na sexta-feira?
        printf("2 - Qual foi a quantidade de sucos vendidos na sexta-feira?\n");
        //c) Em qual dia foram vendidos mais brigadeiros?
        printf("3 - Em qual dia foram vendidos mais brigadeiros?\n");
        //d) Qual foi o dia com maior arrecadação?
        printf("4 - Qual foi o dia com maior arrecadação?\n");
        //e) Quanto a turma arrecadou ao todo na semana?
        printf("5 - Quanto a turma arrecadou ao todo na semana?\n");
        //meta
        printf("6 - Meta\n");
        // sair
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch(op)
        {
        	case 0:
        	    printf("\nSaindo...\n");
    			break;
            case 1:
                printf("\nForam vendidos %d cupcakes na %s\n", vendas[2][1], dias_nome[2]);
                break;
            case 2:
                printf("\nVendas: %d sucos na %s\n", vendas[4][2], dias_nome[4]);
                break;
            case 3:
                printf("\nDia com mais brigadeiros: %s (%d vendidos)\n", dias_nome[dia_max_brigadeiro], brigadeiros_max);
                break;
            case 4:
                printf("\nDia com maior arrecadação: %s (R$ %.2f)\n", dias_nome[dia_max_arrecadacao], arrecadacao_maior);
                break;
            case 5:
                printf("\nTotal arrecadado na semana: R$ %.2f\n", total_semana);
                break;
            case 6:
                if (total_semana >= 1000.00) {
                    printf("\nf) Sim, a meta de R$1000.00 foi atingida!\n");
                } else {
                    printf("\nf) Não, faltaram R$ %.2f para a meta.\n", 1000.00 - total_semana);
                }
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
	}while(op != 0);
}
