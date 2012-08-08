# coding=utf-8
"""Pretty prints."""
import sys


def format_num(num):
    """Format a number according to given places.
    Adds commas, etc."""

    try:
        #return "{0: .8f}".format(float(num))
        return str(num)

    except (ValueError, TypeError):
        return "{0:<}".format(num)


def get_max_width(table, index):
    """Get the maximum width of the given column index"""
    return max([len(format_num(row[index])) for row in table])


def print_table(table, out=sys.stdout, realtable=False):
    """Prints out a table of data, padded for alignment
    @param out: Output stream (file-like object)
    @param table: The table to print. A list of lists.
    Each row must have the same number of columns. """
    col_paddings = []

    if not table:
        return

    for i in range(len(table[0])):
        col_paddings.append(get_max_width(table, i))

    print >> out, '┌─' + '─┬─'.join(map(lambda c: '─' * int(c), col_paddings)) + '─┐'
    print >> out, '│ ' + ' │ '.join(map(lambda (k, c): format_num(c).rjust(col_paddings[k]), enumerate(table[0]))) + ' │'
    for row in table[1:]:
        if realtable:
            print >> out, '├─' + '─┼─'.join(map(lambda c: '─' * int(c), col_paddings)) + '─┤'
        print >> out, '│ ' + ' │ '.join(map(lambda (k, c): format_num(c).rjust(col_paddings[k]), enumerate(row))) + ' │'
    print >> out, '└─' + '─┴─'.join(map(lambda c: '─' * int(c), col_paddings)) + '─┘'

