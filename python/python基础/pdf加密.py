from pypdf import PdfReader, PdfWriter

# 1. 读取原始PDF（就是你图中的pdf1.pdf）
input_pdf_path = r"F:\code_practice\code\python\AI大模型RAG与智能体开发\P3_LangChainRAG开发\data\pdf1.pdf"
# 2. 加密后输出的新PDF路径
output_pdf_path = r"F:\code_practice\code\python\AI大模型RAG与智能体开发\P3_LangChainRAG开发\data\pdf1_encrypted.pdf"

# 3. 读取原始PDF
reader = PdfReader(input_pdf_path)
writer = PdfWriter()

# 4. 把所有页面复制到写入writer（内存）中
for page in reader.pages:
    writer.add_page(page)

# 5. 设置密码（你代码里用的是"zigyr"，这里保持一致）
# 第一个参数是"用户密码"（打开文件需要输入），第二个是"所有者密码"（权限控制）
# 加密writer（内存）
writer.encrypt(user_password="123", owner_password="123")

# 6. 保存加密后的PDF
with open(output_pdf_path, "wb") as output_file:
    # 将加密后的writer（内存）写入路径，存入（硬盘）
    writer.write(output_file)

print("PDF加密完成！密码：123")