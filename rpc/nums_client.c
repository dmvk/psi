#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int main(int argc, char **argv) {
	CLIENT *client;
	input in;
	output out;
	if (argc != 4) {
		fprintf(stderr, "Usage: %s <server> <num1> <num2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	in = (input_t *) malloc(sizeof(input_t));
	in->first = atoi(argv[2]);
	in->second = atoi(argv[3]);
	client = clnt_create(argv[1], NUMSPROG, NUMSVERS, "tcp");
	if (client == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(EXIT_FAILURE);
	}
	out = do_the_magic_1(in, client);
	if (out == (output_t *) NULL) {
		clnt_perror(client, argv[1]);
		printf("mrdka");
		exit(EXIT_FAILURE);
	}
	printf("response:\n - sum %d\n - diff %d \n - product %d\n", out->sum, out->diff, out->product);
	clnt_destroy(client);
	return EXIT_SUCCESS;
}
