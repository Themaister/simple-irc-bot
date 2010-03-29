#include "socket.h"

// irc_pong: For answering pong requests...
int irc_pong(const char *data)
{
   return sck_sendf("PONG :%s\r\n", data);
}

// irc_reg: For registering upon login
int irc_reg(const char *nick, const char *username, const char *fullname)
{
   return sck_sendf("NICK %s\r\nUSER %s localhost 0 :%s\r\n", nick, username, fullname);
}

// irc_join: For joining a channel
int irc_join(const char *data)
{
   return sck_sendf("JOIN %s\r\n", data);

   return 0;
}

// irc_part: For leaving a channel
int irc_part(const char *data)
{
   return sck_sendf("PART %s\r\n", data);

   return 0;
}

// irc_nick: For changing your nick
int irc_nick(const char *data)
{
   return sck_sendf("NICK %s\r\n", data);

   return 0;
}

// irc_quit: For quitting IRC
int irc_quit(const char *data)
{
   {
      if (sck_sendf("QUIT :%s\r\n", data))
      {
         closesocket(server_socket);

         return 1;
      }
   }
   return 0;
}

// irc_topic: For setting or removing a topic
int irc_topic(const char *channel, const char *data)
{
   return sck_sendf("TOPIC %s :%s\r\n", channel, data);

   return 0;
}

// irc_action: For executing an action (.e.g /me is hungry)
int irc_action(const char *channel, const char *data)
{
   return sck_sendf("PRIVMSG %s :\001ACTION %s\001\r\n", channel, data);

   return 0;
}

// irc_msg: For sending a channel message or a query
int irc_msg(const char *channel, const char *data)
{
   return sck_sendf("PRIVMSG %s :%s\r\n", channel, data);

   return 0;
}
