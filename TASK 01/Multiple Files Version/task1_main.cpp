/*
--------------------------------------------------------------------------------------------------------------------------------------------------
                                                        -<(COAL PROJECT)>-
==================================================================================================================================================
                                                            (TASK#01)
                        THIS PROGRAM CONVERT HACK COMPUTER ASSEMBLY CODE TO CORRESPONDING MACHINE CODE
                              [THIS PROGRAM CANNOT HANDLE PREDEFINED SYMBOLS , LABELS AND VARIABLES]  
                                                           (MAIN FILE) 
==================================================================================================================================================
NAME: MOHAMMAD ABDULLAH
ROLL NO: BSEF19A531
--------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "task1_dec.h"


//MIAN FUNCTION 

int main()
{
    file_delete();              
    generate_machine_code();    // FUNCTION TO HANDLE ASSEMBLY CODE & GENERATE MACHINE CODE

    return 0;
}