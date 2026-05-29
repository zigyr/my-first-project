import os
from PIL import Image

def fix_image_extension(folder_path):
    for filename in os.listdir(folder_path):
        file_path = os.path.join(folder_path, filename)
        if not os.path.isfile(file_path):
            continue

        # 跳过非图片文件
        try:
            with Image.open(file_path) as img:
                real_format = img.format.lower()
        except:
            continue

        # 常见格式映射
        format_ext_map = {
            "jpeg": ".jpg",
            "png": ".png",
            "gif": ".gif",
            "webp": ".webp"
        }
        new_ext = format_ext_map.get(real_format, f".{real_format}")
        old_ext = os.path.splitext(filename)[1].lower()

        if old_ext != new_ext:
            new_filename = os.path.splitext(filename)[0] + new_ext
            new_path = os.path.join(folder_path, new_filename)
            os.rename(file_path, new_path)
            print(f"✅ 已重命名：{filename} -> {new_filename}")

# 改成你的图片文件夹路径
fix_image_extension(r"F:\code_practice\code\python\爬虫_up\test_img")