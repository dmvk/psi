GENERATED=msg_svc.c msg.h msg_clnt.c msg_xdr.c
BIN=nums_client nums_server

all:
	rpcgen msg.x
	gcc nums_client.c msg_xdr.c msg_clnt.c -o nums_client
	gcc nums_server.c msg_xdr.c msg_svc.c -o nums_server
	rm -rf ${GENERATED}

clean:
	rm -rf ${GENERATED} ${BIN}
	
