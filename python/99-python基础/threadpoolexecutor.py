from concurrent.futures import ThreadPoolExecutor, as_completed
import time
import random

start = time.time()
def task(index, x):

    time.sleep(random.randint(1, 5))

    return index, x * 2
    

futures = []

pool = ThreadPoolExecutor(max_workers=3)

for index, num in enumerate([1, 2, 3, 4, 5]):

    future = pool.submit(
        task,
        index,
        num
    )

    futures.append(future)

results = {}

for future in as_completed(futures):

    index, data = future.result()

    results[index] = data
    
    print(index)
    
print("================================")


for index in sorted(results):

    print(results[index])


end = time.time()

print(end - start)