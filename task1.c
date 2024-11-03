#include <stdio.h>

typedef struct  {
	int ID;
	float GPA;
	char name[50];
}Student;

void ins(int N, Student Arr[]);
void Print(int N, Student Arr[]);
int main(){
int N;
	printf("\nEnter the number of students: ");
	scanf("%d",&N);

Student Arr[N];

	ins(N,Arr);
	Print(N,Arr);

  return 0;
}

void ins(int N, Student Arr[]){
	for(int i = 0; i < N; i++){
		printf("\nEnter ID for Student %d: ",i+1);
		scanf("%d",&Arr[i].ID);

		printf("\nEnter name for student %d: ",i+1);
		scanf(" %s",Arr[i].name);
	
		printf("\nEnter GPA for student %d: ",i+1);
		scanf("%f",&Arr[i].GPA);
	}
}

void Print(int N, Student Arr[]){
	printf("\n\nStudent Records:\n");
	for(int i = 0; i < N; i++){
		printf("\nID: %d, Name: %s, GPA: %f",Arr[i].ID,Arr[i].name,Arr[i].GPA);
	}
	
	printf("\n");
}		

