"""
🟦 PNG 图片（无损格式）
特点：画质永远 100%，不会损失清晰度
不能降低质量！你给它设置 quality=50 也完全没用
只能通过 optimize=True 做无损压缩（删冗余数据，不改变画质）

🟥 JPG / JPEG 图片（有损格式）
特点：可以自由调节画质，画质越低体积越小
必须用 quality=数字 控制压缩程度
optimize=True 额外再优化一点点体积
"""

"""
os.path.exists
os.makedirs

os.lstdir

os.path.join

os.path.getsize
"""

import os
from PIL import Image


def compress_image(input_folder, out_folder):

    old_tot = 0
    new_tot = 0
    cou = 0

    # 支持的图片格式
    image_ext = (".jpg", ".jpeg", ".png")

    # 如果输出文件夹不存在，自动创建
    if not os.path.exists(out_folder):
        os.makedirs(out_folder)

    all_files = [f for f in os.listdir(input_folder) if f.lower().endswith(image_ext)]

    # 遍历图片
    for filename in all_files:
    
        try:
            img_path = os.path.join(input_folder, filename)
            out_path = os.path.join(out_folder, filename)

            old_file_size_bytes = os.path.getsize(img_path)
            old_tot += old_file_size_bytes
            

            with Image.open(img_path) as img:
                # 等比例缩小分辨率
                img.thumbnail((1000, 1000))

                # 格式判断
                if img.format == "PNG":
                    img.save(out_path, optimize=True)
                else:
                    img.save(out_path, quality=70, optimize=True)

            new_file_size_bytes = os.path.getsize(out_path)
            new_tot += new_file_size_bytes

            cou += 1

            print(f"[+] 压缩完成: {filename}")

        except Exception as e:
            print(f"[-] 处理失败: {filename}, 原因: {str(e)}")

    dis_size = old_tot - new_tot
    if dis_size < 1024:
        size_str = f"{dis_size} B"
    elif dis_size < 1024 * 1024:
        size_str = f"{dis_size / 1024 :.2f} KB"
    else:
        size_str = f"{dis_size / (1024 * 1024) :.2f} MB"
    print(f"[+] 本次图片批量压缩结束\n共压缩{cou}张图片\n共节省空间{size_str}")


# 你的路径
input_folder = r"F:\code_practice\code\python\爬虫_up\test_img"
out_folder = r"F:\code_practice\code\python\脚本练习\图片批量压缩_img"

# 开始压缩
compress_image(input_folder, out_folder)