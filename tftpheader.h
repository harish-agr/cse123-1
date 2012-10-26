#ifndef TFTPHEADER_H
#define TFTPHEADER_H


#define SERV_TID 6132 //6100+group # 
#define CLIENT_TID
#define SERV_HOST_ADDR "127.0.0.1"


/* tftp error messages given in the project statement*/
char * tftp_errors[]={
	"Not defined, see error message (if any).",
	"File not found.",
	"Access violation.",
	"Disk full or allocation exceeded.",
	"Illegal TFTP operation.",
	"Unknown transfer ID.",
	"File already exists",
	"No such user."
};

/*tftp packet header information*/
struct tftp_packet{
		/* Internet header */
		/* Datagram header */
		/* TFTP header */
		/* remainder of the TFTP packet */
};

struct tftp_rrq_wrq{
		/* 2 bytes for opcode */
 		/* string for filename */
		/* 1 byte for...*/
		/* string for mode */
		/* 1 byte for ..*/
};

struct tftp_data{
		/* 2 bytes for opcode*/
		/* 2 bytes for block #*/
		/* n bytes for data*/
};

struct tftp_ack{
		/* 2 bytes for opcode */
		/* 2 bytes for block #*/
};

struct tftp_error{
		/* 2 bytes for opcode */
		/* 2 bytes for errorcode */
		/* string for error message */
		/* 1 byte for ...*/
};


#endif
