import requests
import json
import re
import csv
import os  # 新增：用于文件/文件夹操作

def extract_bilibili_playlist(url, export_formats=None):
    # 默认导出所有格式，也可以指定如 ['csv', 'sql', 'md']
    if export_formats is None:
        export_formats = ['txt', 'csv', 'json', 'sql', 'yml']

    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Safari/537.36',
        'Referer': 'https://www.bilibili.com/'
    }

    print(f"正在请求: {url}")
    try:
        res = requests.get(url, headers=headers, timeout=10)
        res.raise_for_status()
        res.encoding = 'utf-8'
        html = res.text
    except Exception as e:
        print(f"请求失败: {e}")
        return

    # 解析B站数据
    pattern = re.compile(r'window.__INITIAL_STATE__\s*=\s*(\{.*?\});', re.S)
    match = pattern.search(html)
    if not match:
        print("❌ 未找到视频数据，页面结构可能变化")
        return

    try:
        json_data = json.loads(match.group(1))
        # 视频主标题（处理非法字符）
        video_title = json_data.get('videoData', {}).get('title', 'B站视频目录')
        safe_title = re.sub(r'[\\/*?:"<>|]', '', video_title)
        
        # 🔴 新增：创建以视频标题命名的文件夹
        output_dir = safe_title
        os.makedirs(output_dir, exist_ok=True)  # exist_ok=True 避免文件夹已存在时报错

        # 分P数据
        pages = json_data.get('videoData', {}).get('pages', [])
        if not pages:
            print("❌ 未找到分P数据，可能是单P视频")
            return

        print(f"✅ 视频总标题：{video_title}")
        print(f"✅ 找到 {len(pages)} 个分P")
        print(f"✅ 输出文件夹已创建：{output_dir}")

        # 统一整理成结构化数据
        playlist_data = []
        for i, page in enumerate(pages, 1):
            part_title = page.get('part', f"P{i}")
            duration_sec = page.get('duration', 0)
            minutes = duration_sec // 60
            seconds = duration_sec % 60
            dur_str = f"{minutes:02d}:{seconds:02d}"
            playlist_data.append({
                "index": i,
                "title": part_title,
                "duration_str": dur_str,
                "duration_sec": duration_sec
            })

        # 1. TXT格式（和之前一样）
        if 'txt' in export_formats:
            file_path = os.path.join(output_dir, f"{safe_title}.txt")
            with open(file_path, 'w', encoding='utf-8') as f:
                for item in playlist_data:
                    line = f"P{item['index']:02d} {item['title']} 【{item['duration_str']}】\n"
                    f.write(line)
            print(f"✅ 已保存为 TXT: {file_path}")

        # 2. CSV格式（直接双击就能用Excel打开，也能直接导入MySQL）
        if 'csv' in export_formats:
            file_path = os.path.join(output_dir, f"{safe_title}.csv")
            with open(file_path, 'w', encoding='utf-8-sig', newline='') as f:
                writer = csv.DictWriter(f, fieldnames=["index", "title", "duration_str", "duration_sec"])
                writer.writeheader()
                for item in playlist_data:
                    writer.writerow(item)
            print(f"✅ 已保存为 CSV: {file_path}")

        # 3. JSON格式（通用结构化格式，很多工具都支持）
        if 'json' in export_formats:
            file_path = os.path.join(output_dir, f"{safe_title}.json")
            output = {
                "video_title": video_title,
                "playlist": playlist_data
            }
            with open(file_path, 'w', encoding='utf-8') as f:
                json.dump(output, f, ensure_ascii=False, indent=2)
            print(f"✅ 已保存为 JSON: {file_path}")

        # 4. SQL格式（直接生成建表+插入语句，复制就能在MySQL里执行）
        if 'sql' in export_formats:
            file_path = os.path.join(output_dir, f"{safe_title}.sql")
            table_name = re.sub(r'[^\w]', '_', safe_title.lower())
            sql_lines = []
            sql_lines.append(f"-- 自动生成的B站视频目录SQL")
            sql_lines.append(f"CREATE TABLE IF NOT EXISTS `{table_name}` (")
            sql_lines.append("  `id` INT PRIMARY KEY AUTO_INCREMENT,")
            sql_lines.append("  `part_index` INT NOT NULL COMMENT '分P序号',")
            sql_lines.append("  `title` VARCHAR(500) NOT NULL COMMENT '视频标题',")
            sql_lines.append("  `duration_str` VARCHAR(10) COMMENT '时长(MM:SS)',")
            sql_lines.append("  `duration_sec` INT COMMENT '时长(秒)'")
            sql_lines.append(") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;")
            sql_lines.append("")
            for item in playlist_data:
                title_escaped = item['title'].replace("'", "''")
                sql = f"INSERT INTO `{table_name}` (part_index, title, duration_str, duration_sec) VALUES " \
                      f"({item['index']}, '{title_escaped}', '{item['duration_str']}', {item['duration_sec']});"
                sql_lines.append(sql)
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write("\n".join(sql_lines))
            print(f"✅ 已保存为 SQL: {file_path}")

        # 5. YML格式（你提到的yml，适合配置文件用）
        if 'yml' in export_formats:
            file_path = os.path.join(output_dir, f"{safe_title}.yml")
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(f"video_title: {video_title}\n")
                f.write("playlist:\n")
                for item in playlist_data:
                    f.write(f"  - index: {item['index']}\n")
                    f.write(f"    title: {item['title']}\n")
                    f.write(f"    duration: {item['duration_str']}\n")
            print(f"✅ 已保存为 YML: {file_path}")

        print(f"\n🎉 全部导出完成！共 {len(playlist_data)} 条分P数据，文件已全部存入文件夹：{output_dir}")

    except json.JSONDecodeError as e:
        print(f"❌ JSON解析失败: {e}")

if __name__ == "__main__":
    url = input("请输入B站视频链接: ")
    # 你可以在这里指定要导出的格式，比如只导出csv和sql
    # extract_bilibili_playlist(url, export_formats=['csv', 'sql'])
    extract_bilibili_playlist(url)