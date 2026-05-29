import os
import time
import random

def rename_files(folder_path):
    filenames = os.listdir(folder_path)
    cou = 0
    # 顺序重命名
    for index, filename in enumerate(filenames, 1):
        format = f'{index}.png'
    # # 宇宙级不重复时间戳命名
    # for filename in filenames:
    #     time_str = time.strftime("%Y%m%d_%H%M%S")
    # #   time_str = datetime.now().strftime("%Y%m%d_%H%M%S") # datetime
    #     rand_str = str(random.randint(1000, 9999))
    #     format = f"{time_str}_{rand_str}.png"  
        try:
            old_path = os.path.join(folder_path, filename)
            new_path = os.path.join(folder_path, format)

            os.rename(old_path, new_path)
            
            if not os.path.exists(old_path):
                cou += 1
                print(f"成功执行得到{new_path}")
        except Exception as e:
            print(f"文件{old_path}处理失败| 错误：{str(e)}")
    print("=" * 100)
    print(f"成功批量重命名{cou}个{folder_path}路径下的文件")


folder_path = "F:\\code_practice\\code\python\\爬虫_up\\test_img"
rename_files(folder_path)

