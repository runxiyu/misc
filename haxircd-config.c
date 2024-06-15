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

                .in_pass = STRING("beep"),
                .out_pass = STRING("beep"),

                .protocol = INSPIRCD2_PROTOCOL,

                .ignore_remote_unlinks = 1,
                .ignore_remote_kills = 1,
                .ignore_local_kills = 1,

                .autoconnect = 1,
                .autoconnect_type = NET_TYPE_GNUTLS,

                .address = STRING("irc.runxiyu.org"),
                .port = STRING("7005"),
        },
};
size_t SERVER_CONFIG_LEN = sizeof(SERVER_CONFIG)/sizeof(*SERVER_CONFIG);
#endif

struct string SID = STRING("9JF");
struct string SERVER_NAME = STRING("jellyfish.irc.runxiyu.org");
struct string SERVER_FULLNAME = STRING("HaxIRCd");
time_t PING_INTERVAL = 60;

#ifdef USE_GNUTLS
char GNUTLS_USE_SYSTEM_TRUST = 1;
char *GNUTLS_CERT_PATH = NULL;
char *GNUTLS_KEY_PATH = NULL;
#endif

#ifdef USE_OPENSSL
char OPENSSL_USE_SYSTEM_TRUST = 1;
char *OPENSSL_CERT_PATH = NULL;
char *OPENSSL_KEY_PATH = NULL;
#endif

#ifdef USE_SERVER
unsigned short SERVER_PORTS[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#ifdef USE_PLAINTEXT
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 7000,
#endif
#endif
#ifdef USE_GNUTLS
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 7010,
#endif
#endif
#ifdef USE_OPENSSL
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 7020,
#endif
#endif
};


size_t SERVER_LISTEN[NUM_NET_TYPES][NUM_PROTOCOLS] = {
#ifdef USE_PLAINTEXT
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_PLAINTEXT][INSPIRCD2_PROTOCOL] = 16,
#endif
#endif
#ifdef USE_GNUTLS
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_GNUTLS][INSPIRCD2_PROTOCOL] = 16,
#endif
#endif
#ifdef USE_OPENSSL
#ifdef USE_INSPIRCD2_PROTOCOL
        [NET_TYPE_OPENSSL][INSPIRCD2_PROTOCOL] = 16,
#endif
#endif
};
#endif

#ifdef USE_HAXSERV_PSUEDOCLIENT
struct string HAXSERV_UID = STRING("9JF000000");
struct string HAXSERV_NICK = STRING("Jellyfish");
struct string HAXSERV_FULLNAME = STRING("Jellyfish");
struct string HAXSERV_IDENT = STRING("Jellyfish");
struct string HAXSERV_VHOST = STRING("Jellyfish");
struct string HAXSERV_HOST = STRING("/dev/full");
struct string HAXSERV_ADDRESS = STRING("/dev/null");

struct string HAXSERV_PREJOIN_CHANNELS[] = {
        STRING("#chat"),
        STRING("#services"),
        STRING("#spam"),
};
size_t HAXSERV_NUM_PREJOIN_CHANNELS = sizeof(HAXSERV_PREJOIN_CHANNELS) / sizeof(*HAXSERV_PREJOIN_CHANNELS);

struct string HAXSERV_COMMAND_PREFIX = STRING("");

struct string HAXSERV_REQUIRED_OPER_TYPE = STRING("NetAdmin");
#endif
