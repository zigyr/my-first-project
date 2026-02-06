from PIL import Image

image = Image.open('python\脚本\像素错位\demo1.png').convert('RGB')

w,h = image.size

c = [h]*w

for x in range(w):
    for y in range(h):
        r,g,b = image.getpixel((x,y))
        if r>180 and g<80 and b<80:
            c[x]=y
            break

base = min(c)
offset = [cx - base for cx in c]

new_image = Image.new('RGB',(w,h),"white")

for x  in range(w):
    for y in range(h):
        py = (y - offset[x] + h) % h
        new_image.putpixel((x,py),image.getpixel((x,y)))
new_image.save('python\脚本\像素错位\demo1_new.png')
