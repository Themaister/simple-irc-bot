#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

int get_socket(const char* host, const char* port)
{
   int rc;
   int s;
   struct addrinfo hints, *res;

   memset(&hints, 0, sizeof(hints));

   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = AI_PASSIVE;

   if ((rc = getaddrinfo(host, port, &hints, &res) ) < 0 )
   {
      fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
      return -1;
   }

   s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
   if ( s < 0 )
   {
      fprintf(stderr, "Couldn't get socket.\n");
      goto error;
   }

   freeaddrinfo(res);
   return s;

error:
   freeaddrinfo(res);
   return -1;

}

int sck_send(int s, const char* data, size_t size)
{
   size_t written = 0;
   int rc;

   while ( written < size )
   {
      rc = send(s, data + written, size - written, 0);
      if ( rc <= 0 )
         return -1;

      written += rc;
   }

   return written;
}

int sck_sendf(int s, const char *fmt, ...)
{
   char *args;
   int snd_len;
   char snd_buf[1024];

   if (strlen(fmt) != 0)
   {
      // Format the data
      va_start(args, fmt);
      snd_len = vsnprintf(snd_buf, sizeof (snd_buf) - 1, fmt, args);
      va_end(args);

      snd_buf[sizeof (snd_buf) - 1] = '\0'; // initial memset()'ing is slower

      // Clamp the chunk
      if (snd_len < 0 || snd_len > (sizeof (snd_buf) - 1)) snd_len = strlen(snd_buf);
      if (snd_len > 512) snd_len = 512;

      if (sck_send( s, snd_buf, snd_len ) <= 0) return -1;
   }

   return 0;
}

