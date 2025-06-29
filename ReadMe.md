## 🔄 Algoritma Akışı

### Kısa Özet
```
- if is_sorted
  - return

- if size == 2
  - swap_a

- if size == 3
  - sort_three
    - swap_a, rotate_a, reverse_a   (you should choice)

- while (size > 3)
  - move_min_to_top
    - find_min_pos
    - if min_pos == 0      (-,-)        : return
    - if min_pos <= size/2 (upper half) : rotate_a, min_pos--
    - else                 (lower half) : reverse_a, (size - min_pos)--
  - push_b

- sort_three

- while (stack->b)
  - push_a          (because stack b is sorted)
```