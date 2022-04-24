/*											            {DECLARATION FILE}
--------------------------------------------------------------------------------------------------------------------------------------------------
                                                        -<(COAL PROJECT)>-
==================================================================================================================================================
                                                            (TASK#02)
                        THIS PROGRAM CONVERT HACK COMPUTER ASSEMBLY CODE TO CORRESPONDING MACHINE CODE
                              [THIS PROGRAM CANNOT HANDLE PREDEFINED SYMBOLS , LABELS AND VARIABLES]  
							     THIS FILE CONTAINS 13 FUNCTIONS USED TO IMPLEMENT HACK ASSEMBLER
==================================================================================================================================================
NAME: MOHAMMAD ABDULLAH
ROLL NO: BSEF19A531
--------------------------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef HACK_ASSEMBLER_T2_H
#define HACK_ASSEMBLER_T2_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <map>

using namespace std;

// FUNCTIONS ALSO USED IN TASK 01

//FUNCTIONS TO OUTPUT MACHINE CODE  INTO THE OUTPUT FILE
void A_output(int A_inst_arry[16]);

//FUNCTIONS TO OUTPUT C INSTRUCTION MACHINE CODE INTO OUTPUT FILE
void C_output(string C_inst_arry[4]);

//FUNCTION TO CREATE 16 BIT BINARY (MACHINE CODE) FOR THE A INSTRUCTION
void A_inst_generator(int n);

//FUNCTION TO GENERATE DEST MACHINE CODE
string dest_generator(string dest_str);

//FUNCTION TO GENERATE JMP MACHINE CODE
string jmp_generator(string jmp_str);

//FUNCTION TO GENERATE COMP MACHINE CODE
string comp_generator(string comp_str);

//FUNCTION TO HANDLE AND CONVERT C INSTRUCTION TO MACHINE LANGUAGE
void C_inst_generator(string line);

// FUNCTION TO REMOVE ANY EXISTING FILE CONTAINING OLD MACHINE CODE
void file_delete();

//FUNCTION REMOVES WHITESPACES AND COMMENTS FROM EACH LINE OF THE STRING 
string remove_spaces(string str);

//----------------------------------------------------------------------------------------------------

// NEW FUNCTIONS CREATED IN TASK 02

//FUNCTION TO INITIALIZE TABLE WITH PREDEFINED SYMBOLS AND VALUES
map<string,int> init_table(map<string, int> m);

//FUNCTION TO FIND AND INSERT LABEL AND THEIR VALUES IN TABLE
void find_labels(map<string,int> &m);

//FUNCTION TO FIND AND INSERT VARIBLES AND VALUES IN TABLE
void find_variables(map<string,int> &m);

//FUNCTION TO REPLACE VALUES FROM THE TABLE TO FILE
void table_replace(map<string,int> &m);

#endif