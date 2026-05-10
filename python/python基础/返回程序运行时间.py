import time

start = time.perf_counter()

# 你的代码
time.sleep(2)  # 模拟耗时操作

end = time.perf_counter()

print(f"运行时间：{end - start:.3f} 秒")