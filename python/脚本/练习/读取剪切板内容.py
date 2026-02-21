from PIL import ImageGrab, Image
import pyperclip
import os
import time

data = ImageGrab.grabclipboard()

if isinstance(data, Image.Image):
    data.save(str(int(time.time())) + ".png")
elif isinstance(data, list):
    for line in data:
        ext = os.path.splitext(line)[1].lower()
        if ext in ['.jpg', '.jpeg', '.png', '.bmp', '.gif']:
            data = Image.open(line)
            data.save(str(int(time.time())) + ".png")
        if ext in ['.txt', '.py', '.md', '.csv', '.json']:
            with open(line, "r", encoding='utf-8') as f:
                file_content = f.read()
            with open("pyperclip.txt", "a", encoding='utf-8') as f:
                f.write(file_content + "\n")
else:
    file_content = pyperclip.paste()
    with open ("pyperclip.txt", "a", encoding='utf-8') as f:
        f.write(file_content + "\n")