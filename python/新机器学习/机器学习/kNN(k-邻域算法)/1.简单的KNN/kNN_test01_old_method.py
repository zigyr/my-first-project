import numpy as np
import operator


def createDataset():

    # `np.array(列表)` 
    # 把普通列表 → 变成 NumPy 数组（才能批量计算）
    x_train = np.array([[1,101],[5,89],[108,5],[115,8]])
    y_train = ['爱情片','爱情片','动作片','动作片']

    return x_train, y_train


def classify0(x_test, x_train, y_train, k):
    # `numpy_list.shape[0]`
    # 获取numpy_list的一维维度
    num_samples = x_train.shape[0]

    # `np.tile(数据, (行数, 列数))`
    # 复制数组，让待测点和训练集的行列一致
    diff_mat = np.tile(x_test, (num_samples, 1)) - x_train # 差值矩阵

    sq_diff_mat = diff_mat ** 2 # 平方差值矩阵
    # `numpy_list.sum(axis=1)`
    # 按行相加
    sq_distances = sq_diff_mat.sum(axis = 1)

    distances = sq_distances ** 0.5
    # `numpy_list.argsort()`
    # 返回从小到大排序后的索引编号
    sorted_indices = distances.argsort()
    label_count = {}
    for i in range(k):
        lable = y_train[sorted_indices[i]]
        # `dict.get(key, 0)`
        # 安全取值，没有就返回 0，不报错
        label_count[lable] = label_count.get(lable, 0) + 1
    # `dict.items()`
    # 把字典变成 [(键，值), (键，值) ] 的列表，让 sorted 能排序
    # `key = operator.itemgetter(1)`
    # 对list里每一个元素tuple，都取它的 "值" 来排序
    # `reverse = True`降序
    # `reverse = False`升序
    sortedClassify = sorted(label_count.items(), key = operator.itemgetter(1), reverse = True)
    return sortedClassify[0][0]

if __name__ == '__main__':
    x_train, y_train = createDataset()
    x_test = [101, 20]
    y_test = classify0(x_test, x_train, y_train, 3)
    print(y_test)