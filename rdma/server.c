
#include <stdlib.h>
#include <rdma/rdma_cma.h>

int main(void)
{
	// create the communication identifier
	struct rdma_cm_id *cmid = malloc(sizeof(struct rdma_cm_id));
	char *context = "rdmasample";
	if (rdma_create_id(NULL, &cmid, context, RDMA_PS_TCP) != 0){
		//TODO handle error
	}

	// destrou the communication identifier
	if (rdma_destroy_id(cmid) != 0) {
		//TODO handle error
		return -1;
	}
	return 0;
}
