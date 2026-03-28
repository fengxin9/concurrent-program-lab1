import numpy as np
import matplotlib.pyplot as plt

# 设置 matplotlib 参数
plt.rcParams['font.sans-serif'] = ['SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False
plt.rcParams['figure.figsize'] = (10, 6)
plt.rcParams['figure.dpi'] = 100

# 数据定义
sizes = np.array([128, 512, 4096, 16384, 65536])

# 三种算法的时间数据 (单位: 秒)
naive = np.array([0.0370984, 0.0387979, 0.0479869, 0.0786003, 0.206921])      # 平凡算法
fourway = np.array([0.036352, 0.0383549, 0.0468592, 0.0635532, 0.138291])     # 四路链式
recursive = np.array([0.0009211, 0.0021559, 0.0175069, 0.0578634, 0.22201])   # 递归算法

# 创建图形
fig, ax = plt.subplots(figsize=(10, 6))

# 颜色定义
colors = {
    'naive': '#D88C6A',      
    'fourway': '#6A9C89',    
    'recursive': '#8DA9B5'   
}
markers = {'naive': 'o', 'fourway': 's', 'recursive': '^'}

# 绘制三条曲线
ax.plot(sizes, naive, marker=markers['naive'], color=colors['naive'],
        linewidth=2, markersize=8, label='平凡算法')
ax.plot(sizes, fourway, marker=markers['fourway'], color=colors['fourway'],
        linewidth=2, markersize=8, label='四路链式')
ax.plot(sizes, recursive, marker=markers['recursive'], color=colors['recursive'],
        linewidth=2, markersize=8, label='递归算法')

# 设置标题和标签
ax.set_xlabel('数组规模 n', fontsize=12)
ax.set_ylabel('执行时间 (s)', fontsize=12)

# 设置坐标轴
ax.set_xscale('log')
ax.set_yscale('linear')
ax.set_xlim(100, 70000)
ax.set_xticks([128, 512, 4096, 16384, 65536])
ax.set_xticklabels(['128', '512', '4096', '16384', '65536'])
ax.grid(True, alpha=0.3, linestyle='--')

# 添加图例
ax.legend(loc='upper left', fontsize=11)

plt.tight_layout()
plt.savefig('graph2_comp.png', dpi=300, bbox_inches='tight', facecolor='white')
plt.show()

