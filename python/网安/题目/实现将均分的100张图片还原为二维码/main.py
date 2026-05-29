from PIL import Image
import os
import re

def natural_sort_key(s):
    """用于自然排序的辅助函数，确保图片按数字顺序排列"""
    return [int(text) if text.isdigit() else text.lower()
            for text in re.split('([0-9]+)', s)]

def stitch_images(input_folder, output_path):
    """将指定文件夹中的图片按10×10网格拼接"""
    # 获取所有图片文件并按名称排序
    image_files = sorted([f for f in os.listdir(input_folder) 
                         if f.lower().endswith(('.png', '.jpg', '.jpeg'))],
                        key=natural_sort_key)
    
    if len(image_files) != 100:
        raise ValueError(f"文件夹中应有100张图片，但实际有{len(image_files)}张")
    
    # 打开第一张图片以获取尺寸
    first_img = Image.open(os.path.join(input_folder, image_files[0]))
    width, height = first_img.size
    
    # 创建一个空白的大图
    result = Image.new('RGB', (width * 10, height * 10))
    
    # 逐个粘贴小图片到大图上
    for i, img_file in enumerate(image_files):
        row = i // 10
        col = i % 10
        img_path = os.path.join(input_folder, img_file)
        img = Image.open(img_path)
        result.paste(img, (col * width, row * height))
    
    # 保存结果
    result.save(output_path)
    print(f"图片已成功拼接并保存到: {output_path}")

if __name__ == "__main__":
    # 设置输入文件夹和输出路径
    input_folder = r"./python/ctf/实现将均分的100张图片还原为二维码/tiles"  # 包含100张小图片的文件夹
    output_path = r"./python/ctf/实现将均分的100张图片还原为二维码/combined_qrcode.png"  # 拼接后的图片保存路径
    
    # 执行拼接
    stitch_images(input_folder, output_path)    