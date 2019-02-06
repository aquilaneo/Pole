import os
import strutils

# ---------- 初期設定 ----------
# データ領域のサイズ
const size = 256

# データ領域の確保
var data: array[size, uint8]
# ポインタ
var p = 0

# コマンドの定義
type Expr = object
    keyword : string
    behavior : proc()
const exprs = [
    Expr(keyword: "II", behavior: proc() = 
        # ポインタ加算
        if p < size - 1:
            p += 1
        else:
            p = 0
    ), 
    Expr(keyword: "Il", behavior: proc() = 
        # ポインタ減算
        if p > 0:
            p -= 1
        else:
            p = size - 1
    ), 
    Expr(keyword: "I1", behavior: proc() = 
        # 値加算
        data[p] += 1
    ), 
    Expr(keyword: "lI", behavior: proc() = 
        # 値減算
        data[p] -= 1
    ), 
    Expr(keyword: "ll", behavior: proc() = 
        # 値表示
        stdout.write(data[p].char)
    ), 
    Expr(keyword: "l1", behavior: proc() = 
        # 値入力
        let str = readLine(stdin)
        if str.len > 0:
            data[p] = str[0].uint8
        else:
            data[p] = 0
    )
]


# ---------- ファイル読み込み ----------
# コマンドライン引数をチェック
if os.paramCount() == 0:
    echo("[Error] Set the source file path to execute in the first argument.")
    quit()

let filePath = os.commandLineParams()[0]
var rawSource = ""
var file: File
try:
    # ファイルからソースコード読み込み
    file = open(filePath, FileMode.fmRead)
    rawSource = file.readAll
except:
    echo("[Error] Failed to open the source file!  \"" & filePath & "\"")
    quit()
finally:
    close(file)
    

# ---------- 構文解析 ----------
var source = ""
# ソースファイルからIl1だけ取り出す
const chars: array[3, char] = ['I', 'l', '1']
for rawChar in rawSource:
    for ch in chars:
        if rawChar == ch:
            source &= rawChar
            break
# 命令を読み解く
var commands : seq[string]
for i in countup(0, source.len - 1, 2):
    let command = source[i] & source[i + 1]
    commands.add(command)

# ---------- 実行する命令登録 ----------
var behaviors: seq[proc()]
for command in commands:
    for expr in exprs:
        if command == expr.keyword:
            behaviors.add(expr.behavior)
            break

# ---------- 実行 ----------
for behavior in behaviors:
    behavior()
echo("")
