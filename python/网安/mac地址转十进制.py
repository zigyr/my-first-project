def mac_to_decimal(mac_address):
    """
    将 MAC 地址转换为十进制整数
    :param mac_address: 标准 MAC 字符串，如 00:1A:2B:3C:4D:5E
    :return: 十进制整数
    """
    # 去掉 MAC 地址中的分隔符 : -
    clean_mac = mac_address.replace(':', '').replace('-', '')
    
    # 将16进制字符串转为十进制整数
    decimal_num = int(clean_mac, 16)
    
    return decimal_num


# ==================== 测试示例 ====================
if __name__ == '__main__':
    # 你可以替换成任意 MAC
    mac_list = [
        "00:1A:2B:3C:4D:5E",
        "AA-BB-CC-DD-EE-FF",
        "000000000000",
        "FFFFFFFFFFFF"
    ]

    for mac in mac_list:
        dec = mac_to_decimal(mac)
        print(f"MAC地址: {mac}")
        print(f"十进制:   {dec}\n")