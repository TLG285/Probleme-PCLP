//
// Created by mihai on 11/30/2023.
//
#include <stdlib.h>
#include <stdio.h>
#define max 99
#define min 10
//AICI VOM AVEA FUNCTIILE PENTRU TESTAT
int ***apply_filter(int ***image, int N, int M, float **filter, int filter_size) {
    //alocam memorie pentru o noua matrice bordata cu 0
    int N_bordat,M_bordat;
    N_bordat = N + 2;
    M_bordat = M + 2;
    int ***m = (int ***) malloc(N_bordat *sizeof(int **));
    for(int i = 0; i < N_bordat; i++){
        m[i]=(int **) malloc(N_bordat * sizeof (int *));
    }
    for(int i = 0; i < N_bordat; i++){
        for(int j = 0; j < M_bordat; j++){
            m[i][j]=(int *) calloc(3 , sizeof(int));
        }
    }
    //atribuim matricei bordate valoarea imaginii
    for(int i = 1; i < N_bordat - 1; i++){
        for(int j = 1; j < M_bordat - 1; j++){
            m[i][j]=image[i-1][j-1];
        }
    }
    printf("~~~~~~~~~~~~~~~matricea bordata este:~~~~~~~~~~~~~~~~~~`\n");
    for(int i = 0; i < N_bordat; i++){
        for(int j = 0; j < M_bordat; j++){
            printf("%d ",m[i][j][1]);
        }
        printf("\n");
    }

    //matricea e bordata si functioneaza
    //imaginea filtru e pregatita
    //pasi urmatori:
    //realizeaza suma produselor dintre matricea bordata si matricea filtru
    // atribuie valoarea in matricea sursa
    float S=0;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i = 1; i < N_bordat - 1; i++){
       for(int j = 1; j < M_bordat - 1; j++){
           for(int k = 0; k < 3; k++){
               printf("%d",m[i][j][k]);
               S = m[i][j][k] * filter[1][1] + m[i-1][j][k] * filter[0][1] + m[i][j-1][k] * filter[1][0] + m[i][j+1][k] * filter[1][2] + m[i+1][j][k] * filter[2][1] + m[i-1][j-1][k] * filter[0][0] + m[i-1][j+1][k] * filter[0][2] + m[i+1][j-1][k] * filter[2][0] + m[i+1][j+1][k] * filter[2][2];
               printf("%d   ",S);
               if(S > 255)
                   S = 255;
               if(S < 0)
                   S = 0;
               image[i-1][j-1][k]=(int)S;

               S=0;
           }

       }
        printf("\n");
   }

    return NULL;
}

//AICI INCEPE CODUL SURSA
void print_matrix(int ***m,int N,int M){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%d ",m[i][j][1]);
        }
        printf("\n");
    }


}
void read_matrix(int ***m,int N,int M){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<3;k++)
                m[i][j][k]=rand() % (max - min + 1 ) + min;
        }

    }

}
int main(){
    int N,M,N_d,M_d;
    int x,y,h,w;
    int ***image;
    float **image_dst;//image o sa ramana image || image+dst o sa fie filtru
    printf("~~~~~~~~~~~~~~~~~introduceti N si M pentru imaginea sursa:~~~~~~~~~~~~~~~~~~~\n");
    scanf("%d %d",&N,&M);
    printf("~~~~~~~~~~~~~~~~~introduceti N x N pentru imaginea destinatie:~~~~~~~~~~~~~~~\n");
    N_d=3;
    M_d=N_d;
    //alocam memorie pentru imaginea sursa
    image =(int***)malloc(N * sizeof(int **));
    for(int i=0;i<N;i++){
            image[i]=(int**)malloc(M*sizeof(int *));
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            image[i][j]= (int*)calloc(3, sizeof(int));
        }
    }
    //alocam memorie pentru imaginea destinatie
    image_dst =(float**)malloc(3 * sizeof(float *));
    for(int i = 0; i < N_d; i++){
        image_dst[i]=(float*)malloc(3 *sizeof(float ));
    }

    read_matrix(image,N,M);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~imaginea sursa este:~~~~~~~~~~~~~~~~~~~~~~~`\n");
    print_matrix(image,N,M);
    //generam valori pentru matricea filtru
    const float lower_bound = 0.0f;
    const float upper_bound = 1.0f;

    for(int j = 0; j < N_d; j++)
    {
        for(int k = 0; k < 3; k++)
            image_dst[j][k]=lower_bound + ((float)rand() / RAND_MAX) * (upper_bound - lower_bound);
    }
    printf("~~~~~~~~~~~~~~~~~imaginea filtru este:~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int j=0;j<M;j++)
    {
        for(int k=0;k<3;k++){
            printf("%f ",image_dst[j][k]);
        }
        printf("\n");
    }
    apply_filter(image,N,M,image_dst,M_d);
    printf("\n");

}
//in sfarsit :)