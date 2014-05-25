#include <stdio.h>
#include <string.h>

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

		fread(source, sizeof(char), 1000, fp);


		puts("#include \"stdio.h\"\n\n"
                     "int main() {\n"
                     "char array[100000];\n"
                     "memset(array, 0, 100000);\n"
                     "char *ptr=array;\n");

		for (int i = 0; i < strlen(source); ++i) {
			switch(source[i]) {
			case '>':
				puts("++ptr;");
				break;
			case '<':
				puts("--ptr;");
				break;
			case '+':
				puts("++*ptr;");
				break;
			case '-':
				puts("--*ptr;");
				break;
			case '.':
				puts("putchar(*ptr);");
				break;
			case ',':
				puts("*ptr=getchar();");
				break;
			case '[':
				puts("while(*ptr) {");
				break;
			case ']':
				puts("}");
				break;
			}
		}

		puts("}");
	} else {
		puts("No file given.");
	}
	return 0;
}
