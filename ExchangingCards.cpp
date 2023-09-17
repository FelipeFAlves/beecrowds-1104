#include <bits/stdc++.h>
// Felipe Ferreira Alves - 2021020653
int checarseExiste(int num, int cartasVistas[],int tam){
    int i;
    for(i=0;i<tam;i++){
        if(num == cartasVistas[i]){
            return 1; //Se a carta diferente já foi vista
        }
    }

    return 0; // Se pode add
}

int main(){
    int nA,nB; // Numero de cartas de Alice e Betty
    int *cartasA,*cartasB; // Vetor para guardar as cartas de Alice e Betty
    int *cartasDiff; // Vetor para guardar as cartas repetidas
    int nCartasDiff=0, add=1,trocaA=0,trocaB=0;

    while (1)
    {
        scanf("%d %d",&nA, &nB);
        nCartasDiff = 0;
        trocaA = 0;
        trocaB = 0;
        
        if(nA == 0 && nB == 0){
            break;
        }

        if (nA>nB){
            cartasDiff = (int *) malloc (nA * sizeof(int));
        } else {
            cartasDiff = (int *) malloc (nB * sizeof(int));
        }

        cartasA = (int*) malloc (nA * sizeof(int));
        cartasB = (int*) malloc (nB * sizeof(int));

        for (int i=0;i<nA;i++){ // Populando as cartas A
            scanf("%d",&cartasA[i]);
        }

        for (int i=0;i<nB;i++){ // Populando as cartas B
            scanf("%d",&cartasB[i]);
        }

        for (int i=0;i<nB;i++){ // comparar todos valores de A com um valor de B
            add = 1;
            for (int j=0;j<nA;j++){
                if(cartasA[j] == cartasB[i]){
                    add = 0; // não pode adicionar na lista de troca pq é uma carta repetida
                    break;
                }
            }
            if (add == 1){ // Pode adicionar
                if (nCartasDiff==0){ // Se for o primeiro valor diferente
                    cartasDiff[nCartasDiff] = cartasB[i];
                    nCartasDiff++;
                    trocaA++;
                } else { // Verifica se o numero já foi visto para n ter carta repetida
                    int repetida = checarseExiste(cartasB[i],cartasDiff,nCartasDiff);
                    if (repetida == 0){
                        cartasDiff[nCartasDiff] = cartasB[i];
                        trocaA++;
                        nCartasDiff++;
                    }
                }
            }
        }
        for(int x=0;x<nCartasDiff;x++){ // Limpando o vetor
            cartasDiff[x] = '\0';
        }
        nCartasDiff = 0;

        for (int i=0;i<nA;i++){ // comparar todos valores de B com um valor de A
            add = 1;
            for (int j=0;j<nB;j++){
                if(cartasB[j] == cartasA[i]){
                    add = 0; // não pode adicionar na lista de troca pq é uma carta repetida
                    break;
                }
            }
            if (add == 1){ // Pode adicionar
                if (nCartasDiff==0){ // Se for o primeiro valor diferente
                    cartasDiff[nCartasDiff] = cartasA[i];
                    nCartasDiff++;
                    trocaB++;
                } else { // Verifica se o numero já foi visto para n ter carta repetida
                    int repetida = checarseExiste(cartasA[i],cartasDiff,nCartasDiff);
                    if (repetida == 0){
                        cartasDiff[nCartasDiff] = cartasA[i];
                        trocaB++;
                        nCartasDiff++;
                    }
                }
            }
        }
        if(trocaA <= trocaB){
            printf("%d\n",trocaA);
        } else{
            printf("%d\n",trocaB);
        }
        
    }

    
    free(cartasA);
    free(cartasB);
    return 0;
}
    