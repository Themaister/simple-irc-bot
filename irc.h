#ifndef __IRC_H
#define __IRC_H

#include <stdio.h>

typedef struct
{
   int s;
   FILE *file;
   char channel[256];
   char *nick;
   char servbuf[512];
   int bufptr;
} irc_t; 

int irc_connect(irc_t *irc, const char* server, const char* port);
int irc_login(irc_t *irc, const char* nick);
int irc_join_channel(irc_t *irc, const char* channel);
int irc_leave_channel(irc_t *irc);
int irc_handle_data(irc_t *irc);
int irc_set_output(irc_t *irc, const char* file);
int irc_parse_action(irc_t *irc);
int irc_log_message(irc_t *irc, const char *nick, const char* msg);
int irc_reply_message(irc_t *irc, char *nick, char* msg);
void irc_close(irc_t *irc);

// IRC Protocol
int irc_pong(int s, const char *pong);
int irc_reg(int s, const char *nick, const char *username, const char *fullname);
int irc_join(int s, const char *channel);
int irc_part(int s, const char *data);
int irc_nick(int s, const char *nick);
int irc_quit(int s, const char *quit_msg);
int irc_topic(int s, const char *channel, const char *data);
int irc_action(int s, const char *channel, const char *data);
int irc_msg(int s, const char *channel, const char *data);

#endif
