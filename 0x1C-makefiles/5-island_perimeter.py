#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(matrix):
    """Return the perimiter of an island.

    The matrix represents water by 0 and land by 1.

    Args:
        matrix (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in matrix.
    """
    row = len(matrix[0])
    column = len(matrix)
    sharp_end = 0
    size = 0

    for i in range(column):
        for j in range(row):
            if matrix[i][j] == 1:
                size += 1
                if (j > 0 and matrix[i][j - 1] == 1):
                    sharp_end += 1
                if (i > 0 and matrix[i - 1][j] == 1):
                    sharp_end += 1
    return size * 4 - sharp_end * 2
