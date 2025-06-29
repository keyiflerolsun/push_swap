## 🔄 Algoritma Akışı

### Kısa Özet
```
- if is_sorted
  - return

- if size == 2
  - swap_a

- if size == 3
  - sort_three
    - swap_a, rotate_a, reverse_a

- while (size > 3)
  - move_min_to_top
  - push_b

- sort_three

- while (stack->b)
  - push_a          (because stack b is sorted)
```