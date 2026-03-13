# Linked List

## 実装したこと

- `LinkedListNode` 構造体（データ + nextポインタ）
- `LinkedList` 構造体（head / tail / size を管理）
- `node_init` : ノードの初期化（malloc）
- `list_init` : リストの初期化
- `list_free` : 全ノードのメモリ解放
- `list_append` : 末尾への追加（O(1)）
- `list_insert_at_index` : index指定で挿入（O(n)）
- `list_insert_at_node` : ノード指定で直後に挿入（O(1)）
- `list_print` : 全要素の表示

## 学んだこと

- `tail` ポインタを持つことで append を O(1) にできる
- insert は「ノード参照が既知」なら O(1)、index指定なら O(n)
- remove は単方向リストだとノード指定でも prevを探す必要があり O(n)。O(1) にするには双方向リストが必要

## 今後やること（時間があれば）

- `list_remove_at_index` : index指定で削除
- 双方向LinkedList（`prev` ポインタを追加）の実装
