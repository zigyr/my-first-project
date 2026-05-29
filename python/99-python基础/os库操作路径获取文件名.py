import os
resource = "E:\code-memory\英语生词\00Inbox-待处理\代办1：hello.md"
resource_tmp = os.path.basename(resource)
resource_without_ext = os.path.splitext(resource_tmp)[0]
resource = resource_without_ext.replace('：',':').split(':')[-1].strip()
print(resource_tmp)
print(resource_without_ext)
print(resource)