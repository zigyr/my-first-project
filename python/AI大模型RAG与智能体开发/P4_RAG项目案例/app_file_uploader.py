# """
# 基于Streamlit完成WEB网页上传服务
# pip install streamlit
# """
# """
# 运行：
#     在cmd窗口cd到该目录下
#     执行`streamlit run app_file_uploader.py`即可
# """
# """
# Streamlit：当Web页面元素发生变化时，则代码重新执行一遍
# """

import streamlit as st
from knowledge_base import KnowledgeBaseService
import time


# 添加网页标题
st.title("知识库更新服务")

# file_uploader
uploader_file = st.file_uploader(
    label = "请上传TXT文件",
    type = ['txt'],
    accept_multiple_files = False    # False表示仅接受一个文件的上传
)

# session_state 就是一个字典
if "service" not in st.session_state:
    st.session_state["service"] = KnowledgeBaseService()

if uploader_file is not None:
    # 提取文件的信息
    file_name = uploader_file.name
    file_type = uploader_file.type
    file_size = uploader_file.size / 1024

    st.subheader(f"文件名：{file_name}")
    st.write(f"格式：{file_type}    |    大小：{file_size:.2f} KB")

    # getvalue -> bytest --decode('utf-8')--> str
    text = uploader_file.getvalue().decode('utf-8')
    
    # 在spinner内的代码执行过程中, 会有一个转圈动画
    with st.spinner("载入知识库中。。。"):
        time.sleep(1)

        res = st.session_state["service"].upload_by_str(text, file_name)
        st.write(res)