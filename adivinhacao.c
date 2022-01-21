#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);
  
    int numerosecreto = rand() % 100;
    int chute;
    int tentativas = 0;

    double pontos = 1000;
    
    while(1){
        printf("Tentativa %d\n", tentativas + 1);
        printf("Qual é o seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Não pode digitar números negativos");
            continue;
        }

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Você acertou\n");
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }
        
        else {
            printf("Seu número foi menor que o número secreto\n");
        }

        tentativas++;
        // o C compila da direita para esquerda, entao devemos colocar 2.0
        // pois assim o valor que será atribuido a variavel pontos perdidos será
        // um double e nao um int ou podemos converter(casting).
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo\n");
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
}