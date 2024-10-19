import curses
from time import sleep
stdscr = curses.initscr()


curses.noecho()
curses.cbreak()
stdscr.keypad(True)


def main(stdscr):
    # Clear screen
    stdscr.clear()

    # This raises ZeroDivisionError when i == 10.
    for i in range(0, 20):
        v = i-100
        stdscr.addstr(i, 0, '10 added to {} is {}'.format(v, 10+v), curses.A_STANDOUT)
        stdscr.refresh()
        sleep(1)

    stdscr.getkey()

curses.wrapper(main)

