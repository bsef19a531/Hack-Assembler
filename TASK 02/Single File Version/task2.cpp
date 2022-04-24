/*
--------------------------------------------------------------------------------------------------------------------------------------------------
                                                        -<(COAL PROJECT)>-
==================================================================================================================================================
                                                            (TASK#02)
                        THIS PROGRAM CONVERT HACK COMPUTER ASSEMBLY CODE TO CORRESPONDING MACHINE CODE
                            [THIS PROGRAM CAN HANDLE PREDEFINED SYMBOLS , LABELS AND VARIABLES]  
==================================================================================================================================================
NAME: MOHAMMAD ABDULLAH
ROLL NO: BSEF19A531
--------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <map>

using namespace std;

//FUNCTIONS TO OUTPUT MACHINE CODE  INTO THE OUTPUT FILE
void A_output(int A_inst_arry[16])
{
    fstream write_file;
	write_file.open("machinecode_t2.hack", ios::out | ios::app);
	if (!write_file) 
    {
		cout << "Error! while creating file" << endl;
	}
	else 
    {

        for (int j = 15; j >= 0; j--)
        {
            write_file << A_inst_arry[j];
        }
        write_file << endl;

	}
    write_file.close();
}

//FUNCTIONS TO OUTPUT C INSTRUCTION MACHINE CODE INTO OUTPUT FILE
void C_output(string C_inst_arry[4])
{
    fstream write_file;
	write_file.open("machinecode_t2.hack", ios::out | ios::app);
	if (!write_file) 
    {
		cout << "Error! while creating file" << endl;
	}
	else 
    {

        for(int i = 0 ; i < 4 ; i++)
        {
            write_file << C_inst_arry[i];
        }
        write_file << endl;
	}
    write_file.close();
}

//FUNCTION TO CREATE 16 BIT BINARY (MACHINE CODE) FOR THE A INSTRUCTION
void A_inst_generator(int n)
{
    int binaryNum[16] = {0};
 
    int i = 0;
    while (n > 0) 
    {
 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    A_output(binaryNum);

}

//FUNCTION TO GENERATE DEST MACHINE CODE
string dest_generator(string dest_str)
{
    string dest_name[7] = {"M", "D", "MD", "A", "AM", "AD", "AMD"};
    string dest_code[7] = {"001", "010", "011", "100", "101", "110", "111"};
    int i = 0;
    while(true)
    {
        
        if (dest_str == dest_name[i])
        {
            dest_str = dest_code[i];
            break;
        }
        i++;
    }
    return dest_str;

}

//FUNCTION TO GENERATE JMP MACHINE CODE
string jmp_generator(string jmp_str)
{
    string jmp_name[7] = {"JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};
    string jmp_code[7] = {"001", "010", "011", "100", "101", "110", "111"};
    int i = 0;
    while(true)
    {
        
        if (jmp_str == jmp_name[i])
        {
            jmp_str = jmp_code[i];
            break;
        }
        i++;
    }
    return jmp_str;

}

//FUNCTION TO GENERATE COMP MACHINE CODE
string comp_generator(string comp_str)
{
    string comp_name[28] = {    "0",      "1",      "-1",       "D",       "A",      "!D",      "!A",        "-D",     "-A",      "D+1",     "A+1",     "D-1",     "A-1" ,   "D+A",      "D-A",     "A-D",    "D&A",     "D|A",       "M",      "!M",       "-M",       "M+1",      "M-1",     "D+M",    "D-M",      "M-D",    "D&M",    "D|M"};
    string comp_code[28] = {"0101010", "0111111", "0111010", "0001100", "0110000", "0001101", "0110001",  "0001111", "0110011", "0011111", "0110111", "0001110", "0110010", "0000010", "0010011", "0000111", "0000000", "0010101", "1110000", "1110001",  "1110011",  "1110111", "1110010", "1000010", "1010011", "1000111", "1000000", "1010101"};
    int i = 0;
    while(true)
    {
        
        if (comp_str == comp_name[i])
        {
            comp_str = comp_code[i];
            break;
        }
        i++;
    }
    return comp_str;

}


//FUNCTION TO HANDLE AND CONVERT C INSTRUCTION TO MACHINE LANGUAGE
void C_inst_generator(string line)
{
    int dest_pos = 0;
    int jmp_pos = 0;
    string C_instr[4];
    C_instr[0] = "111";
 //COMPUTATION OF DEST
    for (int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == '=')
        {
            string dest_str = line.substr(0, i);
            C_instr[2] = dest_generator(dest_str); 
            dest_pos = i+1;
            break;
        }
        else
        {
            C_instr[2] = "000";
        }
    }
//COMPUTATION OF JMP
    for (int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == ';')
        {
            string jmp_str = line.substr(i+1);
            C_instr[3] = jmp_generator(jmp_str); 
            jmp_pos = i-1;
            break;
        }
        else
        {
            C_instr[3] = "000";
        }
    }

////////////////////////////////////////////////
    if (dest_pos == 0 && jmp_pos != 0)
    {
        jmp_pos++;
    }
    if (dest_pos == 0 && jmp_pos+1 == 1)
    {
        jmp_pos++;
    }
    
    
//COMPUTATION OF COMP
    if (jmp_pos == 0)
    {
        string comp_str = line.substr(dest_pos);
        C_instr[1] = comp_generator(comp_str); 

    }
    else 
    {
        string comp_str = line.substr(dest_pos, jmp_pos);
        C_instr[1] = comp_generator(comp_str); 

    }

    if (C_instr[1] !="" || C_instr[2] !="" || C_instr[3] !="")
    {
        C_output(C_instr);
    }
}

// FUNCTION TO REMOVE ANY EXISTING FILE CONTAINING OLD MACHINE CODE
void file_delete()
{
    ifstream del_file;
    del_file.open("machinecode_t2.hack");
    if(!del_file){}
    else
    {
        del_file.close();
        remove("machinecode_t2.hack");
    }
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//FUNCTION REMOVES WHITESPACES AND COMMENTS FROM EACH LINE OF THE STRING 
string remove_spaces(string str)
{
    int mark = str.find('/');
    string sub = str.substr(0, mark);
    sub.erase(remove(sub.begin(), sub.end(), ' '), sub.end());
    
    return sub;
}

//FUNCTION TO INITIALIZE TABLE WITH PREDEFINED SYMBOLS AND VALUES
map<string,int> init_table(map<string, int> m)
{
    m.insert({"R0",0});
    m.insert({"R1",1});
    m.insert({"R2",2});
    m.insert({"R3",3});
    m.insert({"R4",4});
    m.insert({"R5",5});
    m.insert({"R6",6});
    m.insert({"R7",7});
    m.insert({"R8",8});
    m.insert({"R9",9});
    m.insert({"R10",10});
    m.insert({"R11",11});
    m.insert({"R12",12});
    m.insert({"R13",13});
    m.insert({"R14",14});
    m.insert({"R15",15});
    m.insert({"SCREEN",16384});
    m.insert({"KBD",24576});
    m.insert({"SP",0});
    m.insert({"LCL",1});
    m.insert({"ARG",2});
    m.insert({"THIS",3});
    m.insert({"THAT",4});
    return m;
}

//FUNCTION TO FIND AND INSERT LABEL AND THEIR VALUES IN TABLE
void find_labels(map<string,int> &m)
{
    fstream read_file;
    read_file.open("machinecode_t2.asm", ios :: in);
    if (!read_file)
    {
        cout << "No such file exist in directory" << endl;
    }
    else
    {
        string line;
        int line_no = 0;
        while (true) 
        {
			getline(read_file, line);
            line = remove_spaces(line);
            
            
            //TO FIND AND INSERT LABEL AND VALUES INSTRUCTIONS
            if (line[0] == '(' && line[(line.size())-1] == ')')
            {
                    string lbl_name = line.substr(1, line.size()-2);
                    m.insert({lbl_name,line_no});
            }

            if(line!= "" && (line[0] != '(' && line[(line.size())-1] != ')')){line_no++;}

            if (read_file.eof()) {break;}
		}
        read_file.close();
    }

} 

//FUNCTION TO FIND AND INSERT VARIBLES AND VALUES IN TABLE
void find_variables(map<string,int> &m)
{
    fstream read_file;
    read_file.open("machinecode_t2.asm", ios :: in);
    if (!read_file)
    {
        cout << "No such file exist in directory" << endl;
    }
    else
    {
        string line;
        int var_no = 16;
        while (true) 
        {
			getline(read_file, line);
            line = remove_spaces(line);
                        
            //TO FIND AND INSERT VARIABLES AND VALUES
            if ((line[0] == '@' ) && (line[1] != '0' && line[1] != '1' && line[1] != '2' && line[1] != '3' && line[1] != '4' && line[1] != '5' && line[1] != '6' && line[1] != '7' && line[1] != '8' && line[1] != '9' ))
            {
                    string lbl_name = line.substr(1, line.size()-1);
                    if(m.count(lbl_name) == 0)
                    {
                        m.insert({lbl_name,var_no});
                        var_no++;
                    }

            }

            if (read_file.eof()) {break;}
		}
        read_file.close();
    }

} 

//FUNCTION TO REPLACE VALUES FROM THE TABLE TO FILE
void table_replace(map<string,int> &m)
{
    fstream read_file;
    read_file.open("machinecode_t2.asm", ios :: in);
    if (!read_file)
    {
        cout << "No such file exist in directory" << endl;
    }
    else
    {
        string line;
        while (true) 
        {
			getline(read_file, line);
            line = remove_spaces(line);

            if(line[0] == '@')
            {
                if (line[0] == '@' && (line[1] != '0' && line[1] != '1' && line[1] != '2' && line[1] != '3' && line[1] != '4' && line[1] != '5' && line[1] != '6' && line[1] != '7' && line[1] != '8' && line[1] != '9' ))
                {
                    string lbl_name = line.substr(1, line.size()-1);
                    int to_num = 0;
                    auto itr = m.find(lbl_name);
                    to_num = itr->second;
                    A_inst_generator(to_num);
                }
                else 
                {
                    string sub_str = line.substr(1, line.size()-1);
                    int to_num = 0;
                    stringstream ss;  
                    ss << sub_str;  
                    ss >> to_num;
                    A_inst_generator(to_num);
                }
            }
            else if (line[0] == '(' && line[(line.size())-1] == ')')
            {
                continue;
            }
            else
            {
                    C_inst_generator(line);
            }

            if (read_file.eof()) {break;}
		}
        read_file.close();
    }

}


int main()
{
    file_delete();                      
    map<string, int> table;             //created an empty table
    table = init_table(table);          //initialize table with predefined symbols and values
    find_labels(table);                 //finding and inserting values of labels in table
    find_variables(table);              //finding and inserting values of variables in table
    table_replace(table);               //Replace and generate Machine code
    
    return 0;
}