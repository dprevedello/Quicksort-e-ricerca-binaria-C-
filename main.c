#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100

void scambia(int vett[], int a, int b){
    int tmp = vett[a];
    vett[a] = vett[b];
    vett[b] = tmp;
}

int partition(int vett[], int sx, int dx){
    int i=sx-1, j=dx;
    int val = vett[dx];

    for(;;){
        while(vett[++i] < val);
        while(val < vett[--j])
            if( j==sx )
                break;
        if( i>=j )
            break;
        scambia(vett, i, j);
    }
    scambia(vett, i, dx);
    
    return i;
}

void quickSort(int vett[], int sx, int dx){ 
    if (sx < dx) { 
        /* Partizionamento dell'array */
        int pivot = partition(vett, sx, dx); 
        quickSort(vett, sx, pivot - 1); 
        quickSort(vett, pivot + 1, dx); 
    } 
} 

int main(void) {
    srand(time(NULL));

    int numeri[DIM];
    for(int i=0; i<DIM; i++){
        numeri[i] = rand() % 1000;
        printf("%d ", numeri[i]);
    }
    
    quickSort(numeri, 0, DIM-1);

    printf("\n\n");
    for(int i=0; i<DIM; i++)
        printf("%d ", numeri[i]);

    int valore;
    printf("\n\nInserire il valore da cercare (tra 0 e 1000): ");
    scanf("%d", &valore);
    
    /************** RICERCA BINARIA **************/
    int sx = 0, dx = DIM-1;
    while( sx<=dx && numeri[(sx+dx)/2]!=valore )
        if( valore > numeri[(sx+dx)/2] )
            sx = (sx+dx)/2 + 1;
        else
            dx = (sx+dx)/2 - 1;
    /*********************************************/

    if( sx<=dx )
        printf("Il valore è presente in posizione %d\n", (sx+dx)/2);
    else
        printf("Il valore non è presente\n");

    return 0;
}