#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
void zadanie1(){
	printf("������� 1\n");
	int x[10] = {1,2,3,4,5,6,7,8,9,10};
	int min = 10;
	int max = 0;

	for(int i = 0; i < 10; i++){
		printf("%d  ",x[i]);
	if(x[i]<min)
		min = x[i];
	if(x[i]>max)
		max = x[i];
	}

	printf("\n ������� ����� ����������� � ������������ = %d\n\n", max-min);

}
void zadanie2and4(){
	printf("������� 2 � 4\n");
int mass[5][5];
int sum = 0;
for(int i = 0; i < 5; i++){
	for(int j = 0; j < 5; j++){
	mass[i][j] = rand()%100;
	}
}
for(int i = 0; i < 5; i++){
	sum = 0;
	for(int j = 0; j < 5; j++){
	printf("%d\t", mass[i][j]);
	sum+=mass[i][j];
	}
	printf("����� ������ = %d \n",sum);
	}
printf("\n");
}
void zadanie3(){
	int *p;
	int n;

	printf("������� 3\n");
	printf("������� ������ �������: ");
	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));

	for(int i  = 0; i < n; i++){
		printf("������� %d ������� �������:", i);
		scanf_s("%d", &p[i]);
	}
	printf("\n ��� ������ - ");
	for(int i  = 0; i < n; i++){
		printf("%d  ", p[i]);
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

	printf("\n������� 5\n");

	for(int i = 0; i < 3; i++){
		printf("������� �������:");
			scanf("%20s",stud[i].famil);
		printf("������� ���:");
			scanf("%20s",stud[i].name);
		printf("������� ���������:");
			scanf("%20s",stud[i].facult);
		printf("������� ����� �����.������:");
			scanf("%s",stud[i].nomer);
		}
		printf("\n ������ ���������:\n");
	for(int j = 0; j < 3; j++){
		printf("%s %s\t %s %s\n",stud[j].famil, stud[j].name, stud[j].facult, stud[j].nomer);
	}

	int check = 0;
	printf("�����/");
		scanf("%s", &s);
		for(int i = 0; i < 3; i++){
			if(strcmp(stud[i].famil, s) == 0 || strcmp(stud[i].name, s) == 0 || strcmp(stud[i].facult, s) == 0 || strcmp(stud[i].nomer, s) == 0){
				printf("�������: %s %s %s %s\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomer);
				check++;
			}
		}
		if(check == 0)
			printf("������ �� �������");
}

int main(){
	setlocale(LC_ALL, "Rus");

	zadanie1();
	zadanie2and4();
	zadanie3();
	zadanie5();

	getch();
	return 0;
}