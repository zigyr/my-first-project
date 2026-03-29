from langchain_ollama import OllamaLLM

model = OllamaLLM(model = "qwen3:4b")

res = model.stream(input = "你是谁")

for chunk in res:
    print(chunk, end = "", flush = True)