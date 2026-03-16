import sys
import tkinter as tk
from tkinter import filedialog
import ctypes

def file_read_by_tk():
    try:
        # 请用高DPI支持, 解决窗口模糊问题
        ctypes.windll.shcore.SetProcessDpiAwareness(1)
    except:
        # 如果在非Windows系统上运行, 忽略此处错误
        pass
    root = tk.Tk()
    root.withdraw()
    filepath = filedialog.askopenfilename(
        title = "请选择要读取的文件",
        filetypes = [("文本文件", "*.txt"), ("所有文件", "*.*")]
    )
    if filepath:
        try:
            with open(filepath, 'r', encoding = 'utf-8') as f:
                content = f.read()
        except FileNotFoundError:
            print("文件不存在")
        except Exception as e:
            print("出错", e)
        print(content)

def file_read_by_sys(filepath):
    """
    file_read_by_sys 的 Docstring
    
    :param filepath: 
    python ./python/脚本/文件读取器.py c:\\Users\\zige\\Desktop\\test.py
    输入python + 输入该脚本路径 + 拖拽目标文件至此脚本(vscode)
    """
    try:
        with open(filepath, 'r', encoding = 'utf-8') as f:
            content = f.read()
    except FileNotFoundError:
        print("文件不存在")
    except Exception as e:
        print("出错", e)
    print(content)

def main ():
    if len(sys.argv) > 1:
        filepath = sys.argv[1]
    # file_read_by_sys(filepath)
    file_read_by_tk()

if __name__ == "__main__":
    main()