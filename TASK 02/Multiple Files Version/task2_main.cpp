/*
--------------------------------------------------------------------------------------------------------------------------------------------------
                                                        -<(COAL PROJECT)>-
==================================================================================================================================================
                                                            (TASK#02)
                        THIS PROGRAM CONVERT HACK COMPUTER ASSEMBLY CODE TO CORRESPONDING MACHINE CODE
                            [THIS PROGRAM CAN HANDLE PREDEFINED SYMBOLS , LABELS AND VARIABLES]  
                                                       MAIN FUNCTION FILE
==================================================================================================================================================
NAME: MOHAMMAD ABDULLAH
ROLL NO: BSEF19A531
--------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "task2_dec.h"

//MAIN FUNCTION
int main()
{
    file_delete();                      
    map<string, int> table;             //created an empty table
    table = init_table(table);          //initialize table with predefined symbols and values
    find_labels(table);                 //finding and inserting values of labels in table P-1
    find_variables(table);              //finding and inserting values of variables in table P-2
    table_replace(table);               //Replace and generate Machine code
    
    return 0;
}