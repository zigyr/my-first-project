import numpy as np

def get_dot(vec_a, vec_b):
    # 计算两个向量的点积
    a = np.array(vec_a)
    b = np.array(vec_b)
    return np.dot(a, b)  

def get_norm(vec):
    # 计算单个向量的模长
    v = np.array(vec)
    return np.sqrt(np.sum(v ** 2))

def cosine_similarity(vec_a, vec_b):
    return get_dot(vec_a, vec_b) / (get_norm(vec_a) * get_norm(vec_b))
    

if __name__ == '__main__':
    vec_a = [0.5, 0.5]
    vec_b = [0.7, 0.7]
    vec_c = [0.7, 0.5]
    vec_d = [-0.6, -0.5]
    
    print("ab:", cosine_similarity(vec_a, vec_b))
    print("ac:", cosine_similarity(vec_a, vec_c))
    print("ad:", cosine_similarity(vec_a, vec_d))