from langchain_core.vectorstores import VectorStore
from langchain_core.documents import Document
from typing import List, Any, Optional
from collections import defaultdict

class MovieKNN(VectorStore):
    def __init__(self):
        # 存储形式：[(动作次数, 浪漫次数, 标签), ...]
        self.movies = []
    
    @classmethod
    def from_texts(
            cls, 
            texts: List[str],
            metadatas: Optional[List[dict]] = None,
            **kwargs: Any
    ) -> "MovieKNN":
        """
        VectorStore 强制要求的抽象方法：从文本创建向量库示例
        """
        # 创建示例
        instance = cls()
        # 调用 add_texts 存入数据
        instance.add_texts(texts, metadatas, **kwargs)
        return instance

    def add_texts(
            self,
            texts: List[str],
            metadatas: List[dict] = None,
            **kwargs: Any
    ) -> List[str]:
        # 把训练数据加入 KNN 库
        for txt, meta in zip(texts, metadatas):
            action = meta["action"]
            romance = meta["romance"]
            self.movies.append((action, romance, txt))
        return []
    
    def similarity_search(
            self,
            query: str,
            k: int = 3,
            **kwargs: Any
    ) -> List[Document]:
        # 输入格式示例："80, 15" -> 动作次数, 浪漫次数
        action_q, romance_q = map(float, query.split(","))

        # 计算欧氏距离
        def dict(a, r):
            return (a - action_q) ** 2 + (r - romance_q) ** 2
        
        # 1. 按距离从小到大排序
        sorted_movies = sorted(self.movies, key = lambda x: dict(x[0], x[1]))

        # 2. 取前 K 个近邻
        top_k = sorted_movies[:k]

        # 3. 经典KNN：投票统计
        count = defaultdict(int)
        for a, r, label in top_k:
            count[label] += 1
        
        # 4. 选出票最多的标签
        best_label = max(count, key = count.get)

        # 5. 包装成 LangChain 要求的 Document 格式返回
        return [Document(page_content = best_label)]
    
# -------------------------------测试运行--------------------------

if __name__ == '__main__':
    # # 方式一
    # # 初始化电影 KNN
    # db = MovieKNN()
    # # 训练集
    # db.add_texts(
    #     texts = [
    #         "动作片",
    #         "动作片",
    #         "动作片",
    #         "爱情片",
    #         "爱情片",
    #     ],
    #     metadatas = [
    #         {"action": 90, "romance": 5},
    #         {"action": 85, "romance": 10},
    #         {"action": 88, "romance": 8},
    #         {"action": 5, "romance": 95},
    #         {"action": 10, "romance": 88},
    #     ]
    # )

    # 方式二
    db = MovieKNN.from_texts(
        texts = ["动作片", "动作片", "爱情片", "爱情片"],
        metadatas = [
            {"action": 90, "romance": 5},
            {"action": 85, "romance": 10},
            {"action": 5, "romance": 95},
            {"action": 10, "romance": 88},
        ]
    )

    # 测试：动作80, 浪漫15
    result = db.similarity_search(query = "80, 15", k = 3)
    print("KNN的分类结果：", result[0].page_content)
