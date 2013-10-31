#ifndef SIXLOWPAN_DEF_H_
#define SIXLOWPAN_DEF_H_

#include <stdbool.h>
#include <stdint.h>
#include <netinet/in.h>
#include <sys/time.h>
#include "address.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct sixlowpan_config {
    bool is_custom_local_address;
    addr_ipv6_t local_address;

    bool is_custom_global_address;
    addr_ipv6_t global_address;
} sixlowpan_config_t;

typedef struct sixlowpan_config_delta {
    bool has_changed;

    bool local_address;
    bool global_address;
} sixlowpan_config_delta_t;

typedef struct sixlowpan_statistics {
    int packet_count;
} sixlowpan_statistics_t;

typedef struct sixlowpan_statistics_delta {
    bool has_changed;
    int packet_count;
} sixlowpan_statistics_delta_t;

void init_sixlowpan_config(sixlowpan_config_t *config);
void init_sixlowpan_statistics(sixlowpan_statistics_t *statistics);
void init_sixlowpan_statistics_delta(sixlowpan_statistics_delta_t *delta);

void sixlowpan_config_delta(const sixlowpan_config_t *left, const sixlowpan_config_t *right, sixlowpan_config_delta_t *delta);
void sixlowpan_statistics_delta(const sixlowpan_statistics_t *left, const sixlowpan_statistics_t *right, sixlowpan_statistics_delta_t *delta);

#ifdef  __cplusplus
}
#endif

#endif