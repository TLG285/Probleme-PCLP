#include <stdlib.h>
#include <stdio.h>
#define maximus 99
#define minimus 10
const float lower_bound = -0.0f;
const float upper_bound = -1.0f;
//de aici incepe functia

int ***apply_filter(int ***image, int N, int M, float **filter, int filter_size) {
    float S;
    int ***m;
    m= (int ***) malloc(N* sizeof(int **));
    for(int i = 0; i < N; i++)
        m[i]=(int **) malloc(M *sizeof (int *));
    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++){
            m[i][j]=(int *) malloc(3 * sizeof(int));
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 3; k++){
                printf("\n ~~~~~~~~~~~~i-ul este %d j-ul este %d~~~~~~~~~~~~\n",i,j);
                //adresa lui image o sa o salvam in pointer-ul position
                S=0;
                //stanga sus
                printf("\n~~~~~~~~~~~~zona 1 este:~~~~~~\n");
                for(int x = i; x - i >= -filter_size/2 && x >= 0; x--){
                    for(int y = j; y - j >= -filter_size/2 && y >= 0; y--){
                        printf("valoarea din imagine este (%d,%d) iar cea a filtrului este (%d,%d)",x,y,(x - i + filter_size/2),(y - j + filter_size/2));
                        S = S + (float)image[x][y][k] * filter[x - i + filter_size/2][y - j + filter_size/2];
                    }
                    printf("\n");
                }
                //stanga jos
                printf("\n~~~~~~~~~~~~zona 2 este:~~~~~~\n");
                for(int x = i+1; x - i <= filter_size/2 && x < N; x++){
                    for(int y = j; y - j >= -filter_size/2 && y >= 0; y--){
                        printf("valoarea din imagine este (%d,%d) iar cea a filtrului este (%d,%d)",x,y,(x - i + filter_size/2),(y - j + filter_size/2));
                        S = S + (float)image[x][y][k] * filter[x - i + filter_size/2][y - j + filter_size/2];
                    }
                    printf("\n");
                }
                printf("\n~~~~~~~~~~~~zona 3 este:~~~~~~\n");

                //dreapta sus
                for(int x = i; x - i >= -filter_size/2 && x >= 0; x--){
                    for(int y = j+1; y - j <= filter_size/2 && y < M; y++){
                        printf("valoarea din imagine este (%d,%d) iar cea a filtrului este (%d,%d)",x,y,(x - i + filter_size/2),(y - j + filter_size/2));
                        S = S + (float)image[x][y][k] * filter[x - i + filter_size/2][y - j + filter_size/2];                    }
                    printf("\n");
                }
                //dreapta jos
                printf("\n~~~~~~~~~~~~zona 4 este:~~~~~~\n");
                for(int x = i + 1; x - i <= filter_size/2 && x < N; x++){
                    for(int y = j+1; y - j <= filter_size/2 && y < M; y++){
                        printf("valoarea din imagine este (%d,%d) iar cea a filtrului este (%d,%d)",x,y,(x - i + filter_size/2),(y - j + filter_size/2));
                        S = S + (float)image[x][y][k] * filter[x - i + filter_size/2][y - j + filter_size/2];                    }
                    printf("\n");
                }
                printf("\n~~~~~~~~~~~~~~~~~~~~~~s este %.8f~~~~~~~~~~~~~~~~~~~~\n",S);
                if(S>255)
                    S=255;
                if(S<0)
                    S=0;
                m[i][j][k]=(int)S;


            }
        }
    }

    return m;
}

//aici se termina functia


float **genereaza_filter(int f){
    float **m=(float **) malloc( f * sizeof(float *));
    for(int i = 0; i < f; i++){
        m[i]=(float *) malloc(f * sizeof(float));
    }
    for(int i = 0; i < f; i++){
        for(int j = 0; j < f; j++){
            m[i][j]= lower_bound + ((float)rand() / RAND_MAX) * (upper_bound - lower_bound);

        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~Filtrul tau o sa fie:~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<f;i++){
        for(int j=0;j<f;j++){
            printf("%f ",m[i][j]);
        }
        printf("\n");
    }
    return m;
}
void printeaza_matrice(int ***m,int N,int M){
    printf("~~~~~~~~~~~~~~~~~~~~~matricea ta va fi:~~~~~~~~~~~~~~~\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("(");
            for(int k = 0; k < 3; k++){
                if(k==2){
                    printf("%d",m[i][j][k]);
                }
                else
                printf("%d,",m[i][j][k]);
            }
            printf(") ");
        }
        printf("\n");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
int ***genereaza_matrice(int N,int M){
    int ***m;
    m=(int ***) malloc(N * sizeof(int **));
    for(int i = 0; i < N; i++){
        m[i]=(int **) malloc( M * sizeof(int *));
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            m[i][j]=(int *) malloc(3 * sizeof(int));
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 3; k++){
                m[i][j][k]=rand() %(maximus - minimus) + minimus;
            }
        }
    }
    return  m;
}

int main(){
    //doua variabile N M;
    int N,M;
    printf("~~~~~~~~~valorile pentru N si M vor fi:~~~~~~~~~~~~~~~~\n");
    scanf("%d %d", &N, &M);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~N-ul si M-ul tau vor fi: %d si %d~~~~~~~~~~~~~~~~~~~~~\n",N,M);
    int ***m=genereaza_matrice(N,M);
    printeaza_matrice(m,N,M);
    int f;
    printf("introdu dimensiunea filtrului: \n");
    scanf("%d", &f);
    printf("%d",f);
    float **filter;
    filter=genereaza_filter(f);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    m=apply_filter(m,N,M,filter,f);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printeaza_matrice(m,N,M);
}