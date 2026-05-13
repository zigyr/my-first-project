from tqdm import tqdm
import os
from PIL import Image

def compress_image(input_folder, out_folder):
    img_ext = (".jpeg", ".png", ".jpg")

    if not os.path.exists(out_folder):
        os.makedirs(out_folder)

    all_files = [f for f in os.listdir(input_folder) if f.lower().endswith(img_ext)]

    new_size = 0
    old_size = 0
    cou = 0

    for filename in tqdm(
        all_files,
        desc = "[+] 正在压缩图片",
        unit = "张",
        colour = "green",
        bar_format = "{desc} | {bar:30} | {percentage:3.0f}% | {n_fmt}/{total_fmt} [{elapsed}<{remaining}, {rate_fmt}]"
    ):

        try:
            new_path = os.path.join(out_folder, filename)
            old_path = os.path.join(input_folder, filename)

            old_size += os.path.getsize(old_path)

            with Image.open(old_path) as image:
                image.thumbnail((1000, 1000))

                if image.format == "PNG":
                    image.save(new_path, optimize=True)
                else:
                    image.save(new_path, quality=70, optimize=True)

            cou += 1

            new_size += os.path.getsize(new_path)

        except Exception as e:
            print(f"\n[-] 失败: {filename}, 原因: {str(e)}")

    dis_size = old_size - new_size

    if dis_size < 1024:
        size_str = f"{dis_size :.2f} B"
    elif dis_size < 1024 * 1024:
        size_str = f"{dis_size / 1024 : .2f} KB"
    else:
        size_str = f"{dis_size / (1024 * 1024) : .2f} MB"

    print(f"\n[+] 全部压缩完成, 共节省{size_str} 存储空间 \n点击 \"{out_folder}\" 可查看")





# 你的路径
input_folder = r"F:\code_practice\code\python\爬虫_up\test_img"

out_folder = r"F:\code_practice\code\python\脚本练习\图片批量压缩_img"

compress_image(input_folder, out_folder)