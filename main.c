#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, const char * argv[]) {
    printf("argc=%d", argc);
    if (argc <= 1) {
        printf("input file name is missing");
    }
    
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("input file name is missing");
    }
    
    char output_file[BUFFER_SIZE];
    int file_count = 0;
    sprintf(output_file, "%s.%d", argv[1], file_count);
    
    int max_lines = argc >= 3 ? atoi(argv[2]) : 10000000;
    
    char buffer[BUFFER_SIZE];

    int line_count = 0;
    FILE* out = fopen(output_file, "w");
    while (fgets(buffer, BUFFER_SIZE - 1, input)) {
        //fprintf(out, "%s", buffer);
        fputs(buffer, out);
        if (++line_count >= max_lines) {
            fclose(out);
            line_count = 0;
            file_count++;
            sprintf(output_file, "%s.%d", argv[1], file_count);
            out = fopen(output_file, "w");
        }
    }
    fclose(out);
}
