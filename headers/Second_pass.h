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


/**
 * @brief Handles the second pass of the assembly process.
 * 
 * @param[in] structures Pointer to the data_structures structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] locations Pointer to the DC_IC structure.
 * @param[in,out] file Pointer to the file_status structure.
 * @param[in,out] file_am Pointer to the input assembly file.
 */
void second_pass_main(date_structures * structures, errors_status * errors,DC_IC * locations,struct file_status * file,FILE * file_am);

/**
 * @brief Sends the line to the respective function for processing during the second pass.
 * 
 * @param[in,out] ptp Pointer to a pointer to a character representing the line.
 * @param[in,out] file Pointer to the file_status structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] locations Pointer to the DC_IC structure.
 * @param[in,out] structures Pointer to the data_structures structure.
 * @param[in,out] file_ex Pointer to the external file.
 * @param[in] prev_ic The previous value of the instruction counter.
 */
void send_to_function_pass_two(char ** ptp,struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic);
/**
 * @brief Handles the action coding during the second pass.
 * 
 * @param[in] index_of_action The index of the action in the Opcodes table.
 * @param[in,out] ptp Pointer to a pointer to a character representing the line.
 * @param[in,out] file Pointer to the file_status structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] locations Pointer to the DC_IC structure.
 * @param[in,out] structures Pointer to the data_structures structure.
 * @param[in,out] file_ex Pointer to the external file.
 * @param[in] prev_ic The previous value of the instruction counter.
 */
void action_coding(int index_of_action,char ** ptp ,struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic);
 
/**
 * @brief Handles the coding of operands during the second pass.
 * 
 * @param[in,out] file Pointer to the file_status structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] locations Pointer to the DC_IC structure.
 * @param[in,out] structures Pointer to the data_structures structure.
 * @param[in] operand The operand to be coded.
 * @param[in,out] file_ex Pointer to the external file.
 * @param[in] source_operand Specifies if the operand is a source operand.
 * @param[in] destination_operand Specifies if the operand is a destination operand.
 * @param[in] prev_ic The previous value of the instruction counter.
 */
void coding_operand(struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,char* operand,FILE * file_ex,int source_operand,int destination_operand,int prev_ic );

/**
 * @brief Handles the coding of immediate operands during the second pass.
 * 
 * @param[in,out] file Pointer to the file_status structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] locations Pointer to the DC_IC structure.
 * @param[in,out] structures Pointer to the data_structures structure.
 * @param[in] operand The immediate operand to be coded.
 * @param[in] prev_ic The previous value of the instruction counter.
 */
void coding_immediate(struct file_status * file, errors_status * errors,DC_IC * locations,date_structures * structures,char *operand,int prev_ic );

/*get register assume that its correct*/
void coding_register(struct file_status * file,errors_status * errors,DC_IC * locations,date_structures * structures,char* register_value,int source_operand,int prev_ic );

void coding_by_index(struct file_status * file,char *operand,DC_IC * locations,date_structures * structures,errors_status * errors,FILE * file_ex,int prev_ic );

void coding_direct(struct file_status * file,errors_status * errors,char* operand,DC_IC * locations,date_structures * structures,FILE * file_ex,int prev_ic );
 
/**
 * @brief Checks if a line contains a comma.
 * 
 * @param[in] ptp Pointer to a pointer to a character representing the line.
 * 
 * @return Returns TRUE if the line contains a comma, otherwise FALSE.
 */
int contains_comma(char **ptp);


/**
 * @brief Sets a range of bits in a bitfield with a specified value.
 * 
 * @param[in] file Pointer to the file_status structure.
 * @param[in,out] errors Pointer to the errors_status structure.
 * @param[in,out] bitfield Pointer to the bit_field structure to modify.
 * @param[in] start The starting bit index of the range.
 * @param[in] end The ending bit index of the range.
 * @param[in] value The value to set in the specified bit range.
 * @param[in] prev_ic The previous value of the instruction counter.
 * @param[in] current_ic The current value of the instruction counter.
 */
void set_bit_range(struct file_status *file, errors_status *errors, bit_field *bitfield, int start, int end, int value, int prev_ic, int current_ic);


/**
 * @brief Prints the contents of the instructions array to a file in encoded format.
 * 
 * @param[in] file_ob Pointer to the file where the instructions will be printed.
 * @param[in] instructions_array Pointer to the instructions array to print.
 * @param[in] array_length The length of the instructions array.
 * @param[in] begin The starting position to print the instructions array.
 */
void print_bits_encoded(FILE *file_ob, bit_field *instructions_array, int array_length,int begin);
/**
 * @brief Closes the given external file pointer and removes it if it's empty.
 * 
 * This function closes the provided external file pointer and removes the file if it's empty.
 * It checks if the file is empty, and if so, it deletes the file from the file system.
 * 
 * @param file_ex Pointer to the external file to be closed.
 * @param errors Pointer to the errors_status struct to handle internal errors.
 * @param file_name_with_ex Name of the external file.
 */
void close_ex_file(FILE*file_ex,errors_status * errors,char * file_name_with_ex);
/**
 * @brief Prints the entries to the entry file.
 * 
 * This function prints the entry symbols and their corresponding values to the entry file.
 * It iterates through the symbols list and prints entries with their values to the entry file.
 * 
 * @param file Pointer to the file_status struct containing file-related information.
 * @param errors Pointer to the errors_status struct to handle errors.
 * @param structures Pointer to the date_structures struct containing symbol information.
 */
void print_entry(struct file_status * file, errors_status * errors,date_structures * structures);
/**
 * @brief Prints the object (".ob") file.
 * 
 * This function prints the encoded instructions and data to the object file.
 * It writes the instructions and data, along with their addresses, to the object file.
 * 
 * @param file Pointer to the file_status struct containing file-related information.
 * @param errors Pointer to the errors_status struct to handle errors.
 * @param structures Pointer to the date_structures struct containing symbol and data information.
 * @param locations Pointer to the DC_IC struct containing instruction and data counts.
 * @param prev_ic The previous instruction count.
 */
void print_ob_file(struct file_status * file, errors_status * errors,date_structures * structures,DC_IC * locations,int prev_ic);


       
#endif
