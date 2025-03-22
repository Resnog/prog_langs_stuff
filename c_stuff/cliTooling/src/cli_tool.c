#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "tools.h"


/**************************************************************************
 Helper functions
***************************************************************************/
void print_help(void){
  printf("cliTool:\n");
  printf("\n");
  printf("This is a placeholder help for a CLI tool of your convenience");
  printf("\n");
  printf("  crypt [-h] -b <buffer_size> [-o <output_file>] [<input_file>]\n");
  printf("-h  Show this help\n");
  printf("-o  Output file. If none is specified the stdout will be used\n");
  printf("-b  Processing buffer size. Default size is 256 bytes\n");
  printf("\n");
  printf("If no input file has been specified the input will be taken from stdin\n");
  printf("The buffer size will dictate how many bytes the tool will get from input and output\n");
}

/**************************************************************************
 Main implementation
***************************************************************************/
int main(int argc, char *argv[]){
  int input_file_flag = 0;
  int output_file_flag = 0;
  size_t processing_buffer_size = default_buffer_size;
  FILE *input_file = stdin;
  FILE *output_file = stdout;
  
  int c;
  while((c = getopt(argc, argv, "hk:f:o:b:")) != -1 ){
    switch (c) {
      case 'h':
        // Print the user help
        print_help();
        return -1;
        break;

      case 'o':
        // Create file and use it as an output
        output_file_flag = 1;
        output_file = fopen(optarg, "wb");
        break;
      case 'b':
        // Change the processing buffer size
        processing_buffer_size = atoi(optarg);
        break;
      default:
        break;
    }
  }

  // Read file input
  if(argv[optind] != NULL){
    input_file = fopen(argv[optind], "rb");
    if(input_file == NULL){
      printf("File does not exits");
      return -1;
    }
  }

  // Process incoming data and send to output
  uint8_t *buffer = malloc(processing_buffer_size);
  uint8_t *output = malloc(processing_buffer_size);
  
  // Clear the buffers before starting to process data
  memset(buffer, 0, processing_buffer_size);
  memset(output, 0, processing_buffer_size);

  while(1){

    size_t read_bytes = fread(buffer, sizeof(uint8_t), processing_buffer_size, input_file);
    // Send the input to the output
    memcpy(output, buffer, read_bytes);
    fwrite(output, sizeof(uint8_t), read_bytes, output_file);
    fflush(output_file);
    if(read_bytes < processing_buffer_size){
      if(feof(input_file)){
        printf("\nData reached EOF\n");
        break;
      }
    }
  }

  if(input_file_flag == 1){
    fclose(input_file);
  }

  if(output_file_flag == 1){
    fclose(output_file);
  }

  
  return 0x00;
}
