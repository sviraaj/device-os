#ifndef __SPARK_WIRING_USER_CFG_H__
#define __SPARK_WIRING_USER_CFG_H__

#include "spark_wiring.h"
#include "spark_wiring_platform.h"
#include "usr_fs_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
typedef struct user_cfg
{

} usr_cfg_t;
*/

/* Gateway unique id. Shall not be altered */
#define GATEWAY_ID_OFFSET 0
#define GATEWAY_ID_SIZE 16
#define GATEWAY_CFG_STATUS_OFFSET 16
#define GATEWAY_CFG_STATUS_SIZE   4
/* Gateway net type. Shall not be altered */
#define GATEWAY_NET_TYPE_OFFSET 20
#define GATEWAY_NET_TYPE_SIZE 20
/* Gateway primary server */
#define GATEWAY_PRIMARY_SERV_ADDR_OFFSET 40
#define GATEWAY_PRIMARY_SERV_ADDR_SIZE 512
/* Gateway secondary server */
#define GATEWAY_SECONDARY_SERV_ADDR_OFFSET 548
#define GATEWAY_SECONDARY_SERV_ADDR_SIZE 512
/* Gateway primary server. Shall not be altered */
#define GATEWAY_PRIMARY_SERV_ADDR_ALT_OFFSET 1060
#define GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE 512
/* Gateway secondary server. Shall not be altered */
#define GATEWAY_SECONDARY_SERV_ADDR_ALT_OFFSET 1572
#define GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE 512
/* Gateway connected devices update frequency */
#define GATEWAY_DEV_UPDATE_FREQUENCY_OFFSET 2084
#define GATEWAY_DEV_UPDATE_FREQUENCY_SIZE 8
/* Gateway to server status update frequency */
#define GATEWAY_STATUS_FREQUENCY_OFFSET 2092
#define GATEWAY_STATUS_FREQUENCY_SIZE 8
/* Gateway dhcp configuration */
#define GATEWAY_DHCP_ENABLE_OFFSET 2100
#define GATEWAY_DHCP_ENABLE_SIZE 2
/* Gateway CA cert for ssl secure comms */
#define GATEWAY_SERVER_CA_CERT_PEM_OFFSET 2102
#define GATEWAY_SERVER_CA_CERT_PEM_SIZE 4096
/* Reserved. Add after this. */

int8_t set_gateway_cfg_status(uint16_t* cfg_status);
int8_t get_gateway_cfg_status(uint16_t* cfg_status);
int8_t set_gateway_id(const char* gateway_id, uint32_t size);
int8_t get_gateway_id(char* gateway_id, uint32_t size);
int8_t get_gateway_net_type(char* gateway_net_type, uint32_t size);
int8_t set_gateway_net_type(const char* gateway_net_type, uint32_t size);
int8_t update_prim_serv(const char* serv_addr, uint32_t size);
int8_t update_prim_alt_serv(const char* serv_addr, uint32_t size);
int8_t get_prim_serv(char* serv_addr, uint32_t size);
int8_t get_prim_alt_serv(char* serv_addr, uint32_t size);
int8_t update_sec_serv(const char* serv_addr, uint32_t size);
int8_t update_sec_alt_serv(const char* serv_addr, uint32_t size);
int8_t get_sec_serv(char* serv_addr, uint32_t size);
int8_t get_sec_alt_serv(char* serv_addr, uint32_t size);
int8_t update_dev_freq(uint32_t* dev_freq);
int8_t get_dev_freq(uint32_t* dev_freq);
int8_t update_serv_stat_freq(uint32_t* serv_freq);
int8_t get_serv_stat_freq(uint32_t* serv_freq);
int8_t update_dhcp_en(bool dhcp_en);
int8_t get_dhcp_en(uint8_t* dhcp_en);
int8_t update_ca_cert(const char* ca_cert, uint32_t size);
int8_t get_ca_cert(char* ca_cert, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif
