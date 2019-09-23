#include "spark_wiring_usr_config.h"
#include "logging.h"
LOG_SOURCE_CATEGORY("wiring.usr_fs")

int8_t set_gateway_cfg_status(uint16_t* cfg_status)
{
    if (usr_write_app_data(cfg_status, GATEWAY_CFG_STATUS_OFFSET, 2) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_gateway_cfg_status(uint16_t* cfg_status)
{
    if (usr_read_app_data(GATEWAY_CFG_STATUS_OFFSET, cfg_status, 2) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_prim_serv(const char* serv_addr, uint32_t size)
{
    if (size > GATEWAY_PRIMARY_SERV_ADDR_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }

    char l_serv_addr[GATEWAY_PRIMARY_SERV_ADDR_SIZE];
    memset(l_serv_addr, 0, GATEWAY_PRIMARY_SERV_ADDR_SIZE);
    memcpy(l_serv_addr, serv_addr, size);
    if (usr_write_app_data(l_serv_addr, GATEWAY_PRIMARY_SERV_ADDR_OFFSET,
                           GATEWAY_PRIMARY_SERV_ADDR_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_prim_alt_serv(const char* serv_addr, uint32_t size)
{
    if (size > GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_serv_addr[GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE];
    memset(l_serv_addr, 0, GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE);
    memcpy(l_serv_addr, serv_addr, size);
    if (usr_write_app_data(l_serv_addr, GATEWAY_PRIMARY_SERV_ADDR_ALT_OFFSET,
                           GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_sec_alt_serv(const char* serv_addr, uint32_t size)
{
    if (size > GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_serv_addr[GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE];
    memset(l_serv_addr, 0, GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE);
    memcpy(l_serv_addr, serv_addr, size);
    if (usr_write_app_data(l_serv_addr, GATEWAY_SECONDARY_SERV_ADDR_ALT_OFFSET,
                           GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_sec_serv(const char* serv_addr, uint32_t size)
{
    if (size > GATEWAY_SECONDARY_SERV_ADDR_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_serv_addr[GATEWAY_SECONDARY_SERV_ADDR_SIZE];
    memset(l_serv_addr, 0, GATEWAY_SECONDARY_SERV_ADDR_SIZE);
    memcpy(l_serv_addr, serv_addr, size);
    if (usr_write_app_data(l_serv_addr, GATEWAY_SECONDARY_SERV_ADDR_OFFSET,
                           GATEWAY_SECONDARY_SERV_ADDR_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_dev_freq(uint32_t* dev_freq)
{
    if (usr_write_app_data((char* ) dev_freq, GATEWAY_DEV_UPDATE_FREQUENCY_OFFSET, sizeof(uint32_t)) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_serv_stat_freq(uint32_t* serv_freq)
{
    if (usr_write_app_data((char* ) serv_freq, GATEWAY_STATUS_FREQUENCY_OFFSET, sizeof(uint32_t)) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_dhcp_en(bool dhcp_en)
{
    uint8_t l_de = dhcp_en;
    if (usr_write_app_data(&l_de, GATEWAY_DHCP_ENABLE_OFFSET, sizeof(uint8_t)) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t update_ca_cert(const char* ca_cert, uint32_t size)
{
    if (size > GATEWAY_SERVER_CA_CERT_PEM_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_ca[GATEWAY_SERVER_CA_CERT_PEM_SIZE];
    memset(l_ca, 0, GATEWAY_SERVER_CA_CERT_PEM_SIZE);
    memcpy(l_ca, ca_cert, size);
    if (usr_write_app_data(l_ca, GATEWAY_SERVER_CA_CERT_PEM_OFFSET,
                           GATEWAY_SERVER_CA_CERT_PEM_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t set_gateway_id(const char* gateway_id, uint32_t size)
{
    if (size > GATEWAY_ID_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_gt_id[GATEWAY_ID_SIZE];
    memset(l_gt_id, 0, GATEWAY_ID_SIZE);
    memcpy(l_gt_id, gateway_id, size);
    if (usr_write_app_data(l_gt_id, GATEWAY_ID_OFFSET, GATEWAY_ID_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_gateway_id(char* gateway_id, uint32_t size)
{
    if (size < GATEWAY_ID_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_ID_OFFSET, gateway_id, GATEWAY_ID_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_gateway_net_type(char* gateway_net_type, uint32_t size)
{
    if (size < GATEWAY_NET_TYPE_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_NET_TYPE_OFFSET, gateway_net_type, GATEWAY_NET_TYPE_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t set_gateway_net_type(const char* gateway_net_type, uint32_t size)
{
    if (size > GATEWAY_NET_TYPE_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    char l_gtwy[GATEWAY_NET_TYPE_SIZE];
    memset(l_gtwy, 0, GATEWAY_NET_TYPE_SIZE);
    memcpy(l_gtwy, gateway_net_type, size);
    if (usr_write_app_data(l_gtwy, GATEWAY_NET_TYPE_OFFSET, GATEWAY_NET_TYPE_SIZE) != 0)
    {
        LOG(ERROR, "%s USR write failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_prim_serv(char* serv_addr, uint32_t size)
{
    if (size < GATEWAY_PRIMARY_SERV_ADDR_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_PRIMARY_SERV_ADDR_OFFSET, serv_addr,
                          GATEWAY_PRIMARY_SERV_ADDR_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_prim_alt_serv(char* serv_addr, uint32_t size)
{
    if (size < GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_PRIMARY_SERV_ADDR_ALT_OFFSET, serv_addr,
                          GATEWAY_PRIMARY_SERV_ADDR_ALT_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_sec_serv(char* serv_addr, uint32_t size)
{
    if (size < GATEWAY_SECONDARY_SERV_ADDR_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_SECONDARY_SERV_ADDR_OFFSET, serv_addr,
                          GATEWAY_SECONDARY_SERV_ADDR_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_sec_alt_serv(char* serv_addr, uint32_t size)
{
    if (size < GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_SECONDARY_SERV_ADDR_ALT_OFFSET, serv_addr,
                          GATEWAY_SECONDARY_SERV_ADDR_ALT_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_dev_freq(uint32_t* dev_freq)
{
    if (usr_read_app_data(GATEWAY_DEV_UPDATE_FREQUENCY_OFFSET, (char* ) dev_freq,
                          sizeof(uint64_t)) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_serv_stat_freq(uint32_t* serv_freq)
{
    if (usr_read_app_data(GATEWAY_STATUS_FREQUENCY_OFFSET, (char* ) serv_freq,
                          sizeof(uint64_t)) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_dhcp_en(uint8_t* dhcp_en)
{
    if (usr_read_app_data(GATEWAY_DHCP_ENABLE_OFFSET, dhcp_en, sizeof(uint8_t)) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}

int8_t get_ca_cert(char* ca_cert, uint32_t size)
{
    if (size < GATEWAY_SERVER_CA_CERT_PEM_SIZE)
    {
        LOG(ERROR, "%s Invalid size", __func__);
        return -1;
    }
    if (usr_read_app_data(GATEWAY_SERVER_CA_CERT_PEM_OFFSET, ca_cert,
                          GATEWAY_SERVER_CA_CERT_PEM_SIZE) != 0)
    {
        LOG(ERROR, "%s USR read failed!", __func__);
        return -1;
    }
    return 0;
}
