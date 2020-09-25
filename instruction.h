uint32_t instruction;

void LUI(int32_t arg1, int32_t arg2, int32_t arg3){
 instruction += 0x37;
 instruction += (arg2 & 0x7F) << 6;
 instruction += (arg3 & 0xFFFFF) << 11;
} 
void AUIPC(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void JAL(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void JALR(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BEQ(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BNE(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BLT(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BGE(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BLTU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void BGEU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void LB(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void LH(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void LW(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void LBU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void LHU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SB(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SH(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SW(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void ADDI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLTI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLTIU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void XORI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void ORI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void ANDI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLLI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SRLI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SRAI(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void ADD(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SUB(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLL(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLT(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SLTU(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void XOR(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SRL(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void SRA(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void OR(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void AND(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void FENCE(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void ECALL(int32_t arg1, int32_t arg2, int32_t arg3){

} 
void EBREAK(int32_t arg1, int32_t arg2, int32_t arg3){

}


void (*instructions[40])(int32_t arg1, int32_t arg2, int32_t arg3);

void getTotalInstruction(INSTRUCTION inst){
instructions[0] = LUI;
instructions[1] = AUIPC;
instructions[2] = JAL;
instructions[3] = JALR;
instructions[4] = BEQ;
instructions[5] = BNE;
instructions[6] = BLT;
instructions[7] = BGE;
instructions[8] = BLTU;
instructions[9] = BGEU;
instructions[10] = LB;
instructions[11] = LH;
instructions[12] = LW;
instructions[13] = LBU;
instructions[14] = LHU;
instructions[15] = SB;
instructions[16] = SH;
instructions[17] = SW;
instructions[18] = ADDI;
instructions[19] = SLTI;
instructions[20] = SLTIU;
instructions[21] = XORI;
instructions[22] = ORI;
instructions[23] = ANDI;
instructions[24] = SLLI;
instructions[25] = SRLI;
instructions[26] = SRAI;
instructions[27] = ADD;
instructions[28] = SUB;
instructions[29] = SLL;
instructions[30] = SLT;
instructions[31] = SLTU;
instructions[32] = XOR;
instructions[33] = SRL;
instructions[34] = SRA;
instructions[35] = OR;
instructions[36] = AND;
instructions[37] = FENCE;
instructions[38] = ECALL;
instructions[39] = EBREAK;

 (*instructions[inst.type]) (inst.arg1, inst.arg2, inst.arg3);
}
