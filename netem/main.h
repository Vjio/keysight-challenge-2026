#include <pthread.h>

// UDP PACKETS WILL BE DUPLICATED RANDOMLY
// TCP WILL BE DROPPED RANDOMLY
// ICMP WILL BE DELAYED RANDOMLY
// DEFINES FOR PACKET CLASIFICATION 
#define IP_BROADCAST		FFFFFFFF
#define UDP_PROTOCOL		17
#define TCP_PROTOCOL		6
#define IP_PROTOCOL_ICMP	1

#define DELAY_MIN_MS  50
#define DELAY_MAX_MS 150

struct ctx {
    // condition for telling producer when PQ's have data
    pthread_cond_t *cond_PQ_data;
    // lock for it
    pthread_mutex_t *lock_PQ_data;

    // condition for telling consumer when they can write to TX
    pthread_cond_t *cond_send_to_tx;
    // lock for it
    pthread_mutex_t *lock_send_to_tx;
};
