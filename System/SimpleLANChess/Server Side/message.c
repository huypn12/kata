#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

/**
 * Sample message_construct
 * {
 *  cmd : move;
 *  arg : usr1;
 *  arg1 : usr2;
 *  option : e4e6;
 * }
*/

message_t message_construct (
        CommandCode cmd,
        char *arg,
        char *arg1,
        char *option,
        char *option1
        )
{
    message_t msg = (message_t) malloc (sizeof(struct message));

    msg->cmd = cmd;
    strcpy (msg->arg, arg);
    strcpy (msg->arg1, arg1);
    strcpy (msg->option, option);
    strcpy (msg->option1, option1);

    return msg;
}

message_t message_parse (char msg[MESSAGE_MAXLEN])
{
    /**
     * Detect existing fields
     */
    int cmd = 0;
    char *cmd_appear = strstr(msg, CMD_DECL);
    if (cmd_appear != NULL) {
        char *pch = strchr (cmd_appear, ';');
        char *cmd_str = NULL;
        cmd_str = (char *) malloc (COMP_MAXLEN);
        strncpy(cmd_str, cmd_appear+strlen(CMD_DECL), pch-cmd_appear-strlen(CMD_DECL));
        cmd = atoi(cmd_str);
    } else {
        perror("CMD must not be NULL");
    }

    char *arg = NULL;
    char *arg_appear = strstr(msg, ARG_DECL);
    if (arg_appear != NULL) {
        char *pch = strchr (arg_appear, ';');
        arg = (char *) malloc (COMP_MAXLEN);
        strncpy(arg, arg_appear+strlen(ARG_DECL), pch-arg_appear-strlen(ARG_DECL));
    } else {
        arg = (char *) malloc (1);
        strncpy(arg, "", 1);
    }

    char *arg1 = NULL;
    char *arg1_appear = strstr(msg, ARG1_DECL);
    if (arg1_appear != NULL) {
        char *pch = strchr (arg1_appear, ';');
        arg1 = (char *) malloc (COMP_MAXLEN);
        strncpy(arg1, arg1_appear+strlen(ARG1_DECL), pch-arg1_appear-strlen(ARG1_DECL));
    } else {
        arg1 = (char *) malloc (1);
        strncpy (arg1, "", 1);
    }

    char *option = NULL;
    char *option_appear = strstr (msg, OPTION_DECL);
    if (option != NULL) {
        char *pch = strchr (option_appear, ';');
        option = (char *) malloc (COMP_MAXLEN);
        strncpy (option, option_appear+strlen(OPTION_DECL), pch-option_appear-strlen(OPTION_DECL));
    } else {
        option = (char *) malloc (1);
        strncpy (option, "", 1);
    }

    char *option1 = NULL;
    char *option1_appear = strstr (msg, OPTION1_DECL);
    if (option1 != NULL) {
        char *pch = strchr (option1_appear, ';');
        option1 = (char *) malloc (COMP_MAXLEN);
        strncpy (option1, option1_appear+strlen(OPTION1_DECL), pch-option1_appear-strlen(OPTION1_DECL));
    } else {
        option1 = (char *) malloc (1);
        strncpy (option1, "", 1);
    }

    /**
     * Make new message
     */

    return message_construct (cmd, arg, arg1, option, option1);

}

char* message_toString (message_t msg)
{
    char mesgStr[MESSAGE_MAXLEN];

    strcpy (mesgStr, "{ ");
    strcat (mesgStr, CMD_DECL);
    char buffer[COMP_MAXLEN];
    sprintf(buffer, "%d", msg->cmd);
    strcat (mesgStr, buffer);
    strcat (mesgStr, "; ");
    strcat (mesgStr, ARG_DECL);
    strcat (mesgStr, msg->arg);
    strcat (mesgStr, "; ");
    strcat (mesgStr, ARG1_DECL);
    strcat (mesgStr, msg->arg1);
    strcat (mesgStr, "; ");
    strcat (mesgStr, OPTION_DECL);
    strcat (mesgStr, msg->arg1);
    strcat (mesgStr, "; ");
    strcat (mesgStr, OPTION1_DECL);
    strcat (mesgStr, msg->arg1);
    strcat (mesgStr, "; ");
    strcat (mesgStr, "}");

    return mesgStr;
}
/*
 int main(void)
 {
     char *mesg = "{cmd : 2 ; arg : e2e3;}";
     message_t newMesg = message_parse (mesg);
     printf("%d\n", newMesg->cmd);
     printf("%s\n", message_toString(message_parse(message_toString(newMesg))));
     return 0;
 }
*/