#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
	printf("Enter path to file to copy");
	input_file = gets(str);

	printf("Enter path to copy file to");
	output_file = gets(str)

	FILE *in, *out;
	if ((in = fopen(input_file, "r"))) {
		if ((out != fopen(output_file, "r"))) {
			while((ch = fgetc(in)) != EOF) {
				fputc(ch, out)
			}
		}
	} else {
		printf("File to copy does not exist")
		return 0;
	}
	printf("File copy success");
	return 0;
}