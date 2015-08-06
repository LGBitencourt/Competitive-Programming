#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 100000

int main() {
    int n, valor, sinal, new_sinal, casa_soma, a, b, i;
    long long int soma_final;
    
    while(scanf("%d", &n) != EOF) {
        long long int soma[MAX];
        soma[0] = 0;
        sinal = a = -1;
        casa_soma = soma_final = 0;
        valor = 0;
        new_sinal = -1;
        b = 0;
        i = 0;

        for(i = 0; i < n; i++) {
            scanf("%d", &valor);
            new_sinal = valor == 0 ? sinal : valor > 0 ? 0 : 1;
            
            if (a == -1 && new_sinal == 1) a = casa_soma;
            if (sinal == -1) {
                sinal = new_sinal;
            } else if (sinal != new_sinal) {
                casa_soma++;
                soma[casa_soma] = 0;
                sinal = new_sinal;
            }

            soma[casa_soma] += valor;
        }
        for (i = 0; i <= casa_soma; i++) printf("[SOMA %d] %d\n", i, soma[i]);
        if (a == -1) printf("0\n");
        else if (casa_soma == 2 && a == 1) printf("%d\n", soma[1]);
        else {
            soma_final = soma[casa_soma];
            for(i = casa_soma; i >= 0; i--) {
                if (soma[i] < soma_final) soma_final = soma[i];
                if (soma[i] > 0) continue;
                if (i > 2 && soma[i] + soma[i-1] < 0) {
                    soma[i-2] += soma[i];
                    soma[i-2] += soma[i-1];
                }
            }

            printf("%d\n", -soma_final);
        }

        
    }

    return 0;
}
