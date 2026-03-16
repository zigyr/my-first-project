target_cmd = "phpinfo()"

def is_invalid(char):
    return char.isalnum()

res1 = ""
res2 = ""

for char in target_cmd:
    target_ascii = ord(char)
    found = False

    for x in range(33, 127):
        if is_invalid(chr(x)):
            continue

        for y in range(33, 127):
            if is_invalid(chr(y)):
                continue

            if (x ^ y) == target_ascii:
                res1 += chr(x)
                res2 += chr(y)
                found = True
                break
        if found:
            break

print("===生成成果===")
print(f"Result1 (异或第一部分): {res1}")
print(f"Result2 (异或第二部分): {res2}")
print("\n===验证还原===")
recovered = ""
for a, b in zip(res1, res2):
    recovered += chr(ord(a) ^ ord(b))
print(f"异或还原后的命令: {recovered}")