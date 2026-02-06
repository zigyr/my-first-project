from PIL import Image

image = Image.open('python\脚本\像素错位\demo2.png').convert('RGB')

w, h = image.size

new_image = Image.new('RGB', (w,h), "white")

c = [h]*w

for x in range(w):
    for y in range(h):
        r,g,b =image.getpixel((x,y))
        # if r > 240 and g < 20 and b < 20:
        if r > 180 and g < 80 and b < 80:
            c[x] = y
            break

# for i in c:
#     print(i)
# exit(0)

base = min(c)
offset = [cx -base for cx in c]

for x in range(w):
    q=offset[x]
    for y in range (h):
        py=(y - q +h) % h
        new_image.putpixel((x,py),image.getpixel((x,y)))

new_image.save('python\脚本\像素错位\demo2_new.png')