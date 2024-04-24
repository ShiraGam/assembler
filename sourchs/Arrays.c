
#include "Arrays.h"
#include "Global_def.h"

void set_bit(bit_field *bitfield, int pos, int value) {
    if (value)
        bitfield->data |= (1 << pos);
    else
        bitfield->data &= ~(1 << pos);
}




void print_bits(bit_field *array, int size) {
	int i = 0,j;
    for (; i < size; ++i) {
        unsigned int bits = array[i].data;
        for ( j = BIT_FIELD_SIZE - 1; j >= 0; --j) {
            printf("%d", (bits >> j) & 1);
        }
        printf("\n");
    }
    printf("\n\n\n");
}



