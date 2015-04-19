typedef struct input_t *input;
typedef struct output_t *output;

struct input_t {
	int first;
	int second;
};

struct output_t {
	int sum;
	int diff;
	int product;
};

program NUMSPROG {
	version NUMSVERS {
		output_t DO_THE_MAGIC(input_t) = 1;
	} = 1;
} = 0x539;

