#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void zadanie1_2_4(){
	int i, raz, N[6][6];
		int max = 0;
		int min = 100;
		int summa = 0;
		
		for(int w = 0; w < 6; w++){
			summa = 0;
			for (i = 0; i < 6; i++){
			N[i][w] = rand()%100;
			printf("%d\t",N[i][w]);
			summa+=N[i][w];
			}
			printf("summa = %d", summa);
			printf("\n");
		}
		for(int w = 0; w < 6; w++){
			for (i = 0; i < 6; i++){
		if(N[i][w]<min)
			min = N[i][w];
		if(N[i][w]>max)
			max = N[i][w];
			}
		}

	   raz = max-min;
	   
	   printf("\n raz %d",raz);
}
void zadanie3(){
	int *m;
	int n;
	 
	printf("\n Ukagite razmer massiva: ");
	scanf("%d",&n);
	m = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n;i++){
	printf("Vvedite %d element massiva  ", i);
	scanf("%d",&m[i]);
	}
	printf("Vash massiv - ");
	for(int i=0; i<n; i++){
	printf("%d   ",m[i]);
	}
}
  int main()
	{
		zadanie1_2_4();
		zadanie3();
	   getch ();
	   return 0;

	}

