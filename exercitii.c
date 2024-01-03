//
// Created by mihai on 1/2/2024.
//
#include <stdlib.h>
#include <stdio.h>
int flip_bits(int n){
    return ~n;
}
void print_bits(int n) {
    int aux = n;
    for (int i = 8 * sizeof(int) - 1; i >= 0; i--) {
        aux = n;
        aux = aux >> i;
        printf("%d", aux & 1);

    }
}

int is_power2(int n) {
    int power = 0;
    int aux;
    for (int i = 8 * sizeof(int) - 1; i >= 0; i--) {
        aux = n;
        aux = aux >> i;
        if (((aux & 1) == 1) && (power == 0)) {
            power += 1;
        } else if (((aux & 1) == 1) && (power == 1)) {
            printf("nu e putere a lui 2");
            power = 0;
            break;
        }
    }
    if (power == 1) {
        printf("e putere a lui 2");
    }

}

int is_even(int n) {
    int mask;
    mask = 1;
    int x = n & mask;
    if (x == 1) {

        printf("numarul este impar");
    } else {
        printf("numarul tau este par");
    }

}

int pow2(int n) {
    n = 1 << n;
    return n;
}

int main() {
    int nr_ex;
    printf("introdu numarul exercitiului:\n");
    scanf("%d", &nr_ex);
    switch (nr_ex) {
        case 0 : {
            //verifica daca este numar par
            int n;
            printf("introdu numarul:\n");
            scanf("%d", &n);
            is_even(n);
            break;
        }
        case 1 : {
            int n;
            printf("puterea lui 2 pe care o vrei este: \n");
            scanf("%d", &n);
            int putere = pow2(n);
            printf("puterea lui 2 este %d", putere);
            break;
        }
        case 2: {
            //negarea bitilor unui numar
            int n;
            scanf("%d",&n);
            print_bits(flip_bits(n));
            break;
        }
        case 3 : {
            //afisarea bitilor unui numar
            int n;
            scanf("%d", &n);
            print_bits(n);
            break;
        }
        case 4 : {
            int n;
            printf("introdu valoarea lui n:\n");
            scanf("%d", &n);
            is_power2(n);
            break;
        }
        case 5: {

        }
    }


}