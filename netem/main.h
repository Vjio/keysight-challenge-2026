#include <pthread.h>

// UDP PACKETS WILL BE DUPLICATED RANDOMLY
// TCP WILL BE DROPPED RANDOMLY
// ICMP WILL BE DELAYED RANDOMLY
// DEFINES FOR PACKET CLASIFICATION 
#define IP_BROADCAST		FFFFFFFF
#define UDP_PROTOCOL		17
#define TCP_PROTOCOL		6
#define IP_PROTOCOL_ICMP	1

// flags for modify function
#define DUPLICATE_FLAG          1
#define DUPLICATE_FLAG_WHEN     2
#define DROP_FLAG               2
#define DROP_FLAG_WHEN          2
#define DELAY_FLAG              3
#define DELAY_FLAG_WHEN         4

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

struct thread {
    struct rte_ring *buffer_in;
    struct rte_ring *buffer_out;

    pthread_cond_t *cond_data_in;
    pthread_cond_t *lock_data_in;
    pthread_cond_t *cond_data_out;
    pthread_cond_t *lock_data_out;

    unsigned int flag;
};

int apply_modifiers(thread, flag) {
    dequee de 8 ori din buffer_in;
    // 8 packete de scris
    lock_acquire_buffer_out()
    // ne uitam la flag
    swtich (flag)
        case flag {
            // apply whatever conditie
            // pt fiecare 8 packete
            lock_unlock()
            lock_data_out()
        }
}
