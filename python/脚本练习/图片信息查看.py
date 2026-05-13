from PIL import Image
import os

def get_image_info(img_path):
    """
    获取图片的分辨率、文件大小信息
    """
    # 1. 获取文件大小（字节）
    file_size_bytes = os.path.getsize(img_path)
    # 转成 KB / MB，方便看
    if file_size_bytes < 1024:
        size_str = f"{file_size_bytes} B"
    elif file_size_bytes < 1024 * 1024:
        size_str = f"{file_size_bytes / 1024:.2f} KB"
    else:
        size_str = f"{file_size_bytes / (1024 * 1024):.2f} MB"

    # 2. 获取分辨率
    with Image.open(img_path) as img:
        width, height = img.size  # 宽、高
        format = img.format        # 格式（PNG/JPG等）
        mode = img.mode            # 颜色模式（RGB/RGBA等）

    return {
        "path": img_path,
        "file_size": file_size_bytes,
        "file_size_str": size_str,
        "resolution": f"{width}x{height}",
        "width": width,
        "height": height,
        "format": format,
        "mode": mode
    }

# 测试一下
if __name__ == "__main__":
    # img_path = r"F:\code_practice\code\python\爬虫_up\test_img\1.png"  # 换成你的图片路径
    img_path = r"F:\code_practice\code\python\脚本练习\图片批量压缩_img\1.png"
    info = get_image_info(img_path)
    print(f"文件路径：{info['path']}")
    print(f"文件大小：{info['file_size_str']}")
    print(f"分辨率：{info['resolution']}")
    print(f"格式：{info['format']}")
    print(f"颜色模式：{info['mode']}")