/*											            {DECLARATION FILE}
--------------------------------------------------------------------------------------------------------------------------------------------------
                                                        -<(COAL PROJECT)>-
==================================================================================================================================================
                                                            (TASK#01)
                        THIS PROGRAM CONVERT HACK COMPUTER ASSEMBLY CODE TO CORRESPONDING MACHINE CODE
                              [THIS PROGRAM CANNOT HANDLE PREDEFINED SYMBOLS , LABELS AND VARIABLES]  
							     THIS FILE CONTAINS 10 FUNCTIONS USED TO IMPLEMENT HACK ASSEMBLER
==================================================================================================================================================
NAME: MOHAMMAD ABDULLAH
ROLL NO: BSEF19A531
--------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef HACK_ASSEMBLER_T1_H
#define HACK_ASSEMBLER_T1_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

//FUNCTION REMOVES WHITESPACES AND COMMENTS FROM EACH LINE OF THE STRING 
string remove_spaces(string str);

// FUNCTION TO REMOVE ANY EXISTING FILE CONTAINING OLD MACHINE CODE
void file_delete();

//FUNCTIONS TO OUTPUT MACHINE CODE  INTO THE OUTPUT FILE
void A_output(int A_inst_arry[16]);

void C_output(string C_inst_arry[4]);

//FUNCTION TO CREATE 16 BIT BINARY (MACHINE CODE) FOR THE A INSTRUCTION
void A_inst_generator(int n);

//FUNCTION TO GENERATE DEST MACHINE CODE
string dest_generator(string dest_str);

//FUNCTION TO GENERATE JMP MACHINE CODE
string jmp_generator(string jmp_str);

//FUNCTION TO GENERATE COMP MACHINE CODE
string comp_generator(string comp_str);

//FUNCTION TO HANDLE AND CONVERT IT TO MACHINE LANGUAGE
void C_inst_generator(string line);

//FUNCTION TO HANDLE ASSEMBLY CODE & GENERATE MACHINE CODE
void generate_machine_code();

#endif