# Pole
## Poleとは？
ノリで作ったBrainf*ck系？のネタプログラミング言語です。  
「I」「l」「1」の3文字からなる6命令を使い、それ以外の文字はコメントとして扱われます。  

| 命令 | 内容 |
----|---- 
| II | ポインタを1加算 |
| Il | ポインタを1減算 |
| I1 | ポインタが指す値を1加算 |
| lI | ポインタが指す値を1減算 |
| ll | ポインタが指す値を出力 |
| l1 | ポインタが指す領域に値を入力 |

「Hello World」と表示するソースコード例↓
```
I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1I1I1llI1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1llI1I1I1I1I1I1I1llllI1I1I1llIII1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1llI1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1I1I1I1I1I1I1I1llI1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1I1
I1I1I1I1I1I1llI1I1I1lllIlIlIlIlIlIlllIlIlIlIlIlIlIlIll
```
<br>

## 使い方
Pole.exeがインタプリタの実行ファイル、Pole.nimがインタプリタのソースファイルです。  
インタプリタは以前から興味のあったNim言語で実装しています。  
ほぼ正常系しか組んでないのでガバガバです。  
Pole.exeが存在するディレクトリに移動し、以下のコマンドでPoleを実行できます。
```
./Pole [実行するソースコードのパス]
```
<br>

## サンプルコードの実行
「hello.pole」がHello Worldと表示するサンプルコードです。
```
./Pole hello.pole
```
で実行できます。
