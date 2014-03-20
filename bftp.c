
#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	char source[1000];
	FILE *fp;
	if(argc > 1) {
		fp = fopen(argv[1], "r");
		if(fp == NULL) {
			perror("Error opening file");
			return -1;
		}
		fread(source,sizeof(char), 1000, fp);
			
		
		printf("%s\n", "#include \"stdio.h\"\n\nint main() {");
		printf("%s\n", "char array[100000];");
		printf("%s\n", "char *ptr=array;");
		for (int i = 0; i < strlen(source); ++i)
		{
			switch(source[i]) {
			case '>':
				printf("%s\n", "++ptr;");
				break;
			case '<':
				printf("%s\n", "--ptr;");
				break;
			case '+':
				printf("%s\n", "++*ptr;");
				break;
			case '-':
				printf("%s\n", "--*ptr;");
				break;
			case '.':
				printf("%s\n", "putchar(*ptr);");
				break;
			case ',':
				printf("%s\n", "*ptr=getchar();");
				break;
			case '[':
				printf("%s\n", "while(*ptr) {");
				break;
			case ']':
				printf("%s\n", "}");
				break;
			}
		}

		printf("%s\n", "}");
	} else {
		printf("%s\n", "No file given.");
	}
	return 0;
}