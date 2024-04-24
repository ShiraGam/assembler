#ifndef SECOND_PASS_H
#define SECOND_PASS_H
#include "Global_def.h"
#include "Global_fun.h"
#include "Symbols.h"
#include "First_pass.h"
#include "Opcodes_table.h"
#include "Arrays.h"
#include "Errors.h"
#include "Reserved_words.h"




void second_pass_main(date_structures * structures, errors_status * errors,DC_IC * locations,struct file_status * file,FILE * file_am);


void send_to_function_pass_two(char ** ptp,struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic);

void action_coding(int index_of_action,char ** ptp ,struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic);
 

void coding_operand(struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,char* operand,FILE * file_ex,int source_operand,int destination_operand,int prev_ic );


void coding_immediate(struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,char *operand,int prev_ic );

/*get register assume that its correct*/
void coding_register(struct file_status * file,errors_status * errors,DC_IC * locations,date_structures * structures,char* register_value,int source_operand,int prev_ic );

void coding_by_index(struct file_status * file,char *operand,DC_IC * locations,date_structures * structures,errors_status * errors,FILE * file_ex,int prev_ic );

void coding_direct(struct file_status * file,errors_status * errors,char* operand,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic );
 



int contains_comma(char **ptp);


/*remember to delate structer!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/**
 * @brief Sets a range of bits in a bit field to a specified value.
 *
 * This function sets a range of bits in the given bit field to the specified value.
 * The range is specified by the start and end indices (inclusive).
 *
 * @param file Pointer to the file status structure.
 * @param errors Pointer to the errors status structure.
 * @param bitfield Pointer to the bit field structure.
 * @param start Starting index of the range to set.
 * @param end Ending index of the range to set.
 * @param value Value to set in the specified range.
 * @param prev_ic Previous instruction counter value.
 * @param current_ic Current instruction counter value.
 * @param structures Pointer to the date structures.
 * @param locations Pointer to the DC_IC structures.
 */
void set_bit_range(struct file_status *file, errors_status *errors, bit_field *bitfield, int start, int end, int value, int prev_ic, int current_ic);



void print_bits_encoded(FILE *file_ob, bit_field *instructions_array, int array_length,int begin);

void close_ex_file(FILE*file_ex,errors_status * errors,char * file_name_with_ex);

void print_entry(struct file_status * file, errors_status * errors,date_structures * structures);

void print_ob_file(struct file_status * file, errors_status * errors,date_structures * structures,DC_IC * locations,int prev_ic);


       
#endif
