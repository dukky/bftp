#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char source[100000];
	FILE *fp;

	if(argc > 1) {
		fp = fopen(argv[1], "r");

		if(fp == NULL) {
			perror("Error opening file");
			return -1;
		}

		fread(source, sizeof(char), 100000, fp);


		puts("#include \"stdio.h\"\n"
                     "#include \"string.h\"\n\n"
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
