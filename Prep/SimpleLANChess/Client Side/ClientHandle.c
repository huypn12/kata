#include "ClientHandle.h"
#include "message.h"

#define MAXLENGTH 100
#define MAXLINE 100

char menu();

void
str_cli(int sockfd)
{
  char	*sendline, recvline[MAXLINE], ch;
  message_t newMesg, recvMesg;
  int buffrecv;

    while(1)
      {
  	ch = menu();
	switch(ch)
	  {
	  case '1':
	    printf("\n\nSIGN IN\n");
	    sendline = message_toString(getIdAndPassword(SIGNIN));
		
		if (send(sockfd, sendline, MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN) {
	      printf("send() sent a different number of bytes than expected\n");
	    }

	    if (recv(sockfd, recvline, MESSAGE_MAXLEN, 0) < 0) {
	      printf("str_cli: server terminated prematurely\n");
	      exit(1);
	    }
	    recvline[strlen(recvline)] = '\0';

	    newMesg = message_parse(recvline);
	    switch(newMesg->cmd) {
	    	case SIGNIN:
	    	printf("\nWelcome to console chess game\n");
	    	
	    	for(;;) {
	    		
	    	}


	    	mainConsoleChess(LIGHT, sockfd);
	    	break;

	    	default:
	    	printf("Fail to sign in\n");
	    	break;
	    }

	    continue;

	  case '2':
	    printf("\n\nSIGN UP\n");
	    sendline = message_toString(getIdAndPassword(SIGNUP));

	    if (send(sockfd, sendline, MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
	      printf("send() sent a different number of bytes than expected\n");
	    }

	    if (recv(sockfd, recvline, MESSAGE_MAXLEN, 0) < 0) {
	      printf("str_cli: server terminated prematurely\n");
	      exit(1);
	    }
	    recvline[strlen(recvline)] = '\0';
	    puts(recvline); //Debug

	    newMesg = message_parse(recvline);
	    switch(newMesg->cmd) {
	    	case SIGNUP:
	    	//printf("\nSuccessfull sign up id %s.\n", newMesg->arg);
	    	printf("\nSuccessfull sign up\n");
	    	break;
	    	default:
	    	printf("Fail to sign up. Maybe this account doesn't exist\n");
	    	break;
	    }
	    continue;

	  case '3':
	    printf("Exit\n", ch);
	    sendline = message_toString(message_construct(SIGNOUT, "0", "0", "0", "0"));
	    
	    if (send(sockfd, sendline, MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN) {
	      printf("send() sent a different number of bytes than expected\n");
	    }

	    if (buffrecv = recv(sockfd, recvline, MESSAGE_MAXLEN, 0) < 0) {
	      printf("str_cli: server terminated prematurely\n");
	      exit(1);
	    }
	    recvline[strlen(recvline)] = '\0';
	    puts(recvline); //Debug
	    printf("\nI'm done!\n");
	    exit(0);
	    break;

	  default:
	    printf("Wrong option! Please choose again\n");
	    continue;
	  }
	break;
      }
    printf("\n");
  
	
}

char menu()
{
  char ch;
  printf("\t\tConsole Chess\n\nCreated by Phung Nhat Huy and Pham Duy Hung\nAS K55 HEDSPI\n\n");
  printf("1. SIGN IN.\n");
  printf("2. SIGN UP.\n");
  printf("3. EXIT.\n");
  printf("\tBan chon?\n");
  ch = getchar();
  char ch1;
  while((ch1 = getchar()) != '\n');
  printf("Processing...\n");
  return ch;
}

message_t getIdAndPassword(int mesgType) {
	char id[MAXLENGTH], *pass;

	printf("ID: ");
	fgets(id, 1000, stdin);
	id[strlen(id)-1] = '\0';
	pass = getpass("Password: ");
	return message_construct(mesgType, id, pass, "0", "0");
}
