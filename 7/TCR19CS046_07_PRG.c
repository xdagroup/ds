#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int exp;
	struct Node* next;
};

void readpoly(struct Node** poly)
{
	int coeff, exp, cont;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
	do{
        printf("Enter the values\n");
		printf("\n Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->exp = exp;
		temp-> next = NULL;
		printf("\nHave more terms? (1- Yes, 0- No): ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);	
}

void showpoly(struct Node* poly)
{
	printf("\nPolynomial expression = ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->exp);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addpoly(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->exp > second->exp)
 		{
 			temp->coeff = first->coeff;
 			temp->exp = first->exp;
 			first = first->next;
 		}
 		else if(first->exp < second->exp)
 		{
 			temp->coeff = second->coeff;
 			temp->exp = second->exp;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->exp = first->exp;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->exp = first->exp;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->exp = second->exp;
 			second = second->next;
 		}
 	}
}

int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;
	printf("------First polynomial-----\n");
	readpoly(&first);
	printf("First polynomial=\n");
	showpoly(first);

	printf("\n------Second polynomial-----\n");
	readpoly(&second);
	printf("\nSecond polynomial=\n");
	showpoly(second);
	addpoly(&result, first, second);
    printf("\nSum=");
	showpoly(result);
	return 0;
}