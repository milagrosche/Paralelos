#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <random>

using namespace std;

int main()
{

	int MAX;
	int sum = 0;

	cout<<"tamanio de la matriz: ";
	cin>>MAX;

	int A[MAX][MAX], B[MAX][MAX], Y[MAX][MAX], X[MAX][MAX];

	srand(time(NULL));

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			A[i][j]=(rand()%10)+1;
	}

	cout<<"La matriz A es: "<<endl<<endl;

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			B[i][j]=(rand()%10)+1;
	}

	cout<<"La matriz B es: "<<endl<<endl;

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			cout<<B[i][j]<<" ";
		cout<<endl;
	}
/*
	cout<<"\n ******** multiplicacion parte I *******"<<endl;

	cout<<"\n Opcion A: "<<endl<<endl;
	//first
	for (int i=0;i<MAX;i++){
		for (int j = 0; j <MAX;j++){
			X[i][j]+=A[i][j]*B[i][j];
			cout<<X[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"\n Opcion B: "<<endl<<endl;
	// second
	for (int j=0;j<MAX;j++){
		for (int i = 0; i <MAX;i++){
			Y[i][j]+=A[i][j]*B[i][j];
			cout<<Y[i][j]<<" ";
		}
		cout<<endl;
	}	

	cout<<"\n ******** multiplicacion clasica *******"<<endl;

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			for(int k=0; k<MAX; k++)
			  	sum=sum+(A[i][k]*B[k][j]);
				Y[i][j]=sum;
			sum=0;
		}
	}

	cout<<"\n La multiplicacion es: "<<endl<<endl;

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			cout<<Y[i][j]<<" ";
		cout<<endl;
	}


*/
	cout<<"\n ******** multiplicacion por bloques *******"<<endl;

	for(int i=1; i<MAX; i++)
	{
		for(int j=1; j<MAX; j++)
		{
			for(int k=1; k<MAX; k++)
			{
				for (int i = i+MAX; i < MAX; i++)
				{
					for (int j = j+MAX; i < MAX; j++)
					{
						sum=0;
						for (int k = k+MAX; k < MAX; k++)
						{
							sum=sum+(A[i][k]*B[k][j]);
						}
						Y[i][j]=sum;
					}
				}
			}
		}
	}
	
	cout<<"\n La multiplicacion es: "<<endl<<endl;

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			cout<<Y[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}