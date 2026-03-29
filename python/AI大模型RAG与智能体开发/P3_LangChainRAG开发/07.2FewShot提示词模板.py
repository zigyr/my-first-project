from langchain_core.prompts import FewShotPromptTemplate, PromptTemplate
from langchain_community.llms.tongyi import Tongyi


# 示例的模板
example_template = PromptTemplate.from_template("单词：{word}， 反义词：{antonym}")
# 示例的动态数据注入 要求是list内部套字典
examples_data = [
    {"word" : "happy", "antonym" : "sad"},
    {"word" : "hot", "antonym" : "cold"}
]
# FewShotPromptTemplate的类对象
few_shot_template = FewShotPromptTemplate(
    example_prompt = example_template,  # 示例数据模板
    examples = examples_data,           # 示例的数据（用来注入动态数据的）, list内套字典
    prefix = "告诉我单词的反义词，我提供如下示例：",        # 示例之前的提示词
    suffix = "请告诉我单词{input_word}的反义词是什么？",   # 示例之后的提示词
    input_variables = ["input_word"]    # 声明在前缀或后缀中所需注入的变量名 
)
# 动态注入
prompt_text = few_shot_template.invoke(input = {"input_word" : "fast"}).to_string()
# print(prompt_text)

model = Tongyi(model = "qwen-max")

print(model.invoke(input = prompt_text))