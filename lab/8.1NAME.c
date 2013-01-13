#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char fname[50],sname[50];

	printf("Enter first name\n");
	scanf("%s",&fname);
	printf("Enter surname\n");
	scanf("%s",&sname);

	char* name;
	name = (int*)malloc((strlen(fname)+strlen(sname)+1)*sizeof(int));

	strcat(name,fname);
	strcat(name,sname);

	printf("%s\n",name);
	printf("Array size is %d\n",strlen(name));

        // Flush the input Stream

        char flush;
        while((flush = getchar()) != '\n' && flush != EOF);

        // "getchar()" used to pause propgram (instead of system("pause")) for code portability to other OS'

        printf("Please press enter to continue");
        getchar();
        return(0);
}

/********** EOF **********/
