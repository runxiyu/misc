// One of the code files for HaxServ
//
// Written by: Test_User <hax@andrewyu.org>
//
// This is free and unencumbered software released into the public
// domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include <time.h>

#include "config.h"
#include "general_network.h"
#include "protocols.h"

#ifdef USE_SERVER
#include "server_network.h"
#endif

#ifdef USE_SERVER
struct server_config SERVER_CONFIG[] = {
	{
	 .name = STRING("irc.runxiyu.org"),
	 .sid = STRING("101"),

	 .in_pass =
	 STRING(""),
	 .out_pass =
	 STRING(""),

	 .protocol = INSPIRCD2_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 1,
	 .ignore_local_kills = 1,

	 .autoconnect = 1,
	 .autoconnect_type = NET_TYPE_OPENSSL,

	 .address = STRING("irc.runxiyu.org"),
	 .port = STRING("7005"),
	 },
	{
	 .name = STRING("hax.hax.irc.andrewyu.org"),
	 .sid = STRING("1HC"),

	 .in_pass =
	 STRING
	 (""),
	 .out_pass =
	 STRING
	 (""),

	 .protocol = INSPIRCD2_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 0,
	 .ignore_local_kills = 0,

	 .autoconnect = 0,
	 },
	{
	 .name = STRING("py.hax.irc.andrewyu.org"),
	 .sid = STRING("1PY"),

	 .in_pass =
	 STRING
	 (""),
	 .out_pass =
	 STRING
	 (""),

	 .protocol = INSPIRCD2_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 0,
	 .ignore_local_kills = 0,

	 .autoconnect = 0,
	 },
	{
	 .name = STRING("lua.hax.irc.andrewyu.org"),
	 .sid = STRING("1LU"),

	 .in_pass =
	 STRING
	 (""),
	 .out_pass =
	 STRING
	 (""),

	 .protocol = INSPIRCD2_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 0,
	 .ignore_local_kills = 0,

	 .autoconnect = 0,
	 },
};

size_t SERVER_CONFIG_LEN = sizeof(SERVER_CONFIG) / sizeof(*SERVER_CONFIG);
#endif

struct string SID = STRING("1HZ");
struct string SERVER_NAME = STRING("jellyfish.irc.runxiyu.org");
struct string SERVER_FULLNAME = STRING("HaxIRCd");
time_t PING_INTERVAL = 60;

#ifdef USE_GNUTLS
char GNUTLS_USE_SYSTEM_TRUST = 1;
char *GNUTLS_CERT_PATH = "/home/runxiyu/.local/share/secrets/haxircd.crt";
char *GNUTLS_KEY_PATH = "/home/runxiyu/.local/share/secrets/haxircd.key";
#endif

#ifdef USE_OPENSSL
char OPENSSL_USE_SYSTEM_TRUST = 1;
char *OPENSSL_CERT_PATH = "/home/runxiyu/.local/share/secrets/haxircd.crt";
char *OPENSSL_KEY_PATH = "/home/runxiyu/.local/share/secrets/haxircd.key";
#endif

#ifdef USE_SERVER
unsigned short SERVER_PORTS[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#ifdef USE_PLAINTEXT
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 7001,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 7002,
#endif
#endif
#ifdef USE_GNUTLS
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 7011,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 7012,
#endif
#endif
#ifdef USE_OPENSSL
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 7021,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 7022,
#endif
#endif
};

size_t SERVER_LISTEN[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#ifdef USE_PLAINTEXT
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 16,
#endif
#endif
#ifdef USE_GNUTLS
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 16,
#endif
#endif
#ifdef USE_OPENSSL
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 16,
#endif
#endif
};

char SERVER_INCOMING[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#ifdef USE_PLAINTEXT
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 0,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 0,
#endif
#endif
#ifdef USE_GNUTLS
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 0,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 0,
#endif
#endif
#ifdef USE_OPENSSL
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 0,
#endif
#endif
};
#endif

#ifdef USE_HAXSERV_PSEUDOCLIENT
struct string HAXSERV_UID = STRING("1HZ000000");
struct string HAXSERV_NICK = STRING("Jellyfish");
struct string HAXSERV_FULLNAME = STRING("Jellyfish");
struct string HAXSERV_IDENT = STRING("Jellyfish");
struct string HAXSERV_VHOST =
STRING("rx' one service to rule them all: Jellyfish™");
struct string HAXSERV_HOST = STRING("/dev/full");
struct string HAXSERV_ADDRESS = STRING("/dev/null");

struct string HAXSERV_PREJOIN_CHANNELS[] = {
	STRING("#chat"),
	STRING("#services"),
	STRING("#spam"),
};

size_t HAXSERV_NUM_PREJOIN_CHANNELS =
    sizeof(HAXSERV_PREJOIN_CHANNELS) / sizeof(*HAXSERV_PREJOIN_CHANNELS);

struct string HAXSERV_COMMAND_PREFIX = STRING("%");

struct string HAXSERV_REQUIRED_OPER_TYPE = STRING("NetAdmin");

struct string HAXSERV_LOG_CHANNEL = STRING("#services");
#endif

#ifdef USE_OPENSSL_BUFFERED
size_t OPENSSL_BUFFERED_LEN = 1048576;
#endif

#ifdef USE_HAXSERV_PSEUDOCLIENT
struct string NICKSERV_UID = STRING("1HZ010100");
struct string NICKSERV_NICK = STRING("NukeServ");
struct string NICKSERV_FULLNAME = STRING("Nukename Services");
struct string NICKSERV_IDENT = STRING("NukeServ");
struct string NICKSERV_VHOST = STRING("services/NukeServ");
struct string NICKSERV_HOST = STRING("localhost");
struct string NICKSERV_ADDRESS = STRING("/dev/null");
struct string SERVICES_CHANNEL = STRING("#services");
size_t SERVICES_DB_MAX_SIZE = 104857600;
#endif
