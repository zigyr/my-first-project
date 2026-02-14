data = """

[{"e":"load balancers","c":"负载均衡器","t":"C"},{"e":"a failover","c":"故障转移","t":"A"},{"e":"periodic checks","c":"定期检查","t":"A"},{"e":"an enterprise scale","c":"企业级规模","t":"A"},{"e":"respond appropriately","c":"适当响应","t":"A"},{"e":"clusters of multiple servers","c":"多服务器集群","t":"A"},{"e":"resilience","c":"弹性","t":"A"},{"e":"Web Application Firewall","c":"Web应用防火墙","t":"C"},{"e":"back slash","c":"反斜杠","t":"B"},{"e":"be mapped to","c":"映射到","t":"A"},{"e":"underscore","c":"下划线","t":"A"},{"e":"come to a crawl","c":"变得缓慢","t":"A"},{"e":"take for example a blog","c":"以博客为例","t":"A"},{"e":"the latest entries","c":"最新条目","t":"A"},{"e":"scripting languages","c":"脚本语言","t":"A"},{"e":"and so much more","c":"等等","t":"A"},{"e":"Yay/Nay","c":"赞成/反对","t":"A"},{"e":"virtual hosts","c":"虚拟主机","t":"B"}]
"""

import json

lines = json.loads(data.strip())

for line in lines:
    e, c, r = line["e"], line["c"], line["t"]
    print(f"{e}\t{c}\t{r}")