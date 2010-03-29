#ifndef __IRC_H
#define __IRC_H

int irc_pong(const char *pong);
int irc_reg(const char *nick, const char *username, const char *fullname);
int irc_join(const char *channel);
int irc_part(const char *data);
int irc_nick(const char *nick);
int irc_quit(const char *quit_msg);
int irc_topic(const char *channel, const char *data);
int irc_action(const char *channel, const char *data);
int irc_msg(const char *channel, const char *data);

#endif
