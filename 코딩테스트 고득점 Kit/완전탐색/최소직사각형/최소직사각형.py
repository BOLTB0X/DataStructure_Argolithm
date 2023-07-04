def solution(sizes):
    row, col = -1, -1

    for size in sizes:
        row = max(row, max(size[0], size[1]))
        col = max(col, min(size[0], size[1]))
    return row*col
