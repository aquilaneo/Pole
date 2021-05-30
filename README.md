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
C++版と以前から興味のあったNim言語で実装した版のインタプリタがあります。<br>
Mac用の実行ファイルはそれぞれ「Pole_cpp」「Pole_nim」で、ソースファイルは「Pole.cpp」「Pole.nim」です。<br>
Nim版はほぼ正常系しか組んでいないのでガバガバです。<br>
実行ファイルが存在するディレクトリに移動し、以下のコマンドでPoleを実行できます。<br>
```
./Pole_cpp [実行するソースコードのパス]
```
<br>

## サンプルコードの実行
「hello.pole」はHello Worldと表示するサンプルコードです。
```
./Pole_cpp hello.pole
```
で実行できます。
