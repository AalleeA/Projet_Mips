#ifndef VARCONV_H_
#define VARCONV_H_

char instructionJ [NBINSTRUCTIONJ * 2][7] = {
    {"J"}, {"000010"},
    {"JAL"}, {"000011"}
  };

/*
 *Dans l'orde,
 *Instruction Calssique (Label rs rt immediat) {ADDI, BEQ, BNE}
 *classique sans rt (Label rs 00000 immediat) {BGTZ, BLEZ}
 *classique sans rs (Label 00000 rt immediat) {LUI}
 *avec base (Label base rt offset)  {LW, SW}
 */
char instructionI [NBINSTRUCTIONI * 2][7] = {
  {"ADDI"}, {"001000"},
  {"BEQ"}, {"000100"},
  {"BNE"}, {"000101"},

  {"BGTZ"}, {"000111"},
  {"BLEZ"}, {"000110"},

  {"LUI"}, {"001111"},

  {"LW"}, {"100011"},
  {"SW"}, {"101011"}
};
  
  char binaireToHexa[33][5] = {
    {"0000"},{"0"},
    {"0001"},{"1"},
    {"0010"},{"2"},
    {"0011"},{"3"},
    {"0100"},{"4"},
    {"0101"},{"5"},
    {"0110"},{"6"},
    {"0111"},{"7"},
    {"1000"},{"8"},
    {"1001"},{"9"},
    {"1010"},{"A"},
    {"1011"},{"B"},
    {"1100"},{"C"},
    {"1101"},{"D"},
    {"1110"},{"E"},
    {"1111"},{"F"},
  };

#endif
