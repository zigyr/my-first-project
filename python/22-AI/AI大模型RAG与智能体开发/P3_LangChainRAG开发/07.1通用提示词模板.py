from langchain_core.prompts import PromptTemplate
from langchain_community.llms.tongyi import Tongyi

prompt_template = PromptTemplate.from_template(
    "网上看到一个很好看的英文名字叫{name}, 请根据这个名字的含义中所蕴含的力量, 再给我点类似的英文名字"
)

model = Tongyi(model = "qwen-max")



# # 调用.format方法注入信息即可
# prompt_text = prompt_template.format(name = "Twilight Mystery")

# res = model.stream(input = prompt_text)

# for chunk in res:
#     print(chunk, end = "", flush = True)

# LangChain框架的链式调用(Runnable接口)
chain = prompt_template | model

res = chain.invoke(input = {"name" : "Twilight Mystery"})

print(res)





"""
"Twilight Mystery"这个名字确实很有魅力，它结合了“暮色”（twilight）带来的神秘、梦幻感和“谜”（mystery）所代表的未知与探索。基于这个灵感来源，这里为你推荐几个具有相似感觉或含义的名字：

1. **Eternal Enigma** - 永恒之谜。这个名字强调了一种永远无法完全解开的秘密感。
2. **Lunar Whisper** - 月光低语。将月亮的柔和与秘密交流的感觉结合起来。
3. **Shadow Veil** - 阴影面纱。给人一种隐藏在阴影背后、等待被揭开的神秘印象。
4. **Mystic Aurora** - 神秘极光。极光本身就是自然界中一种非常神奇而美丽的现象，加上“神秘”的前
缀更添几分不可思议。
5. **Glimmering Secret** - 微光秘密。暗示着即使是在最微弱的光芒下也存在着值得探索的秘密。
6. **Celestial Riddle** - 天体谜题。将天空中的星星等元素与解不开的难题联系起来。
7. **Whispering Stars** - 星辰细语。想象夜空中星星之间似乎在进行着只有它们才能理解的对话。
8. **Enchanted Twilight** - 迷人的黄昏。直接从你的原名出发，但加入了“迷人”这一形容词来增加吸
引力。

这些名字都试图捕捉到与“Twilight Mystery”类似的感觉——既美丽又充满未解之谜。希望这些建议能够激
发你更多的灵感！
"""