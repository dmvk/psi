#include <stdlib.h>
#include "msg.h"

output do_the_magic_1_svc(input in, struct svc_req *req) {
	static output out;
	out = (output_t *) malloc(sizeof(output_t));
	out->sum = in->first + in->second;
	out->diff = in->first - in->second;
	out->product = in->first * in->second;
	return out;
}
