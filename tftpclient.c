/* 
 * Name: Melissa W. Huang
 * PID:	A08162136
 * Email: mwhuang@ucsd.edu
 * Class: cse 123
 * Description:
 */

#include        <stdio.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include 	<strings.h>
#include 	<stdlib.h>
#include 	<string.h>

#define SERV_UDP_PORT 6132 //6100+group # 
#define SERV_HOST_ADDR "127.0.0.1"

/* A pointer to the name of this program for error reporting.      */

char *progname;

/* Size of maximum message to send.                                */
#define MAXLINE 512
/* Number of timeout						*/
#define TIMEOUT 10
/* Filename's size*/
#define FILENAMESIZE 128
/* Mode's size */
#define MODESIZE 128
/* Default mode */
#define MODE "octect"

/*opcodes supported*/
#define RRQ 1
#define WRQ 2
#define DATA 3
#define ACK 4
#define ERROR 5

/* will be put in a header file*/
struct tftp_rrq_wrq{
          signed short int opcode;  /* 2 bytes for opcode */
	  char filename[FILENAMESIZE]; /* suppose to be a string for filename...not sure if this will work */
          char zero;       /* 1 byte for...*/
          char mode[MODESIZE];      /* string for mode */
          char zero_1;       /* 1 byte for ..*/
};

/* main function for client side*/
int main (int argc, char *argv[]){

	/*checking the number of argument passed in */
	/*tftpclient -r filename	*/
	/*tftpclient -w filename	*/
	if (argc<3){
		printf("Invalid number of argument");
	}

	int 	sockfd;
	/* We need to set up two addresses, one for the client and one for */
	/* the server.                                                     */
	struct sockaddr_in      cli_addr, serv_addr;
	progname = argv[0];

	/* Initialization */
	FILE * filename;

	/* Initialize the server's data with the well-known numbers. */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family      = AF_INET;

	/* The system needs a 32 bit integer as an Internet address, so we */
	/* use inet_addr to convert the dotted decimal notation to it.     */

	serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
	serv_addr.sin_port        = htons(SERV_UDP_PORT);

	/* Create the socket for the client side.                          */
	//int socket(int domanin, int type, int protocol)
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		printf("%s: can't open datagram socket\n",progname);
		exit(1);	
	}

	/* Initialize the structure holding the local address data to      */
	/* bind to the socket.                                             */
	bzero((char *) &cli_addr, sizeof(cli_addr));
	cli_addr.sin_family      = AF_INET;
	
	/* Let the system choose one of its addresses for you. You can     */
	/* use a fixed address as for the server.                          */
	cli_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	/* The client can also choose any port for itself (it is not       */
	/* well-known). Using 0 here lets the system allocate any free     */
	/* port to our program.                                            */
	cli_addr.sin_port        = htons(0);
	
	/* The initialized address structure can be now associated with    */
	/* the socket we created. Note that we use a different parameter   */
	/* to exit() for each type of error, so that shell scripts calling */
	/* this program can find out how it was terminated. The number is  */
	/* up to you, the only convention is that 0 means success.         */
	if (bind(sockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0)
	{
		 printf("%s: can't bind local address\n",progname);
		 exit(2);
	}

	//check if it is read or write?
	char * opt=argv[1];
	char opt1[]="-r";
	char opt2[]="-w";
	if(strcmp(opt, opt1)==0){
		struct tftp_rrq;
		tftp_rrq.opcode=RRQ;	//set the opcode
		strcpy(filename, tftp_rrq.filename); //set the filename
		tftp_rrq.zero1=0;	//set the zero 
		strcpy(mode, tftp_rrq.mode);	//set the mode
		tftp_rrq.zero2=0;
       		//set up the format of the packet?
       		//send the request
		//recieve data?
		//reset the time to go off
		//sends acknowlegment?
		
	}
	else if(strcmp(opt, opt1)==1){
                //set up the format of the packet?
                //send the request
		//receive acknowlegment?
		//sends data?
		//set the timer
		//count the num of retry
	}
	else{
		//terminates because option is invalid, opt has be to -r or -w	
	}
		

	
	return 0;
}


	
 
