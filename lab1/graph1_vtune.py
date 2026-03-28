import numpy as np
import matplotlib.pyplot as plt

# 设置 matplotlib 参数
plt.rcParams['font.sans-serif'] = ['SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False
plt.rcParams['figure.figsize'] = (12, 8)
plt.rcParams['figure.dpi'] = 100

# 定义指标名称（简化显示）
metrics = ['执行时间(s)', 'CPU时间(s)', '微架构利用率(%)', 
           '内存瓶颈(%)', '主存瓶颈(%)', '末级缓存未命中(M)']

# 平凡算法数据
ordinary_values = [3.745, 0.347, 27.1, 41.1, 26.9, 3.85]

# Cache优化算法数据
cache_values = [3.068, 0.275, 35.1, 24.6, 13.2, 0]

# 创建图形
fig, ax = plt.subplots(figsize=(12, 7))

x = np.arange(len(metrics))
width = 0.35

# 绘制条形图
bars1 = ax.bar(x - width/2, ordinary_values, width, label='平凡算法', 
               color='#F4A261', edgecolor='black', linewidth=1.2)
bars2 = ax.bar(x + width/2, cache_values, width, label='Cache优化算法', 
               color="#46828A", edgecolor='black', linewidth=1.2)

# 添加数值标签
for bar, val in zip(bars1, ordinary_values):
    ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + max(ordinary_values)*0.02,
            f'{val:.2f}', ha='center', va='bottom', fontsize=9, fontweight='bold')

for bar, val in zip(bars2, cache_values):
    ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + max(ordinary_values)*0.02,
            f'{val:.2f}', ha='center', va='bottom', fontsize=9, fontweight='bold')

# 设置标题和标签
ax.set_xlabel('性能指标', fontsize=13, fontweight='bold')
ax.set_ylabel('数值', fontsize=13, fontweight='bold')
ax.set_xticks(x)
ax.set_xticklabels(metrics, fontsize=11)
ax.legend(fontsize=11, loc='upper right')
ax.grid(True, alpha=0.3, axis='y', linestyle='--')


# 调整布局
plt.tight_layout()
plt.savefig('lab1/graph1_vtune.png', dpi=300, bbox_inches='tight', facecolor='white')
plt.show()