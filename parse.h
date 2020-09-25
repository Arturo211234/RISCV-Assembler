typedef struct INSTRUCTION INSTRUCTION;
struct INSTRUCTION{
 uint8_t type;
 int32_t arg1;
 int32_t arg2;
 int32_t arg3;
};



int stringlength(char *s){
 int len = 0;
 while(1){
  if(*(s+len) == 0){break;}
  len++;
 }
 return len;
}


int compareString(char *pen15, char *yourMom /* What I was doing last night lol */){
 size_t i = 0;
 while(pen15[i] || yourMom[i]){
  if(pen15[i] != yourMom[i]){
   return 0;
  }
  i++;
 }
 return 1;
}

char *dictionary[40] = {
"LUI",
"AUIPC",
"JAL",
"JALR",
"BEQ",
"BNE",
"BLT",
"BGE",
"BLTU",
"BGEU",
"LB",
"LH",
"LW",
"LBU",
"LHU",
"SB",
"SH",
"SW",
"ADDI",
"SLTI",
"SLTIU",
"XORI",
"ORI",
"ANDI",
"SLLI",
"SRLI",
"SRAI",
"ADD",
"SUB",
"SLL",
"SLT",
"SLTU",
"XOR",
"SRL",
"SRA",
"OR",
"AND",
"FENCE",
"ECALL",
"EBREAK"
};

size_t curr_line = 1;
int argcount = 0;

size_t getArgStartIndex(size_t current, char *the_buffer){
 size_t loopcount = current;
 while(1){
  if(the_buffer[loopcount] == 0){
   exit(1);
  }
  if(the_buffer[loopcount] == 10){
   curr_line++;
  }
  if((the_buffer[loopcount] >= 48 && the_buffer[loopcount] <= 57) || (the_buffer[loopcount] >= 65 && the_buffer[loopcount] <= 90)){
   return loopcount;
  }
  loopcount++;
 }
}



size_t getArgEndIndex(size_t current, char *the_buffer){
 size_t loopcount = current;
 while(1){

  if(the_buffer[loopcount] == 10){
   curr_line++;
  }
  if(the_buffer[loopcount] == 10 || the_buffer[loopcount] == 9 || the_buffer[loopcount] == 32 || the_buffer[loopcount] == 0 || the_buffer[loopcount] == 44){
   return loopcount - 1;
  }
  loopcount++;
 }
}

int32_t tenExp(size_t power){
 int32_t ret = 1;
 for(size_t i = 0; i < power; i++){
  ret *= 10;
 }
 return ret;
}


int32_t interpretArgument(char *argument){
 size_t loopcount = 0;
 int32_t retval = 0;
 if(argument[0] == 120){
  char *newstring = argument;
  for(int i = 0; *(argument + i) != 0; i++){
   newstring[i] = argument[i+1];
  }
  argument = newstring;
 }
 while(1){
   if(argument[loopcount] == 0){
    return retval;
   }
   retval += (argument[loopcount] - 48) * tenExp(loopcount);
 }
}


uint8_t getInstructionType(char *instruction){
 for(uint8_t i = 0; i < 40; i++){
  if(compareString(dictionary[i], instruction) == 1){
  if(i == 38 || i == 39){
   argcount = 4;
  } else if(i == 0 || i == 1 || i == 2){
   argcount += 2;
  } else {
   argcount++;
  }
  printf("Instruction: %s", dictionary[i]);
  return i;
  }
 }
 printf("Invalid instruction at line #%ld", curr_line);
 exit(1);
}


