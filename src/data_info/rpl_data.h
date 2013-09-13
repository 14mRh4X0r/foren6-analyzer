/*
 * File:   collected_data.h
 * Author: am
 *
 * Created on July 4, 2013, 10:16 AM
 */

#ifndef RPL_DATA_H
#define	RPL_DATA_H

#include "link.h"
#include "node.h"
#include "dodag.h"
#include "rpl_instance.h"
#include "hash_container.h"

#ifdef	__cplusplus
extern "C" {
#endif

void rpldata_init();

//These function use version 0. Modification to other version should not be allowed.
di_node_t *rpldata_get_node(const di_node_ref_t *node_ref, hash_value_mode_e value_mode, bool *was_already_existing);
di_dodag_t *rpldata_get_dodag(const di_dodag_ref_t *dodag_ref, hash_value_mode_e value_mode, bool *was_already_existing);
di_rpl_instance_t *rpldata_get_rpl_instance(const di_rpl_instance_ref_t *rpl_instance_ref, hash_value_mode_e value_mode, bool *was_already_existing);
di_link_t *rpldata_get_link(const di_link_ref_t *link_ref, hash_value_mode_e value_mode, bool *was_already_existing);
di_link_t *rpldata_del_link(const di_link_ref_t *link_ref);

hash_container_ptr rpldata_get_nodes(uint32_t version);
hash_container_ptr rpldata_get_dodags(uint32_t version);
hash_container_ptr rpldata_get_rpl_instances(uint32_t version);
hash_container_ptr rpldata_get_links(uint32_t version);


uint32_t rpldata_add_node_version();
uint32_t rpldata_add_dodag_version();
uint32_t rpldata_add_rpl_instance_version();
uint32_t rpldata_add_link_version();

void rpldata_wsn_create_version(int packed_id, double timestamp);
double rpldata_wsn_version_get_timestamp(uint32_t version);
uint32_t rpldata_wsn_version_get_packet_count(uint32_t version);

uint32_t rpldata_get_wsn_last_version();

void rpldata_clear();

#ifdef	__cplusplus
}
#endif

#endif	/* RPL_DATA_H */
