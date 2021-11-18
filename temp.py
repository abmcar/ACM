def init():
    oriString = input()[2:]
    oriList = list(oriString.split('5a'))      # 按开始结束符分割
    oriList = list(x for x in oriList if x) # 列表去空


# print(oriList)
# print(len(oriList))
l1 = [item[:-3].strip() for item in oriList]    # 保存数据
l2 = [int(item[-3:], 16) for item in oriList]   # 保存校验长度
# print(l1)
# print(l2)
l3 = [0]*len(oriList)                   # 记录该位置的数据和长度是否合法，合法为1，不合法为0
for i, oriString in enumerate(l1):
    num = oriString.count('5b ba') + oriString.count('5b bb')    # 记录转义次数
    # print('num', num)
    if (len(l1[i])+1) // 3 == l2[i] + num:              # 需要满足的合法条件
        l3[i] = 1                                      # 合法为1
    if oriString.count('5b') > oriString.count('5b ba') + oriString.count('5b bb'):
        l3[i] = 0                                       # 不能存在单独的'5b'
    # print(l3)
res = '5a'                                            # 开始符
for i in range(len(oriList)):
    if l3[i]:
        res += oriList[i] + '5a'                      # 加入合法数据以及长度域 以及间隔符
print(res)