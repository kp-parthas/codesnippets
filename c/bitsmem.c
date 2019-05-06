#include <stdio.h>

#define NUMBITS 8

int get_num_bitset(unsigned char a, int startbit)
{
	int cnt=0;
	a >>= startbit;
	while (a) {
		if (a & 0x1) {
			cnt++;
		} else {
			break;
		}
		a >>= 1;
	}
	return cnt;
}
int get_first_bitset(unsigned char a, int startbit)
{
	int bitno = startbit-1;
	a >>= startbit;
	while (a) {
		bitno++;
		if (a & 0x1) {
			return bitno;
		}
		a >>= 1;
	}
	return -1;
}

int get_bit_pos(unsigned char *bitstr, int numbytes, int blksize, int *retsize)
{
	int i=0, j=0;
	int bit_pos=-1, byte_pos = 0, bit_size = 0;
	int start_bit=0, num_bits_set;
	while (i<numbytes) {
		bit_pos = get_first_bitset(bitstr[i], start_bit);
		printf("firstbit at i=%d, start=%d, pos=%d\n", i, start_bit, bit_pos);
		if (bit_pos < 0) {
			i++;
			start_bit = 0;
			continue;
		}
		for (j=i; j < numbytes; j++) {
			start_bit = (bit_size==0)?bit_pos:0;
			num_bits_set = get_num_bitset(bitstr[j], start_bit);
			bit_size += num_bits_set;
			printf("numbits at j=%d, start_bit=%d, bits=%d, size=%d\n", j, start_bit, num_bits_set, bit_size);

			if (bit_size >= blksize) {
				*retsize = bit_size;
				return (i*8 + bit_pos);
			}

			if (start_bit+num_bits_set < NUMBITS) {
				if (num_bits_set)
					start_bit += num_bits_set;
				else
					start_bit +=1;
				if (start_bit >= NUMBITS) {
					start_bit = 0;
				}
				bit_pos = -1;
				bit_size = 0;
				i = j+1;
				break;
			}
		}
	}
	return -1;
}

int main()
{
	int pos, size;
	unsigned char str[]= {0x0, 0x0F, 0, 0xF0, 0xFF, 0};
	pos = get_bit_pos(str, sizeof(str)/sizeof(char), 5, &size);
	printf("pos=%d, size=%d\n", pos, size);
}
