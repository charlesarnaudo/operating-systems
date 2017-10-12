#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

 int main() {
 	char input_file[100], output_file[100];

	printf("Enter path to file to copy");
        scanf("%s", input_file);

	printf("Enter path to copy file to");
	scanf("%s", output_file);

	FILE *in, *out;
	if ((in = fopen(input_file, "r"))) {
		if ((out != fopen(output_file, "r"))) {
                        char ch;
			while((ch = fgetc(in)) != EOF) {
				fputc(ch, out);
			}
		}
	} else {
		printf("File to copy does not exist")
		return 0;
	}
	printf("File copy success");
	return 0;
}