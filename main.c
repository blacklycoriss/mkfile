
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE (2 * 1024)

void write(char *, char *);
void read(char *);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Hasn't written filename");
		
		return 1;
	}
	else if (argc == 3)
	{
		char *filename = argv[1];
		char *option = argv[2];
	
		if (strcmp(option, "-r") == 0)
		{
			read(filename);
		}
		else if (strcmp(option, "-w") == 0)
		{
			printf("Enter your text: ");
		
			char *entr_str = calloc(sizeof(CHUNK_SIZE), sizeof(char));
		
			scanf("%s", entr_str);
			write(entr_str, filename);
	
			free(entr_str);
		}
	}
	
	
	return 0;
}

void write(char *str, char *filename)
{
	FILE *file = fopen(filename, "a+");
	for (int i = 0; i < strlen(str); i++)
	{
		putc(str[i], file);
	}
	
	fclose(file);
	return;
}
void read(char *filename)
{	
	FILE *file = fopen(filename, "r");
	char c;
	
	if (file)
	{
		while ((c = getc(file)) != EOF)
		{
			printf("%c", c);
		}
	}
	else
	{
		printf("Error reading file: file is empty \n");
	}
	
	fclose(file);
	return;
}