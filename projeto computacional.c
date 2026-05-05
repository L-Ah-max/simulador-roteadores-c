#include <stdio.h>
#include <stdlib.h>

int main() {
    int linha, col, a, k, soma, somaSaida, qtdsaem = 0, qtdchega = 0;
    int fullduplex = 1, maiorconex = 0, total, m;

    printf("Qual é o numero de roteadores da sua rede: ");
    scanf("%d", &a);

    int matriz[a][a];
    int conexoes[a];


    for(linha = 0; linha < a; linha++) {
        for(col = 0; col < a; col++) {
            printf("Digite 1 se existe ligacao entre o roteador %d e o roteador %d, ou 0 caso contrario: ", linha, col);
            scanf("%d", &matriz[linha][col]);
        }
    }

    printf("\nMatriz de conexoes:\n");
    for(linha = 0; linha < a; linha++) {
        for(col = 0; col < a; col++) {
            printf("%d ", matriz[linha][col]);
        }
        printf("\n");
    }

    // A
    printf("\nDigite um roteador para ser analisado: ");
    scanf("%d", &k);

    qtdsaem = qtdchega = 0;
    for(col = 0; col < a; col++) {
        qtdsaem += matriz[k][col];
        qtdchega += matriz[col][k];
    }
    printf("\n Roteador %d -> Saidas: %d | Entradas: %d\n", k, qtdsaem, qtdchega);

    // B
    fullduplex = 1;
    for(col = 0; col < a; col++) {
        if(matriz[k][col] == 1 && matriz[col][k] == 0) {
            fullduplex = 0;
            break;
        }
    }
    if(fullduplex)
        printf("\n Todas as conexoes diretas do roteador %d sao full duplex.\n", k);
    else
        printf("\n Nem todas as conexoes diretas do roteador %d sao full duplex.\n", k);

    // C
    printf("\n Roteadores conectados diretamente ao roteador %d: ", k);
    for(col = 0; col < a; col++) {
        if(col != k && matriz[k][col] == 1) {
            printf("%d ", col);
        }
    }
    printf("\n");

    // D
    maiorconex = 0;
    for(col = 0; col < a; col++) {
        total = 0;
        for(linha = 0; linha < a; linha++) {
            total += matriz[linha][col] + matriz[col][linha];
        }
        conexoes[col] = total;
        if(total > maiorconex)
            maiorconex = total;
    }

    printf("\n Roteadores com o maior numero de conexoes (%d): ", maiorconex);
    for(col = 0; col < a; col++) {
        if(conexoes[col] == maiorconex)
            printf("%d ", col);
    }
    printf("\n");

    // E
    printf("\n Roteadores isolados: ");
    for(linha = 0; linha < a; linha++) {
        soma = 0;
        for(col = 0; col < a; col++) {
            soma += matriz[linha][col] + matriz[col][linha];
        }
        if(soma == 0)
            printf("%d ", linha);
    }

    printf("\n Roteadores sem saida: ");
    for(linha = 0; linha < a; linha++) {
        somaSaida = 0;
        for(col = 0; col < a; col++) {
            somaSaida += matriz[linha][col];
        }
        if(somaSaida == 0)
            printf("%d ", linha);
    }
    printf("\n");

    // F
    printf("\n Digite o tamanho da sequencia de roteadores: ");
    scanf("%d", &m);
    int caminho[m];
    printf("Digite a sequencia de roteadores: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &caminho[i]);
    }

    int valido = 1;
    for(int i = 0; i < m - 1; i++) {
        int comeco = caminho[i];
        int destino = caminho[i+1];

        if(comeco < 0 || comeco >= a || destino < 0 || destino >= a) {
            printf("Roteador %d ou %d invalido.\n", comeco, destino);
            valido = 0;
            break;
        }

        if(matriz[comeco][destino] != 1) {
            printf("Nao existe ligacao direta do roteador %d para o roteador %d.\n", comeco, destino);
            valido = 0;
            break;
        }
    }

    if(valido)
        printf("A sequencia de roteadores forma um caminho valido.\n");
    else
        printf("A sequencia de roteadores NAO forma um caminho valido.\n");

    return 0;
}



