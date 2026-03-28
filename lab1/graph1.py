import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate

# 设置 matplotlib 参数
plt.rcParams['font.sans-serif'] = ['SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False
plt.rcParams['figure.figsize'] = (12, 10)
plt.rcParams['figure.dpi'] = 100

# 矩阵规模
sizes = np.array([10, 100, 1000, 5000, 10000])

# 平凡算法数据 (单位：秒)
ordinary = {
    '-O0': np.array([0.0027987, 0.011957, 0.454597, 26.5699, 190.385]),
    '-O1': np.array([0.0016169, 0.0065169, 0.347602, 18.1085, 116.723]),
    '-O2': np.array([0.0010562, 0.0048294, 0.212762, 14.8579, 75.3924])
}

# Cache优化算法数据 (单位：秒)
cache = {
    '-O0': np.array([0.00084, 0.0116232, 0.22993, 4.51504, 17.4124]),
    '-O1': np.array([0.001426, 0.0069713, 0.104104, 1.75282, 6.55993]),
    '-O2': np.array([0.0013929, 0.0085558, 0.103263, 1.71709, 6.43022])
}

# 优化级别列表
opts = ['-O0', '-O1', '-O2']

all_data = []
for opt in opts:
    all_data.extend(ordinary[opt])
    all_data.extend(cache[opt])
y_max = max(all_data) * 1.1  
y_min = 0

# 创建 1×3 子图
fig, axes = plt.subplots(1, 3, figsize=(15, 5))

# 颜色定义
colors = {'ordinary': '#D55E00', 'cache': '#0072B2'} 
markers = {'ordinary': 'o', 'cache': 's'}

# ==================== 绘制三张图 ====================
for idx, opt in enumerate(opts):
    ax = axes[idx]
    
    # 生成平滑曲线的 x 值
    sizes_smooth = np.linspace(10, 10000, 200)

    # 对数据进行样条插值
    tck_ordinary = interpolate.splrep(sizes, ordinary[opt], s=0)
    ordinary_smooth = interpolate.splev(sizes_smooth, tck_ordinary)

    tck_cache = interpolate.splrep(sizes, cache[opt], s=0)
    cache_smooth = interpolate.splev(sizes_smooth, tck_cache)

    # 绘制平滑曲线
    ax.plot(sizes_smooth, ordinary_smooth, color=colors['ordinary'], linewidth=2, label='平凡算法')
    ax.plot(sizes_smooth, cache_smooth, color=colors['cache'], linewidth=2, label='cache算法')

    # 绘制原始数据点
    ax.scatter(sizes, ordinary[opt], color=colors['ordinary'], s=50, zorder=5)
    ax.scatter(sizes, cache[opt], color=colors['cache'], s=50, zorder=5)
        
    # 设置标题和标签
    ax.set_title(f'{opt} 优化级别', fontsize=14, fontweight='bold')
    ax.set_xlabel('矩阵规模 n', fontsize=12)
    ax.set_ylabel('执行时间 (s)', fontsize=12)
    ax.legend(loc='upper left', fontsize=10)
    ax.grid(True, alpha=0.3, linestyle='--')

    # 统一 y 轴范围
    ax.set_ylim(y_min, y_max)
    
    # 设置 x 轴范围
    ax.set_xlim(0, 10500)
    ax.set_xticks([10, 100, 1000, 5000, 10000])
    ax.set_xticklabels(['10', '100', '1000', '5000', '10000'])   
    

# 添加总标题
fig.suptitle('不同优化级别下平凡算法与cache算法的性能对比', fontsize=16, fontweight='bold')
plt.tight_layout()
plt.savefig('lab1/graph1_Ocomp.png', dpi=300, bbox_inches='tight')
plt.show()