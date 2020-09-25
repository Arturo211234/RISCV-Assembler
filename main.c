#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "parse.h"
#include "instruction.h"

enum PSstate{PUSH, SHIFT};
int state = SHIFT;
size_t linecount = 1;

size_t current_index = 0;

INSTRUCTION curr_inst;

int main(int argc, char *argv[]){
 if(argc != 3){
  puts("Incorrect amount of arguments provided,");
  printf("Usage is %s [INPUT FILE] [OUTPUT FILE]\n", argv[0]);
  return 0;
 }
 
 FILE *output = fopen(argv[2], "wb");

 FILE *file = fopen(argv[1], "r");
 char *buffer;
 long filesize;
 fseek(file, 0, SEEK_END);
 filesize = ftell(file);
 rewind(file);
 buffer = malloc(filesize+1);
 fread(buffer, filesize, 1, file);
 fclose(file);
 buffer[filesize] = 0;
 
 for(int i = 0; i < filesize; i++){
  if(buffer[i] == 10){
   linecount++;
  }
 }
 
 size_t start, end;
 char currentString[10];
 switch(state){
  case SHIFT:
    switch(argcount){
      case 0:
       start = getArgStartIndex(current_index, buffer);
       end = getArgEndIndex(current_index, buffer);
       for(unsigned long i = 0; i <= (end - start); i++){
        currentString[i] = buffer[start + i];
       }
       current_index = end+1;
       currentString[end+1] = 0;
       curr_inst.type = getInstructionType(currentString);
       for(int i = 0; i < 10; i++){
        currentString[i] = 0;
       }
       break;
      case 1:
       start = getArgStartIndex(current_index, buffer);
       end = getArgEndIndex(current_index, buffer);
       for(unsigned long i = 0; i <= (end - start); i++){
        currentString[i] = buffer[start + i];
       }
       current_index = end+1;
       currentString[end+1] = 0;
       curr_inst.arg1 = interpretArgument(currentString);
       for(int i = 0; i < 10; i++){
        currentString[i] = 0;
       }
       break;
      case 2:
       start = getArgStartIndex(current_index, buffer);
       end = getArgEndIndex(current_index, buffer);
       for(unsigned long i = 0; i <= (end - start); i++){
        currentString[i] = buffer[start + i];
       }
       current_index = end+1;
       currentString[end+1] = 0;
       curr_inst.arg2 = interpretArgument(currentString);
       for(int i = 0; i < 10; i++){
        currentString[i] = 0;
       }
       break;
      case 3:
       start = getArgStartIndex(current_index, buffer);
       end = getArgEndIndex(current_index, buffer);
       for(unsigned long i = 0; i <= (end - start); i++){
        currentString[i] = buffer[start + i];
       }
       current_index = end+1;
       currentString[end+1] = 0;
       curr_inst.arg3 = interpretArgument(currentString);
       for(int i = 0; i < 10; i++){
        currentString[i] = 0;
       }
       break;
      case 4:
       state = PUSH;
       break;
    }
    break;
  case PUSH:
    fwrite(&instruction, 4, 1, output); 
    break;
 }
 
 return 0; 
}
