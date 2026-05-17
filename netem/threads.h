#ifndef __THREADS_H__
#define __THREADS_H__

#include <pthread.h>
#include <stdint.h>

struct thread {
    struct rte_ring *buffer_in;
    struct rte_ring *buffer_out;

    pthread_cond_t *cond_data_in;
    pthread_mutex_t *lock_data_in;

    pthread_mutex_t *lock_TX;

    unsigned int flag;
};

struct pq_thread_args {
    struct thread *thread;
    uint16_t tx_port_id;
    struct rte_eth_dev_tx_buffer **tx_buffer;
};

#endif
