"""
通过
`tshark -r usb.pcapng -T fields -e usbhid.data -Y "usb.transfer_type == 0x01 && usbhid.data" | sed '/^\s*$/d' > hid_data.txt`
提取到usb中的流量信息到hid_data.txt

随后通过脚本进行还原
"""

import matplotlib.pyplot as plt

# 读取提取的hid数据，还原鼠标坐标
data = []
with open(r"F:\code_practice\code\python\ctf\NSSCTF\[LitCTF 2025]消失的文字\hid_data.txt", "r") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        # 鼠标HID报告格式：1字节按键 + 2字节X位移 + 2字节Y位移
        # 有些数据包可能不完整、长度不够，比如只有 2 个字符
        btn = int(line[0:2], 16)
        dx = int(line[2:4], 16) if len(line)>=4 else 0
        dy = int(line[4:6], 16) if len(line)>=6 else 0
        # 处理有符号位移（超过127的是负数）
        if dx > 127:
            dx -= 256
        if dy > 127:
            dy -= 256
        data.append((dx, dy))

# 计算轨迹坐标
x, y = 0, 0
trajectory = [(x, y)]
for dx, dy in data:
    x += dx
    y += dy
    trajectory.append((x, y))

# 绘图部分
xs = [p[0] for p in trajectory]
ys = [p[1] for p in trajectory]


plt.gca().invert_yaxis()  # 反转Y轴
plt.plot(xs, ys, color='black', linewidth=2)
# plt.axis('equal')  # 保持横纵比例一致，防止文字变形
# plt.title("Mouse Trajectory")
# plt.savefig("mouse_trajectory.png", dpi=300, bbox_inches='tight')
plt.show()