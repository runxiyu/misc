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

	 .in_pass = STRING("eeeee"),
	 .out_pass = STRING("eeeee"),

	 .protocol = INSPIRCD3_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 1,
	 .ignore_local_kills = 1,

	 .autoconnect = 1,
	 .autoconnect_type = NET_TYPE_OPENSSL_BUFFERED,
	 .address = STRING("irc.runxiyu.org"),
	 .port = STRING("7005"),
	},
	{
	 .name = STRING("inspircd.laptop.rx"),
	 .sid = STRING("10F"),

	 .in_pass = STRING("eeeee"),
	 .out_pass = STRING("eeeee"),

	 .protocol = INSPIRCD4_PROTOCOL,

	 .ignore_remote_unlinks = 0,
	 .ignore_remote_kills = 1,
	 .ignore_local_kills = 1,

	 .autoconnect = 0,
	},
};

size_t SERVER_CONFIG_LEN = sizeof(SERVER_CONFIG) / sizeof(*SERVER_CONFIG);
#endif

struct string SID = STRING("5HX");
struct string SERVER_NAME = STRING("jellyfish.laptop.rx");
struct string SERVER_FULLNAME = STRING("HaxIRCd");
time_t PING_INTERVAL = 60;

#if (defined(USE_GNUTLS_NETWORK) || defined(USE_GNUTLS_BUFFERED_NETWORK))
char GNUTLS_USE_SYSTEM_TRUST = 1;
char *GNUTLS_CERT_PATH = "/home/runxiyu/.local/share/secrets/haxircd.crt";
char *GNUTLS_KEY_PATH = "/home/runxiyu/.local/share/secrets/haxircd.key";
#endif
#if (defined(USE_OPENSSL_NETWORK) || defined(USE_OPENSSL_BUFFERED_NETWORK))
char OPENSSL_USE_SYSTEM_TRUST = 1;
char *OPENSSL_CERT_PATH = "/home/runxiyu/.local/share/secrets/haxircd.crt";
char *OPENSSL_KEY_PATH = "/home/runxiyu/.local/share/secrets/haxircd.key";
#endif

#ifdef USE_SERVER
unsigned short SERVER_PORTS[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#if (defined(USE_PLAINTEXT_NETWORK) || defined(USE_PLAINTEXT_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 13101,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 13102,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD4_PROTOCOL] = 13103,
#endif
#endif
#if (defined(USE_GNUTLS_NETWORK) || defined(USE_GNUTLS_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 13111,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 13112,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD4_PROTOCOL] = 13113,
#endif
#endif
#if (defined(USE_OPENSSL_NETWORK) || defined(USE_OPENSSL_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 13121,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 13122,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD4_PROTOCOL] = 13123,
#endif
#endif
};

size_t SERVER_LISTEN[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#if (defined(USE_PLAINTEXT_NETWORK) || defined(USE_PLAINTEXT_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD4_PROTOCOL] = 16,
#endif
#endif
#if (defined(USE_GNUTLS_NETWORK) || defined(USE_GNUTLS_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD4_PROTOCOL] = 16,
#endif
#endif
#if (defined(USE_OPENSSL_NETWORK) || defined(USE_OPENSSL_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 16,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD4_PROTOCOL] = 16,
#endif
#endif
};

char SERVER_INCOMING[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#if (defined(USE_PLAINTEXT_NETWORK) || defined(USE_PLAINTEXT_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD3_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_PLAINTEXT][INSPIRCD4_PROTOCOL] = 1,
#endif
#endif
#if (defined(USE_GNUTLS_NETWORK) || defined(USE_GNUTLS_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD3_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_GNUTLS][INSPIRCD4_PROTOCOL] = 1,
#endif
#endif
#if (defined(USE_OPENSSL_NETWORK) || defined(USE_OPENSSL_BUFFERED_NETWORK))
#ifdef USE_INSPIRCD2_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD3_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD3_PROTOCOL] = 1,
#endif
#ifdef USE_INSPIRCD4_PROTOCOL
	[NET_TYPE_OPENSSL][INSPIRCD4_PROTOCOL] = 1,
#endif
#endif
};
#endif

#ifdef USE_HAXSERV_PSEUDOCLIENT
struct string HAXSERV_UID = STRING("5HX000000");
struct string HAXSERV_NICK = STRING("Jellyfish");
struct string HAXSERV_FULLNAME = STRING("Jellyfish");
struct string HAXSERV_IDENT = STRING("Jellyfish");
struct string HAXSERV_VHOST = STRING("services/Jellyfish");
struct string HAXSERV_HOST = STRING("/dev/full");
struct string HAXSERV_ADDRESS = STRING("/dev/null");
struct string HAXSERV_PREJOIN_CHANNELS[] = {
	STRING("#chat"),
	STRING("#services"),
	STRING("#spam"),
};
size_t HAXSERV_NUM_PREJOIN_CHANNELS =
    sizeof(HAXSERV_PREJOIN_CHANNELS) / sizeof(*HAXSERV_PREJOIN_CHANNELS);
struct string HAXSERV_COMMAND_PREFIX = STRING("Jellyfish: ");
struct string HAXSERV_REQUIRED_OPER_TYPE = STRING("NetAdmin");
struct string HAXSERV_LOG_CHANNEL = STRING("#services");
#endif

#ifdef USE_PLAINTEXT_BUFFERED_NETWORK
size_t PLAINTEXT_BUFFERED_LEN = 1048576;
#endif
#ifdef USE_GNUTLS_BUFFERED_NETWORK
size_t GNUTLS_BUFFERED_LEN = 1048576;
#endif
#ifdef USE_OPENSSL_BUFFERED_NETWORK
size_t OPENSSL_BUFFERED_LEN = 1048576;
#endif

#ifdef USE_SERVICES_PSEUDOCLIENT
struct string NICKSERV_UID = STRING("5HX0000NS");
struct string NICKSERV_NICK = STRING("JellyNickServ");
struct string NICKSERV_FULLNAME = STRING("Nickname Services");
struct string NICKSERV_IDENT = STRING("JellyNickServ");
struct string NICKSERV_VHOST = STRING("services/JellyNickServ");
struct string NICKSERV_HOST = STRING("localhost");
struct string NICKSERV_ADDRESS = STRING("/dev/null");
struct string SERVICES_CHANNEL = STRING("#services");
size_t SERVICES_DB_MAX_SIZE = 104857600;
struct string SERVICES_DB_PATH = STRING("services.db");
#endif
