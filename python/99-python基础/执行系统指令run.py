import subprocess

res = subprocess.run(
    "dir",
    stdout = subprocess.PIPE,
    stderr = subprocess.PIPE,
    text = True,
    shell = True
)

print("输出：", res.stdout)
print("错误：", res.stderr)
print("返回码：", res.returncode)  # 0=成功，非0=失败