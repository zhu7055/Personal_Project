import matplotlib.pyplot as plt
import re

# 步驟 1: 導入字體管理器
import matplotlib.font_manager as fm

logfile = open('firewall.log', 'r')
protocols = {}
protocol_pattern = r"\b(tcp|udp|icmp|gre|esp)\b"

for line in logfile:
    line = line.strip().lower()
    match = re.search(protocol_pattern, line)
    if match:
        protocol = match.group(1)
        if protocol in protocols:
            protocols[protocol] += 1
        else:
            protocols[protocol] = 1
    else:
        print(f"警告：以下行未找到可識別的協定：{line}")

logfile.close()

labels = list(protocols.keys())
sizes = list(protocols.values())

if labels:
    # 步驟 2: 尋找可用的中文字體 (您可以根據您的系統調整)
    plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 常見的 Windows 中文字體
    plt.rcParams['axes.unicode_minus'] = False  # 解決負號顯示為方塊的問題

    plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
    plt.title('防火牆協定使用情況')
    plt.axis('equal')
    plt.savefig('firewall_protocols.png')
    plt.show()
else:
    print("日誌檔案中沒有找到相關的協定資訊。")