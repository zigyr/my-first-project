from PIL import Image

jpg = "output.jpg"

img = Image.open(f"{jpg}")

# 缩放比例
scale = 0.5

w, h = img.size

new_size = (int(w * scale), int(h * scale))

resized_img = img.resize(new_size)

resized_img.save("output1.jpg")

print("缩放完成")