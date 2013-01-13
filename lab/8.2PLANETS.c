//kg m-3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct planet
{
	char name[8];
	double distance, mass, radius, density;
};

double density(struct planet *p)
{
	double result;
	result = (p->mass)/((4.0*M_PI*pow(p->radius,3))/3.0);
	return result;
}

double ylength(struct planet *p)
{
	const double M=2.0e30;
	const double G=6.672e-11;

	return (2*M_PI*pow(p->distance,1.5))/pow(G*M,0.5);
}


int main()
{
	FILE *planets,*results;
	int i;
	struct planet ss[9];

	if((planets=fopen("planets.txt","r"))==NULL)
	{
		printf("Error loading planets.txt\n");
		printf("Please press enter to continue");
		getchar();
		return(0);
	}

	if((results=fopen("results.txt","w"))==NULL)
	{
		printf("Error loading results.txt\n");
		printf("Please press enter to continue");
		getchar();
		return(0);
	}


	for(i=0;i<9;i++)
	{
		fscanf(planets,"%s %lf %lf %lf",&ss[i].name,&ss[i].distance,&ss[i].mass,&ss[i].radius);
	}

	printf("Name       Distance   Mass   Radius\n");
	for(i=0;i<9;i++)
	{
		printf("%10s %g %g %g\n",ss[i].name,ss[i].distance,ss[i].mass,ss[i].radius);
	}

	for(i=0;i<9;i++)
	{
		fprintf(results,"%s %g %g\n",ss[i].name,ylength(&ss[i]),density(&ss[i]));
	}
        printf("Please press enter to continue");
        getchar();
        return(0);
}

/********** EOF **********/
