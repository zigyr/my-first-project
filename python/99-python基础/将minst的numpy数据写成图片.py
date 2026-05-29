import struct
import numpy as np
from PIL import Image

with open(r"F:\code_practice\code\python\22-AI\新机器学习\data\t10k-images.idx3-ubyte", "rb") as f:

    # 跳过16字节文件头
    f.read(16)

    for i in range(1, 5):

        img = np.frombuffer(
            f.read(28 * 28),
            dtype=np.uint8
        ).reshape(28, 28)

        Image.fromarray(img).save(f"./img/{i}.png")

