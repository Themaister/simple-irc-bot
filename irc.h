#ifndef __IRC_H
#define __IRC_H

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
