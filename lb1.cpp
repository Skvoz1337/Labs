#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
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
void zadanie5(){
char s[20];
	struct{
		char famil[20];
		char name [20];
		char facult[20];
		char nomer[5];
	}stud[3];

	printf("\nZadanie 5\n");

	for(int i = 0; i < 3; i++){
		printf("Vvedite family:");
			scanf("%20s",stud[i].famil);
		printf("Vvedite name:");
			scanf("%20s",stud[i].name);
		printf("Vvedite faculty:");
			scanf("%20s",stud[i].facult);
		printf("Vvedite nomer knigi:");
			scanf("%s",stud[i].nomer);
		}
	int check = 0;
	printf("Search/");
		scanf("%s", &s);
		for(int i = 0; i < 3; i++){
			if(strcmp(stud[i].famil, s) == 0 || strcmp(stud[i].name, s) == 0 || strcmp(stud[i].facult, s) == 0 || strcmp(stud[i].nomer, s) == 0){
				printf("Naideno: %s %s %s %s\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomer);
				check++;
			}
		}
		if(check == 0)
			printf("Poprobyite zanogo");
}
  int main()
	{
		zadanie1_2_4();
		zadanie3();
		zadanie5();
	   getch ();
	   return 0;

	}


