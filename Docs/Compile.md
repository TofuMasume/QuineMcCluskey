# Compile

## 概要

主加法標準形にするにあたって、
AB^D+ABCD+...
↓
AB^(C:Any)D+ABCD+...
みたいなことを事前にしておきたい。

## 設計

### 文脈自由文法

G = ((S, A), (\<chars>, +), (S→\<chars>, A→\<chars>+|A\<chars>+), S)
