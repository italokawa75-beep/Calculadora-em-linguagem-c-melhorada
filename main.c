#include <stdio.h>   // biblioteca para entrada e saída (printf, scanf)
#include <math.h>    // biblioteca matemática (pow, sqrt, sin, cos, etc)
#include <stdlib.h>   // biblioteca padrão


#define MAX_HISTORICO 50 // Define o tamanho máximo do histórico de operações


struct Calculo { // Estrutura para armazenar cada cálculo realizado
    double num1;
    double num2;
    int operador;
    double resultado;
};



struct Calculo historico[MAX_HISTORICO]; // Array para armazenar o histórico de operações
int contador_historico = 0; // Contador para o número de operações no histórico

void salvar_historico(double n1, double n2, int op, double res){ // Função para salvar operações no histórico
    if (contador_historico < MAX_HISTORICO){ // Verifica se há espaço no histórico
        historico[contador_historico].num1 = n1; // Salva os dados na estrutura
        historico[contador_historico].num2 = n2; 
        historico[contador_historico].operador = op;
        historico[contador_historico]. resultado = res; // Salva o resultado
        
        
        contador_historico++;
        
    } else {
        printf("Atenção; historico lotado. Ultima operação não salva\n");
    }
}


void exibir_historico(){ // Função para exibir o histórico de operações
    printf("\n Historico de operações (%d registradas)", contador_historico);
    
    if (contador_historico == 0){ // Verifica se há operações no histórico
        printf("Nenhuma operação registrada\n");
        return;
    }
    
    for (int i = 0; i < contador_historico; i++){
        
        struct Calculo op = historico[i]; // Recupera a operação do histórico
            printf("[%d]", i + 1);
            
        switch (op.operador){ // Exibe a operação com base no operador
            
            case 1:
            printf("%.2lf + %.2lf = %.2lf\n", op.num1, op.num2, op.resultado);
                break;
                
                case 2: // Subtração 
                printf("%.2lf - %.2lf = %.2lf\n", op.num1, op.num2, op.resultado);
                break;
                
            case 3: // Multiplicação 
                printf("%.2lf * %.2lf = %.2lf\n", op.num1, op.num2, op.resultado);
                break;
                
                case 4: // Divisão
                printf("Divi: %.2lf / %.2lf = %.2lf\n", op.num1, op.num2, op.resultado);
                break;
                
                
            case 5: // Potência
                printf("Potencia: %.2lf ^ %.2lf = %.2lf\n", op.num1, op.num2, op.resultado);
                break;
                
            
            case 6: // Raiz Quadrada 
                printf("sqrt(%.2lf) = %.2lf\n", op.num1, op.resultado);
                break;
                
            case 7: // Seno 
                printf("Seno: sin(%.2lf graus) = %.4lf\n", op.num1, op.resultado);
                break; 
                
            case 8: // Cosseno 
                printf("Cosseno: cos(%.2lf graus) = %.4lf\n", op.num1, op.resultado);
                break;
                
            case 9: // Tangente 
                printf("Tangente: tan(%.2lf graus) = %.4lf\n", op.num1, op.resultado);
                break;
                
            case 10: // Logaritmo Natural 
                printf("Log. Natural: ln(%.2lf) = %.4lf\n", op.num1, op.resultado);
                break;
                
            case 11: // Logaritmo Base 10 
                printf("Log. Base 10: log10(%.2lf) = %.4lf\n", op.num1, op.resultado);
                break;
                
            case 12: // Exponencial 
                printf("Exponencial: e^(%.2lf) = %.4lf\n", op.num1, op.resultado);
                break;
                
            case 13: // Média Aritmética 
                printf("Média Aritmética de 4 Nums. = %.2lf\n", op.resultado);
                break;
                
            case 14: // Valor Absoluto 
                printf("Absoluto: |%.2lf| = %.2lf\n", op.num1, op.resultado);
                break;
            case 15: // Arredondar para o menor inteiro 
                printf("Arredondar p/ cima (ceil): %.2lf => %.0lf\n", op.num1, op.resultado);
                break;
                
            case 16: // Arredondar para o mais próximo 
                printf("Arredondar p/ prox (round): %.2lf => %.0lf\n", op.num1, op.resultado);
                break;
                
            case 17: // Arredondar para o maior inteiro que não é maior que x
                printf("Arredondar p/ baixo (floor): %.2lf => %.0lf\n", op.num1, op.resultado);
                break;
                
            case 18: // Fatorial 
                // Usamos %.0lf para números inteiros grandes
                printf("Fatorial: %.0lf! = %.0lf\n", op.num1, op.resultado);
                break;
            case 19: // Arco Seno
                printf("Arcoseno: asin(%.2lf) = %.2lf graus\n", op.num1, op.resultado);
                break;
            case 20: // Arco Cosseno 
                printf("Arcocosseno: acos(%.2lf) = %.2lf graus\n", op.num1, op.resultado);
                break;
            
            case 21: // Arco Tangente 
                printf("Arcotangente: atan(%.2lf) = %.2lf graus\n", op.num1, op.resultado);
                break;
                
            case 22: // Resto da divisão 
              
                printf("Resto da Divisão: %d %% %d = %d\n", (int)op.num1, (int)op.num2, (int)op.resultado);
                break;
            default: 
                printf("Operação desconhecida: %d. Resultado: %.2lf\n", op.operador, op.resultado);
                break;   
                
            case 24: // Soma de Matrizes
    printf("Soma de Matrizes (2x2). Resultado exibido na tela.\n");
    break;
    
            case 25: // Multiplicação de Matrizes
    printf("Multiplicação de Matrizes (2x2). Resultado exibido na tela.\n");
    break;
    

        }
    }
    printf("====================================================\n");
}



void imprimir_matriz(double matriz[2][2], char *nome) { // Função para imprimir uma matriz 2x2
    printf("\n--- Matriz %s ---\n", nome); 
    for (int i = 0; i < 2; i++) { // Laço para linhas
        printf("|");
        for (int j = 0; j < 2; j++) { // Laço para colunas
            printf(" %7.2lf ", matriz[i][j]);
        }
        printf("|\n"); 
    }
    printf("-------------------\n");
}



// FUNÇÃO: SOMA MATRIZES 2x2
void somar_matrizes(double A[2][2], double B[2][2], double C[2][2]) {
    // Laço para linhas
    for (int i = 0; i < 2; i++) {  
        // Laço para colunas
        for (int j = 0; j < 2; j++) { 
            C[i][j] = A[i][j] + B[i][j];  // Soma o elemento de A com o elemento de B e guarda em C.
        }
    }
}



// FUNÇÃO: MULTIPLICA MATRIZES 2x2
void multiplicar_matrizes(double A[2][2], double B[2][2], double C[2][2]) {
    // Zera todos os elementos da matriz C antes de multiplicar.
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0.0;
        }
    }

    
    for (int i = 0; i < 2; i++) { // Laço para linhas de A
        for (int j = 0; j < 2; j++) { // Laço para colunas de B
            for (int k = 0; k < 2; k++) { // Laço para somar os produtos
                C[i][j] += A[i][k] * B[k][j]; // Multiplica e acumula o valor em C
            }
        }
    }
}






int main() {
   double num1, num2, num3,num4, resultado, media; // Variáveis de cálculo (double).
   double A[2][2], B[2][2], C[2][2];  // Matrizes de entrada (A, B) e saída (C). Arrays 2x2.
   int operador;  // Variável para a opção do menu.
   char continuar; // Variável de controle de repetição do programa
   int contador = 0;   // Contador s para laços e histórico.

              // Menu de opções
   do {  //função para colocar a calculadora em loop 
       
   printf("\n=== CALCULADORA CIENTIFICA ===\n");
   printf("1 - Soma\n");
   printf("2 - Subtração\n");
   printf("3 - Multiplicação\n");
   printf("4 - Divisão\n");
   printf("5 - Potência (a^b)\n");
   printf("6 - Raiz Quadrada\n");
   printf("7 - Seno\n");
   printf("8 - Cosseno\n");
   printf("9 - Tangente\n");
   printf("10 - Logaritmo natural (ln)\n");
   printf("11 - Logaritmo base 10\n");
   printf("12 - Exponencial (e^x)\n");
   printf("13 - Media Aritmetica\n");
   printf("14 - Valor Absoluto\n");
   printf("15 - Arredondar para o menor numero inteiro\n");
   printf("16 - Arredondar para o inteiro mais proximo\n");
   printf("17 - Arredondar para o maior valor inteiro que não é maior que x\n");
   printf("18 - Fatorial de um número\n");
   printf("19 - Arco seno\n");
   printf("20 - Arco Cosseno\n");
   printf("21 - Arco Tangente\n");
   printf("22 - Resto da divisão\n");
   printf("23 - Exibir Historico\n");
   printf("24 - Soma de matrizes\n");
   printf("25 - Multiplicações de matrizes (2x2)\n");
   printf("26 - Sair\n");
   printf("Escolha uma opção (1 a 26): ");
   scanf(" %d", &operador);
  
   switch (operador) {
      case 1:  // Soma
      printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
    printf("Digite o segundo número: ");
   scanf("%lf", &num2);
        resultado = num1 + num2;    // Função para somar dois números
        printf("Resultado: %.2f\n", resultado);
        
        salvar_historico(num1, num2, operador, resultado); // Salva no histórico isso para as 26 cases também nao vou repetir isso em todas mais é isso :)
        break;
        
        
        
        
        
        case 2:  // Subtração
         printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
    printf("Digite o segundo número: ");
   scanf("%lf", &num2);
        resultado = num1 - num2;  // Função para subtrair dois números
        printf("Resultado: %.2f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
        
        
        
        
        case 3:   // Multiplicação
         printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
    printf("Digite o segundo número: ");
   scanf("%lf", &num2);
        resultado = num1 * num2; // Função para multiplicar dois números
        printf("Resultado: %.2f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
        
        

        
        case 4:  // Divisão
         printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
    printf("Digite o segundo número: ");
   scanf("%lf", &num2);
        if (num2 !=0) { // Função que impede divisão por zero
            resultado = num1 / num2; // Função para dividir dois números
            printf("Resultado: %.2f\n", resultado);
        } else {
            printf("Erro: Divisão por zero!\n");
        }
        salvar_historico(num1, num2, operador, resultado); 
        break;
        
        
        
        
        case 5: // Potência
         printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
    printf("Digite o segundo número: ");
   scanf("%lf", &num2);
        resultado = pow(num1, num2); // Função para calcular potência
        printf("Resultado: %.2f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
        
        
        
        
        case 6: // Raiz quadrada
         printf("Digite o primeiro número: ");
   scanf("%lf", &num1);
        if (num1 >= 0){ // raiz só existe para números >= 0
            resultado = sqrt(num1); // Função para calcular raiz quadrada
            printf("Resultado: %.2f\n", resultado);
            
            salvar_historico(num1, 0.0, operador, resultado);
        }else{
            printf("Erro raiz de numero negativo!\n");
        }
            break;
            
            
            
            
        case 7: // Seno
         printf("Digite o angulo em graus: ");
   scanf("%lf", &num1);
        resultado = sin(num1 * M_PI / 180); // Função para calcular seno
        printf("Resultado: %.4f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
        
        
        
        case 8: // Cosseno
         printf("Digite o angulo em graus: ");
   scanf("%lf", &num1);
        resultado = cos(num1 * M_PI / 180); // Função para calcular cosseno
        printf("Resultado: %.4f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
        
        
        
        case 9: // Tangente
         printf("Digite o angulo em graus: ");
   scanf("%lf", &num1);
        resultado = tan(num1 * M_PI / 180); // Função para calcular tangente
        printf("Resultado: %.4f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;
        
    
        
        
        case 10: // Logaritmo natural
         printf("Digite um número para ver o seu logaritmo natural: ");
   scanf("%lf", &num1);
        if (num1 > 0){
            resultado = log(num1); // Função para calcular logaritmo natural
            printf("Resultado: %.3f\n", resultado);
        }else{
            printf("Erro logaritimo de numero negativo!\n");
        }
        salvar_historico(num1, num2, operador, resultado);
            break;
        
        
        
            case 11: // Logaritmo base 10
            printf("Digite um número para ver o seu logaritmo de base 10: ");
             scanf("%lf", &num1);
        if (num1 > 0){
                resultado = log10(num1); // Função para calcular logaritmo base 10
                printf("Resultado: %.2f\n", resultado);
        }else{
            printf("Erro logaritmo de numero não positivo!\n");
        }
        salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 12: // Exponencial
            printf("Digite o expoente x para a função (e^x): ");
            scanf("%lf", &num1);
            resultado = exp(num1); // Função para calcular exponencial 
            printf("Resultado: %.2f\n", resultado);
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 13: // Média aritmética
            printf("Digite o primeiro número: ");
            scanf("%lf", &num1);
            printf("Digite o segundo número: ");
            scanf("%lf", &num2);
            printf("Digite o terceiro número: ");
            scanf("%lf", &num3);
            printf("Digite o quarto número: ");
            scanf("%lf", &num4);
            
            media = (num1 + num2 + num3 + num4 ) / 4.0; // Função para calcular média aritmética
            salvar_historico(num1, num2, operador, resultado);
            printf("Resultado: %.2f\n", media);
            break;
            
            
            
            case 14: // Valor absoluto
            printf("Digite um número para ver o seu valor absoluto: ");
            scanf("%lf", &num1);
            resultado = abs(num1); // Função para calcular valor absoluto
            printf("Resultado: %.2f\n", resultado);
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 15: // Arredondar para o menor numero inteiro
            printf("Digite um número: ");
            scanf("%lf", &num1);
            resultado = ceil(num1); // Função para arredondar para o menor numero inteiro
            printf("Resultado: %.2f\n", resultado);
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 16: // Arredondar para o inteiro mais próximo
            printf("Digite um número: ");
            scanf("%lf", &num1);
            
            resultado = round(num1); // Função para arredondar para o inteiro mais proximo
            printf("Resultado: %.2f\n", resultado);
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 17: // Arredondar maior numero inteiro que não é maior que x
            printf("Digite um número: ");
            scanf("%lf", &num1);
            resultado = floor(num1); // Função para arredondar para o maior valor inteiro que não é maior que x
            printf("Resultado: %.2f\n", resultado);
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 18: // Fatorial
                printf("Digite um número para ver o seu fatorial: ");
                scanf("%lf", &num1);
            if (num1 < 0 || floor(num1) != num1) { // só funciona para inteiros positivos
                printf("Erro numero negativo!");
            } else { 
                int n = (int)num1;
                long long fat = 1; // começa o fatorial em 1
                for (int i = 1; i <= n; i++) { // Multiplica de 1 até n
            fat *= i;
                }
                printf("Resultado: %.2lld\n", fat);
            }
            salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            
            case 19: // Arco seno 
             printf("Digite um numero entre -1 e 1 para ver o seu arco do seno: ");
   scanf("%lf", &num1);
   if (num1 < -1 || num1 > 1) {
        printf("Erro! O valor deve estar entre -1 e 1.\n");
    } else {
        
        resultado = asin(num1); // Função para calcular arco seno
        resultado = resultado * 180 / M_PI;
        printf("Resultado: %.2f\n", resultado);
    }
    salvar_historico(num1, num2, operador, resultado);
        break;
            
            
            case 20: // Arco cosseno
            printf("Digite um numero entre -1 e 1 para ver o seu arco do cosseno: ");
   scanf("%lf", &num1);
   if (num1 < -1 || num1 > 1) {
        printf("Erro! O valor deve estar entre -1 e 1.\n");
    } else {
        
        resultado = acos(num1); // Função para calcular arco cosseno
        resultado = resultado * 180 / M_PI;
        printf("Resultado: %.2f\n", resultado);
    }
    salvar_historico(num1, num2, operador, resultado);
            break;
            
            
            case 21: // Arco tangente
             printf("Digite um numero real para ver o seu arco da tangente: ");
   scanf("%lf", &num1);
        resultado = atan(num1); // Função para calcular arco tangente
        resultado = resultado * 180 / M_PI;
        printf("Resultado: %.2f\n", resultado);
        salvar_historico(num1, num2, operador, resultado);
        break;    
            
          
          
           
           
           case 22: // Resto da divisão
    printf("Digite o primeiro número inteiro: ");
    scanf("%lf", &num1);
    printf("Digite o segundo número inteiro: ");
    scanf("%lf", &num2);
    if ((int)num2 != 0) { //Função para calcular módulo (resto da divisão)
        int resto = (int)num1 % (int)num2;
        printf("O resto da divisão é: %d\n", resto);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    salvar_historico(num1, num2, operador, resultado);
        break;
           
            
            case 23: // Exibir historico
            exibir_historico();
            break;
            
            
            
            
            case 24: // Soma de Matrizes 2x2
    printf("--- Leitura da Matriz 1 (A) ---\n");
                for (int i = 0; i < 2; i++) { // Laço para linhas
                    for (int j = 0; j < 2; j++) { // Laço para colunas
                        printf("Elemento A[%d][%d]: ", i + 1, j + 1); // Solicita o elemento da matriz A
                        scanf("%lf", &A[i][j]); 
                    }
                }
                
                printf("--- Leitura da Matriz 2 (B) ---\n");
                for (int i = 0; i < 2; i++) { // Laço para linhas
                    for (int j = 0; j < 2; j++) { // Laço para colunas
                        printf("Elemento B[%d][%d]: ", i + 1, j + 1); // Solicita o elemento da matriz B
                        scanf("%lf", &B[i][j]); 
                    }
                }
                somar_matrizes(A, B, C);  // Chama a função para somar as matrizes A e B, armazenando o resultado em C
                
                imprimir_matriz(A, "A"); // Imprime a matriz A
                printf("  + \n");
                imprimir_matriz(B, "B");// Imprime a matriz B
                printf("  = \n");
                imprimir_matriz(C, "Resultado"); 
                
                salvar_historico(0.0, 0.0, operador, 0.0);
                break;


case 25: // Multiplicação de Matrizes 2x2
    printf("--- Leitura da Matriz 1 (A) ---\n");
                for (int i = 0; i < 2; i++) { // Laço para linhas
                    for (int j = 0; j < 2; j++) { // Laço para colunas
                        printf("Elemento A[%d][%d]: ", i + 1, j + 1);   // Solicita o elemento da matriz A
                        scanf("%lf", &A[i][j]);  // Lê o elemento da matriz A
                    }
                }
                
                printf("--- Leitura da Matriz 2 (B) ---\n");
                for (int i = 0; i < 2; i++) { // Laço para linhas
                    for (int j = 0; j < 2; j++) {   // Laço para colunas
                        printf("Elemento B[%d][%d]: ", i + 1, j + 1);  // Solicita o elemento da matriz B
                        scanf("%lf", &B[i][j]);  
                    }
                }
                
                multiplicar_matrizes(A, B, C);  // Chama a função para multiplicar as matrizes A e B, armazenando o resultado em C
                imprimir_matriz(A, "A"); // Imprime a matriz A
                printf("  x \n"); 
                imprimir_matriz(B, "B");
                printf("  = \n");
                imprimir_matriz(C, "Resultado");
                salvar_historico(0.0, 0.0, operador, 0.0);
                break;
    
    
    

case 26: // Sair 
    printf("Saindo da calculadora, obrigado por utilizar!!");
    return 0;
    break;
            
            
            
            
        default: // caso a escolha for inválida
        printf("Opção invalida!\n");
   }
   // Pergunta se o usuário quer continuar
   printf("Deseja realizar outra operação? (s/n) s=sim n=não: ");
   scanf("%s", &continuar);

} while (continuar == 's' || continuar == 'S'); // Função que continua o programa se digitar 's'
   
   printf("Obrigado por utilizar a calculadora!!");
   
   return 0; // fim do programa

 }