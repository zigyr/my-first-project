import os
import logging
import sys

def setup_logging():
    logging.basicConfig(
        level = logging.INFO,
        format = '%(asctime)s - %(levelname)s - %(message)s',
        handlers = [
            logging.FileHandler('rename_function.log', encoding = 'utf-8', mode = 'a'),
            logging.StreamHandler(sys.stdout)
        ]
    )

def rename_files(folder_path):
    filenames = os.listdir(folder_path)
    cou = 0
    for index, filename in enumerate(filenames, 1):
        format = f'{index}.png'
        try:
            old_path = os.path.join(folder_path, filename)
            new_path = os.path.join(folder_path, format)
            os.rename(old_path, new_path)
            if not os.path.exists(old_path):
                cou += 1
                logging.info(f"成功执行得到{new_path}")
        except Exception as e:
            logging.error(f"文件{old_path}处理失败| 错误：{str(e)}")
    logging.info(f"成功批量重命名{cou}个{folder_path}路径下的文件")

def main():
    setup_logging()
    folder_path = input("请输入待执行文件夹路径：")
    rename_files(folder_path)

if __name__ == "__main__":
    main()