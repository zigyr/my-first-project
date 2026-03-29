from langchain_ollama import OllamaEmbeddings

model = OllamaEmbeddings(model = "qwen3-embedding:4b")

print(model.embed_query("我喜欢你"))
print(model.embed_documents(["我喜欢你", "你喜欢我", "我稀饭你"]))